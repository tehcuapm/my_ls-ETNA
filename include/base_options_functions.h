/*
** ETNA PROJECT, 07/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      header file for base options
*/

#ifndef BASE_OPT
#define BASE_OPT
#include "structs/llist.h"

OptionsHead initAllOption(void);

void activeOption(List *list, OptionsHead *optList);

int isActive(OptionsHead *list, char opt);

void freeOptions(OptionsHead *list);

void my_putlistOpt(OptionsHead *list);

#endif