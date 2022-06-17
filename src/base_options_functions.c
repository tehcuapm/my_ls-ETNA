/*
** ETNA PROJECT, 07/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      all functions for all existing options
*/

#include "../include/pools_functions.h"
#include "../include/structs/llist.h"
#include "../include/base_options_functions.h"
#include <stdlib.h>

OptionsHead initAllOption(void)
{
    char optionNames[] = "lRrdtaAfL";
    int i = 0;
    OptionsHead *list = malloc(sizeof(*list));
    Options *tail = malloc(sizeof(*tail));

    if (list == NULL || tail == NULL)
    {
        exit(EXIT_FAILURE);
    }
    tail->name = 0;
    tail->isActive = 0;
    tail->next = NULL;
    list->head = tail;

    while (optionNames[i] != '\0')
    {
        Options *element = malloc(sizeof(*element));
        if (element == NULL)
        {
            exit(EXIT_FAILURE);
        }

        element->name = optionNames[i];
        element->isActive = 0;
        element->next = list->head;
        list->head = element;

        i += 1;
    }

    return *list;
}

void activeOption(List *list, OptionsHead *optList)
{
    Element *temp1 = malloc(sizeof(temp1));
    Options *temp2 = malloc(sizeof(temp2));

    if (temp1 == NULL || temp2 == NULL)
    {
        exit(EXIT_FAILURE);
    }
    temp1 = list->head;
    while (temp1->next != NULL)
    {
        temp2 = optList->head;
        int is_exist = 0; // Bool
        while (temp2->next != NULL)
        {
            if (temp1->option == temp2->name)
            {
                temp2->isActive = 1;
                is_exist = 1;
            }

            temp2 = temp2->next;
        }
        if (!is_exist)
        {
            my_putstr("my_ls : option invalide -- '");
            my_putchr(temp1->option);
            my_putchr('\'');
            my_putchr('\n');
            exit(EXIT_FAILURE);
        }
        temp1 = temp1->next;
    }
    free(temp1);
}

void my_putlistOpt(OptionsHead *list)
{
    Options *temp = list->head;
    while (temp != NULL)
    {
        my_putchr(temp->name);
        temp = temp->next;
    }
    free(temp);
}

int isActive(OptionsHead *list, char opt)
{

    Options *temp = list->head;
    while (temp != NULL)
    {
        if (temp->isActive == 1 && temp->name == opt)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void freeOptions(OptionsHead *list)
{
    // int i = 0;
    Options *temp = list->head;
    Options *temp2 = temp;
    while (temp != NULL)
    {
        temp2 = temp;
        temp = temp->next;
        // i += 1;
        free(temp2);
    }
    free(temp);
}