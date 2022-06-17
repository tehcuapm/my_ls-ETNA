/*
** ETNA PROJECT, 10/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      header file for all functions for directories
*/

#ifndef DIRECTORIES
#define DIRECTORIES

#include "../include/structs/llist.h"

ListDir initDir(void);

void addDir(ListDir *list, char *dir);

void my_putLlistDir(ListDir *list);

void my_putCountList(ListDir *list);

void freeDir(ListDir *list);

#endif