/*
** ETNA PROJECT, 03/01/2022 by pauche_m & garo_n
** main.c
** File description:
**      main file of the project
*/

#include "../include/pools_functions.h"
#include "../include/structs/llist.h"
#include "../include/base_options_functions.h"
#include "../include/options_functions.h"
#include "../include/option_l.h"
#include "../include/dir_functions.h"
#include "../include/option_t.h"
#include "../include/option_r.h"
#include "../include/option_d.h"
#include "../include/option_majA.h"
#include "../include/option_a.h"
#include "../include/my_ls.h"
#include "../include/option_majL.h"
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void listAllFiles(ListDir *listDir, OptionsHead *allOptions)
{
    int i = 0;
    Directory *dir = listDir->head;
    if (!listDir->count)
    {
        char no_dir[256] = ".";
        my_ls(no_dir, allOptions);
    }
    else
    {
        while (i < listDir->count)
        {
            my_ls(dir->dir, allOptions);
            dir = dir->next;
            i += 1;
        }
    }
}
int main(int argc, char *argv[])
{
    int i = 1;
    List listOption = initOption();
    ListDir listDir = initDir();

    while (i < argc)
    {
        switch (argv[i][0])
        {
        case '-':
            insertOption(&listOption, argv[i][1]);
            break;

        default:
            addDir(&listDir, argv[i]);
            break;
        }
        i += 1;
    }

    OptionsHead allOptions = initAllOption();
    activeOption(&listOption, &allOptions);

    listAllFiles(&listDir, &allOptions);
    freeOptions(&allOptions);
    freeDir(&listDir);
    return 0;
}
