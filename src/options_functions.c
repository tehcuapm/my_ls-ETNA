/*
** ETNA PROJECT, 07/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      all functions for given option
*/

#include "../include/structs/llist.h"
#include "../include/pools_functions.h"
#include <stdlib.h>

List initOption(void)
{
    List *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->option = '0';
    element->next = NULL;
    list->head = element;

    return *list;
}

void insertOption(List *list, char option)
{
    Element *newOption = malloc(sizeof(*newOption));

    if (newOption == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newOption->option = option;
    newOption->next = list->head;
    list->head = newOption;
}

void my_putllist(List *list)
{

    Element *temp = list->head;
    while (temp != NULL)
    {
        my_putchr(temp->option);
        temp = temp->next;
    }
}
