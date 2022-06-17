/*
** ETNA PROJECT, 07/01/2022 by garo_n
** /home/matheo/Bureau/group-944762
** File description:
**      functions for -f
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




void  my_f_ls(char *dir)
{
    DIR *directory = opendir(dir);
    struct dirent *d;
    struct userFile* head = NULL;
    struct userFile* temp = head;
    
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
   
    int cpt = 0;
    while ((d = readdir(directory)) != NULL)
    {

        char *name = d->d_name;
        
        if(cpt<1){
            head = addToEmpty(name);
            cpt++;
            continue;
        }
        head = addFile(head,name);
    
    }
  
    closedir(directory);
    temp = head;
    while (temp !=NULL)
    {
       
       
        my_putstr(temp->file);
       
        my_putchr('\n');

        temp = temp->link;
    }
    let_it_be_userFiles(&head);
}
