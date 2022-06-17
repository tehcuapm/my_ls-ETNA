/*
** ETNA PROJECT, 14/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      all function needed for R option
*/

#include <stdlib.h>
#include <errno.h>
#include <dirent.h>

#include "../include/pools_functions.h"
#include "../include/my_ls.h"

char *addSlash(char *dir)
{
    int len = my_strlen(dir);
    if (dir[len - 1] == '/')
    {
        return dir;
    }
    else
    {
        dir = my_strcat(dir, "/");
        return dir;
    }
}

char *my_strdecat(char *dir, char *curr_dir)
{
    int len = my_strlen(curr_dir);
    int len2 = my_strlen(dir);
    int i = len - len2;

    while (i < len)
    {
        curr_dir[i - 1] = '\0';
        i += 1;
    }

    return curr_dir;
}

void R_ls(char *dir)
{
    DIR *directory = opendir(dir);
    struct dirent *d;

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

    // Print the name of the current dir
    my_putstr(dir);
    my_putchr(':');
    my_putchr('\n');

    // Declare variable
    char is_dir[100][256];
    int i = 0;
    int j = 0;

    while ((d = readdir(directory)) != NULL)
    {
        char *name = d->d_name;
        char *filepath = malloc(my_strlen(dir) + my_strlen(name) + 3);

        if (name[0] == '.')
        {
            free(filepath);
            continue;
        }
        int len_dir = my_strlen(dir);
        if (len_dir < 2)
        {
            filepath = my_strcpy(filepath, name);
        }
        else if (dir[len_dir - 1] == '/')
        {

            filepath = my_strcpy(filepath, dir);
            filepath = my_strcat(filepath, name);
        }
        else
        {
            filepath = my_strcpy(filepath, dir);
            filepath = my_strcat(filepath, "/");
        }

        if (d->d_type == DT_DIR)
        {
            my_strcpy(is_dir[i], d->d_name);
            i += 1;
        }

        my_putstr(name);
        my_putchr(' ');
        free(filepath);
    }

    // Do the recursive
    my_putchr('\n');
    while (j < i)
    {
        my_putchr('\n');
        R_ls(my_strcat(addSlash(dir), is_dir[j]));
        dir = my_strdecat(is_dir[j], dir);
        j += 1;
    }
    closedir(directory);
}