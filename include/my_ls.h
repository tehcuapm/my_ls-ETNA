/*
** ETNA PROJECT, 12/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      header file for my_ls
*/

#ifndef LS
#define LS
#include <dirent.h>
#include "../include/structs/llist.h"

void test_if_exist(DIR *directory);

void my_ls(char *dir, OptionsHead *allOptions);

#endif