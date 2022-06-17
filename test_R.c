#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <stdlib.h>

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
int my_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
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

char *my_strlowcase(char *str)
{
    int i = 0;
    char *temp = str;
    while (temp[i] != '\0')
    {
        if (temp[i] > 64 && temp[i] < 91)
        {
            temp[i] += 32;
        }
        i += 1;
    }
    return (temp);
}

char *addSlash(char *dir)
{
    int len = my_strlen(dir);
    if (dir[len - 1] == '/')
    {
        return dir;
    }
    else
    {
        dir = my_strcat(dir, "/");
        return dir;
    }
}

char *my_strdecat(char *dir, char *curr_dir)
{
    int len = my_strlen(curr_dir);
    int len2 = my_strlen(dir);
    int i = len - len2;

    while (i < len)
    {
        curr_dir[i] = '\0';
        i += 1;
    }

    return curr_dir;
}

void R_ls(char *dir)
{
    DIR *directory = opendir(dir);
    struct dirent *d;

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

    // Print the name of the current dir
    my_putstr(dir);
    my_putchr(':');
    my_putchr('\n');

    // Declare variable
    char is_dir[100][256];
    int i = 0;
    int j = 0;

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

        if (d->d_type == DT_DIR)
        {
            my_strcpy(is_dir[i], d->d_name);
            i += 1;
        }

        my_putstr(name);
        my_putchr(' ');
        free(filepath);
    }

    // Do the recursive
    my_putchr('\n');
    while (j < i)
    {
        my_putchr('\n');
        my_ls(my_strcat(addSlash(dir), is_dir[j]));
        dir = my_strdecat(is_dir[j], dir);
        j += 1;
    }
    closedir(directory);
}

int main(int argc, char *argv[])
{
    my_ls(argv[argc - 1]);
    return 0;
}