/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** mysh
*/

#include "include/my.h"
#include "include/mysh.h"

char *value_env(char *name, char *value, int count)
{
    char *save =  NULL;
    char *equal;

    if (count == 3)
        save = malloc(sizeof(char) * (my_strlen(name) +
        my_strlen(value) + 2));
    else
        save = malloc(sizeof(char) * (my_strlen(name)) +2);

    save = my_strcpy(save, name);
    equal = my_strcat(save, "=");
    if (count == 3)
        save = my_strcat(equal, value);
    return (save);
}

void set_env(char **env, char *name, char *value, int count)
{
    int i = 0;

    for (;env[i]; i++);
    env[i] = malloc(sizeof(char) * (my_strlen(name) + my_strlen(value) + 2));
    env[i] = value_env(name, value, count);
    env[i + 1] = NULL;
}