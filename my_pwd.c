/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_pwd
*/

#include "include/my.h"
#include "include/mysh.h"

char *remove_equal3(char **env)
{
    int lin = check_pwd(env);
    char *save = my_strmult(env[lin]);

    for (int i = 0; save[i] != '\0'; i++) {
        if (save[i] != '/')
            save[i] = ' ';
        if (save[i] == '/')
            break;
    }
    return (save);
}

char *get_pwd(char **env)
{
    char *line = remove_equal3(env);
    for (int i = 0; line[i] != '\0'; i++)
        while (line[i] == ' ')
            move_str(line);
    return (line);
}