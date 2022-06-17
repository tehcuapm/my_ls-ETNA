/*
** ETNA PROJECT, 07/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      functions for -l
*/

#include "../include/structs/llist.h"
#include "../include/pools_functions.h"
#include "../include/option_l.h"
#include "../include/sort_files.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <errno.h>

int count(char *filepath)
{
    struct stat buf;
    int i = 0;
    if (stat(filepath, &buf) != -1)
    {
        i = buf.st_blocks;
    }
    return i;
}

int total_count(char *dir)
{
    DIR *directory = opendir(dir);
    struct dirent *d;
    int total = 0;

    while ((d = readdir(directory)) != NULL)
    {
        char *name = d->d_name;
        char *filepath = malloc(my_strlen(dir) + my_strlen(name) + 3);

        if (name[0] == '.')
        {
            continue;
        }
        int len_dir = my_strlen(dir);
        if (len_dir < 2)
        {

            filepath = my_strcpy(filepath, name);
        }
        else if (dir[len_dir - 1] == '/')
        {

            filepath = my_strcpy(filepath, dir);
            filepath = my_strcat(filepath, name);
        }
        else
        {
            filepath = my_strcpy(filepath, dir);
            filepath = my_strcat(filepath, "/");
        }
        total += count(filepath);
        free(filepath);
    }
    closedir(directory);
    return total / 2;
}

void permissions(char *file)
{
    struct stat st;
    char *modeval = malloc(sizeof(char) * 9 + 1);
    if (stat(file, &st) == 0)
    {
        mode_t perm = st.st_mode;
        modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
        modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
        modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
        modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
        modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
        modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
        modeval[6] = (perm & S_IROTH) ? 'r' : '-';
        modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
        modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
        modeval[9] = '\0';
        switch (st.st_mode & S_IFMT)
        {
        case S_IFREG:
            my_putchr('-');
            break;
        case S_IFDIR:
            my_putchr('d');
            break;
        }
        my_putstr(modeval);
    }
    free(modeval);
}

void lls(char *filepath)
{
    struct stat buf;
    if (stat(filepath, &buf) != -1)
    {
        char links = buf.st_nlink + '0';
        struct passwd *pw = getpwuid(buf.st_uid);
        struct group *gr = getgrgid(buf.st_gid);
        char *name = pw->pw_name;
        char *gname = gr->gr_name;

        permissions(filepath);
        my_putchr(' ');
        my_putchr(links);
        my_putstr(" ");
        my_putstr(name);
        my_putstr(" ");
        my_putstr(gname);
        my_putstr(" ");
        my_putnbr(buf.st_size);
        my_putstr(" ");
        write(1, (ctime(&buf.st_mtime) + 4),
              (my_strlen(ctime(&buf.st_mtime)) - 13));
        my_putchr(' ');
    }
}

char *filepath_maker(char *dir, char *file)
{
    char *filepath = malloc(my_strlen(dir) + my_strlen(file) + 3);

    int len_dir = my_strlen(dir);
    if (len_dir < 2)
    {

        filepath = my_strcpy(filepath, file);
    }
    else if (dir[len_dir - 1] == '/')
    {

        filepath = my_strcpy(filepath, dir);
        filepath = my_strcat(filepath, file);
    }
    else
    {
        filepath = my_strcpy(filepath, dir);
        filepath = my_strcat(filepath, "/");
    }
    return filepath;
}

void my_l_ls(char *dir)
{
    DIR *directory = opendir(dir);
    struct dirent *d;
    struct userFile *head = NULL;
    struct userFile *temp = head;

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
    int a = total_count(dir);
    my_putstr("total ");
    my_putnbr(a);
    my_putchr('\n');

    int cpt = 0;
    while ((d = readdir(directory)) != NULL)
    {

        char *name = d->d_name;
        if (name[0] == '.')
        {
            continue;
        }
        if (cpt < 1)
        {
            head = addToEmpty(name);
            cpt++;
            continue;
        }
        head = insert(head, name);
    }
    temp = head;

    while (temp != NULL)
    {
        if (temp->file[0] == '.')
        {
            continue;
        }
        char *filepath = filepath_maker(dir, temp->file);
        lls(filepath);
        my_putchr(' ');
        my_putstr(temp->file);

        my_putchr('\n');

        temp = temp->link;
    }

    closedir(directory);
}
