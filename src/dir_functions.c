/*
** ETNA PROJECT, 10/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      for directory's functions
*/

#include "../include/structs/llist.h"
#include "../include/pools_functions.h"
#include <stdlib.h>

ListDir initDir(void)
{
    ListDir *list = malloc(sizeof(*list));
    Directory *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->dir = "./";
    element->next = NULL;
    list->head = element;
    list->count = 0;
    return *list;
}

void addDir(ListDir *list, char *dir)
{
    Directory *newDir = malloc(sizeof(*newDir));

    if (newDir == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newDir->dir = dir;
    newDir->next = list->head;
    list->head = newDir;
    list->count += 1;
}

void my_putLlistDir(ListDir *list)
{
    Directory *temp = list->head;
    while (temp != NULL)
    {
        my_putstr(temp->dir);
        my_putchr('\n');
        temp = temp->next;
    }
    free(temp);
}

void my_putCountList(ListDir *list)
{
    my_putnbr(list->count);
}

void freeDir(ListDir *list)
{
    Directory *temp = list->head;
    Directory *temp2 = temp;
    while (temp != NULL)
    {
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    free(temp);
    // list = NULL;
}