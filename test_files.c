
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

void my_putchr(char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        my_putchr(str[i]);
        i = i + 1;
    }
}

char *my_strcpy(char *dest, const char *src)
{

    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void my_putnbr(int nb)
{

    if (nb >= 10)
    {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    else
    {
        my_putchr(48 + nb);
    }
}
struct userFile
{
    char *file;
    __time_t *date;
    struct userFile *link;
};
struct userFile *addToEmpty(char *data)
{

    struct userFile *temp = malloc(sizeof(struct userFile));
    temp->file = data;
    temp->link = NULL;
    return temp;
}

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
    {
        i += 1;
    }

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        j += 1;
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}

void my_ls(char *dir)
{
    DIR *directory = opendir(dir);
    struct dirent *d;

    struct userFile *insert_date(struct userFile * head, char *data, __time_t *date)
    {
        struct userFile *temp = head;
        struct userFile *newFile = malloc(sizeof(struct userFile));
        newFile->file = data;
        newFile->date = date;
        newFile->link = NULL;
        __time_t *key = date;
        if (head == NULL || key < head->date)
        {

            newFile->link = head;
            head = newFile;
        }
        else
        {
            while (temp->link != NULL && key > temp->link->date)
            {
                temp = temp->link;
            }
            newFile->link = temp->link;
            temp->link = newFile;
        }
        return head;
    }

    if (!directory)
    {
        char *error = "Unable to read the directory";

        if (head == NULL || i == 0)
        {

            newFile->link = head;
            head = newFile;
        }
        else
        {
            while (temp->link != NULL && i != 0)
            {
                my_putstr(error);
            }
            exit(EXIT_FAILURE);
        }
        while ((d = readdir(directory)) != NULL)
        {
            char *name = d->d_name;
            char *filepath = malloc(my_strlen(dir) + my_strlen(name) + 3);

            if (name[0] == '.')
            {
                free(filepath);
                continue;
            }
            int len_dir = my_strlen(dir);
            if (len_dir < 2)
            {

                int main()
                {
                    struct userFile *head = NULL;
                    head = addToEmpty("base_options_functions.c");
                    head = insert(head, "sort_files.c");
                    head = insert(head, "main.c");
                    head = insert(head, "main.o");

                    print_userFiles(head);
                    let_it_be_userFiles(&head);
                }
