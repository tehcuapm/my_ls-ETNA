/*
** ETNA PROJECT, 06/01/2022 by pauche_m
** /home/matheo/Bureau/group-944762
** File description:
**      all pool's functions
*/

#include "../include/pools_functions.h"
#include <unistd.h>
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
    char *temp = malloc(sizeof(str));
    temp = my_strcpy(temp,str);
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

int my_strcmp(char *s1, char *s2)
{
    int i;
    s1 = my_strlowcase(s1);
    s2 = my_strlowcase(s2);
    i = 0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        i++;
    }
    return (s1[i] - s2[i]);
}