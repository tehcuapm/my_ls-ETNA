/*
** ETNA PROJECT, 12/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      file for my_ls function
*/

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include "../include/structs/llist.h"
#include "../include/pools_functions.h"
#include "../include/sort_files.h"
#include "../include/option_l.h"
#include "../include/option_a.h"
#include "../include/option_r.h"
#include "../include/option_f.h"
#include "../include/option_d.h"
#include "../include/option_t.h"
#include "../include/option_majA.h"
#include "../include/base_options_functions.h"
#include "../include/option_majR.h"
#include "../include/option_majL.h"
#include "../include/base_ls.h"

void test_if_exist(DIR *directory)
{
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
}

void my_ls(char *dir, OptionsHead *allOptions)
{
    DIR *directory = opendir(dir);
    struct dirent *d;
    struct userFile *head = NULL;

    test_if_exist(directory);

    char is_dir[100][256];
    int i = 0;
    int j = 0;

    // If -R is active, store all directories into is_dir
    if (isActive(allOptions, 'R'))
    {
        if (!isActive(allOptions, 'd'))
        {

            while ((d = readdir(directory)) != NULL)
            {
                char *name = d->d_name;
                int len = my_strlen(name);

                if (!isActive(allOptions, 'A') || !isActive(allOptions, 'a'))
                {
                    if (name[0] == '.' && len < 3)
                    {
                        continue;
                    }
                }

                if (d->d_type == DT_DIR)
                {
                    my_strcpy(is_dir[i], name);
                    i += 1;
                }
            }
            my_putstr(dir);
            my_putchr('\n');
        }
    }

    if (isActive(allOptions, 'a'))
    {
        head = my_a_ls(dir);
        print_userFiles(head);
    }
    else if (isActive(allOptions, 'A'))
    {
        head = my_majA_ls(dir);
        print_userFiles(head);
    }
    else if (isActive(allOptions, 'd'))
    {
        my_d_ls(dir);
    }
    else if (isActive(allOptions, 'f'))
    {
        my_f_ls(dir);
    }

    // Print
    if (isActive(allOptions, 't'))
    {
        if (isActive(allOptions, 'r'))
        {
            // Sort with datetime and reverse it
        }
        else
        {
            head = my_t_ls(dir);
            print_userFiles(head);
        }
    }

    if (isActive(allOptions, 'l'))
    {
        if (isActive(allOptions, 'L'))
        {
            my_bigL_ls(dir);
        }
        if (isActive(allOptions, 'r'))
        {
            // Sort Alpha and reverse it
            int a = total_count(dir);
            my_putstr("total ");
            my_putnbr(a);
            my_putchr('\n');

            head = my_r_ls(dir);
            while (head != NULL)
            {
                if (head->file[0] == '.')
                {
                    continue;
                }
                char *filepath = filepath_maker(dir, head->file);
                lls(filepath);
                my_putchr(' ');
                my_putstr(head->file);
                my_putchr('\n');

                head = head->link;
            }
        }
        else if (!isActive(allOptions, 'L'))
        {
            my_l_ls(dir);
        }
    }
    else if (isActive(allOptions, 'L'))
    {
        my_base_ls(dir);
    }

    if (isActive(allOptions, 'r') && !isActive(allOptions, 'l'))
    {
        // Sort Alpha and reverse it
        head = my_r_ls(dir);
        while (head != NULL)
        {
            if (head->file[0] == '.')
            {
                continue;
            }

            my_putstr(head->file);
            my_putchr('\n');

            head = head->link;
        }
    }
    if (!isActive(allOptions, 'A') && !isActive(allOptions, 'a') && !isActive(allOptions, 't') && !isActive(allOptions, 'd') && !isActive(allOptions, 'f') && !isActive(allOptions, 'l') && !isActive(allOptions, 'L') && !isActive(allOptions, 'r'))
    {
        my_base_ls(dir);
    }

    // If -R is active, do recursive
    if (isActive(allOptions, 'R'))
    {
        if (!isActive(allOptions, 'd'))
        {
            while (j < i)
            {
                my_putchr('\n');
                my_ls(my_strcat(addSlash(dir), is_dir[j]), allOptions);
                dir = my_strdecat(is_dir[j], dir);
                j += 1;
            }
        }
    }

    closedir(directory);
}