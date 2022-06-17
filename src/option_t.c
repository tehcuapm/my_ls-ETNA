/*
** ETNA PROJECT, 07/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      functions for -t
*/

#include "../include/structs/llist.h"
#include "../include/pools_functions.h"
#include "../include/option_l.h"
#include "../include/sort_files.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <errno.h>


struct userFile* tls(char *filepath,char *name,struct userFile* head)
{
    struct stat buf;
    
    if(head != NULL){
        if (stat(filepath, &buf) != -1)
        {
         
        head = insert_date(head,name,buf);   
        }
        
    }
    else{
        if (stat(filepath, &buf) != -1)
        { 

        head = addToEmptyTime(name,buf);
        }
    }
    
    return head;
}


struct userFile* my_t_ls(char *dir)
{
    DIR *directory = opendir(dir);
    struct dirent *d;
    struct userFile* head = NULL;
    
    if (!directory)
    {
        char *error = "Unable to read the directory";

        if (errno == ENOENT)
        {
            error = "Directory does not exist";
            my_putstr(error);
        }
        else
        {
            my_putstr(error);
        }
        exit(EXIT_FAILURE);
    }
   
    
    while ((d = readdir(directory)) != NULL)
    {
        
        char *name = d->d_name;
         if (name[0] == '.')
            {
            continue;
            }

        char *filepath = filepath_maker(dir,name);
        
           
        head = tls(filepath,name,head);
          
    }
    
    
    closedir(directory);
    return head;
}
