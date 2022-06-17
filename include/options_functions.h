/*
** ETNA PROJECT, 07/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      header file for given option
*/

#ifndef OPT
#define OPT
#include "structs/llist.h"

List initOption(void);

void insertOption(List *list, char option);

void my_putllist(List *list);

void freeListOption(List *list, OptionsHead *listOpt);

#endif