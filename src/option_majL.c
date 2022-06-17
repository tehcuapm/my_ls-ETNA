/*
** ETNA PROJECT, 07/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      functions for -l
*/

#include "../include/structs/llist.h"
#include "../include/pools_functions.h"
#include "../include/option_l.h"
#include "../include/option_majL.h"
#include "../include/sort_files.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <errno.h>



void my_bigL_ls(char *dir)
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
    int a = total_count(dir);
    my_putstr("total ");
    my_putnbr(a);
    my_putchr('\n');

    int cpt = 0;
    while ((d = readdir(directory)) != NULL)
    {

        char *name = d->d_name;
         if (name[0] == '.')
            {
            continue;
            }
        if(cpt<1){
            head = addToEmpty(name);
            cpt++;
            continue;
        }
        head = insert(head,name);
    
    }
    temp = head;

    while (temp !=NULL)
    {
        if (temp->file[0] == '.')
        {
            continue;
        }
        char *filepath = filepath_maker(dir,temp->file);
        lls(filepath);
        my_putchr(' ');
        my_putstr(temp->file);
        my_putchr('\n');

        temp = temp->link;
    }
    

    closedir(directory);
}
