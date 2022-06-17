/*
** ETNA PROJECT, 07/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      my_ls
*/

#include "../include/structs/llist.h"
#include "../include/pools_functions.h"
#include "../include/option_l.h"
#include "../include/option_d.h"
#include "../include/sort_files.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <errno.h>

void my_d_ls(char *dir)
{
    DIR *directory = opendir(dir);

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

    if (dir[0] == '.')
    {

        my_putstr(".\n");
    }
    else
    {
        my_putstr(dir);
        my_putchr('\n');
    }

    closedir(directory);
}
