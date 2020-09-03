/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd
*/

#include "include/my.h"
#include "include/mysh.h"

int found_home(char **env)
{
    int nbr;

    for (int i = 0; env[i] != NULL; i++) {
        nbr = my_strncmp(env[i], "HOME=", 5);
        if (nbr == 0)
            return (i);
    }
    return (-1);
}

char *remove_equal(char **env)
{
    int lin = found_home(env);
    char *save = my_strmult(env[lin]);

    for (int i = 0; save[i] != '\0'; i++) {
        if (save[i] != '/')
            save[i] = ' ';
        if (save[i] == '/')
            break;
    }
    return (save);
}

char *get_home(char **env)
{
    char *line = remove_equal(env);
    for (int i = 0; line[i] != '\0'; i++)
        while (line[i] == ' ')
            move_str(line);
    return (line);
}

int check_pwd(char **env)
{
    int nbr = 0;

    for (int i = 0; env[i] != NULL; i++) {
        nbr = my_strncmp(env[i], "PWD=", 4);
        if (nbr == 0) {
            return (i);
        }
    }
    return (-1);
}

char *modif_pwd(char **env)
{
    int nbr = check_pwd(env);
    char *line = get_home(env);
    char *str = "PWD=";
    char *str2 = malloc(sizeof(char) * my_strlen(str) + 2);
    char *my_pwd;
    char *new_pwd;

    str2 = my_strcpy(str2, str);
    my_pwd = my_strcpy(env[nbr], str2);
    new_pwd = my_strcat(my_pwd, line);
    return (new_pwd);
}