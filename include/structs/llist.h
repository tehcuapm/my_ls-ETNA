/*
** ETNA PROJECT, 06/01/2022 by pauche_m & garo_n
**
** File description:
**      all linked list
*/
#include <time.h>
#include "sys/stat.h"
#ifndef LLIST
#define LLIST
/**
 *  Two linked list for store all directories
 *  The first one store the path of directories
 *  The second one store the head of the first llist and how many element are in the llist
 */
typedef struct ElementDir Directory;
struct ElementDir
{
    char *dir;
    Directory *next;
};

typedef struct ListDir ListDir;
struct ListDir
{
    Directory *head;
    int count;
};

/**
 * Two linked list for store all options selected by the user
 * The first one store the name
 * The second llist store the head of the first one
 */
typedef struct ElementOption Element;
struct ElementOption
{
    char option;
    Element *next;
};

typedef struct ListOption List;
struct ListOption
{
    Element *head;
};

/**
 * Two linked list for store all existing options
 * The first llist store the name of each option and if the option is active
 * The second store the head of the first one
 */
typedef struct options Options;
struct options
{
    char name;
    int isActive; // Bool
    Options *next;
};

typedef struct optionsHead OptionsHead;
struct optionsHead
{
    Options *head;
};

struct userFile
{
    char *file;
    struct stat stat;
    struct userFile *link;
};
#endif