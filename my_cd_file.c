/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd_file
*/

#include "include/my.h"
#include "include/mysh.h"

int found_oldpwd(char **env)
{
    int nbr;

    for (int i = 0; env[i] != NULL; i++) {
        nbr = my_strncmp(env[i], "OLDPWD=", 7);
        if (nbr == 0)
            return (i);
    }
    return (-1);
}

char *remove_equal2(char **env)
{
    int lin = found_oldpwd(env);
    char *save = my_strmult(env[lin]);

    for (int i = 0; save[i] != '\0'; i++) {
        if (save[i] != '/')
            save[i] = ' ';
        if (save[i] == '/')
            break;
    }
    return (save);
}

char *get_oldpwd(char **env)
{
    char *line = remove_equal2(env);
    for (int i = 0; line[i] != '\0'; i++)
        while (line[i] == ' ')
            move_str(line);
    return (line);
}

char *create_pwd(char **env, char *line)
{
    int nbr = check_pwd(env);
    char *my_pwd = my_strmult(env[nbr]);
    int nbr_char = my_strlen(my_pwd) + my_strlen(line);
    char *new_pwd = malloc(sizeof(char) * nbr_char + 1);
    new_pwd = my_strcat(my_pwd, line);
    return (new_pwd);
}

char *create_oldpwd(char **env, char *line)
{
    int nbr = found_oldpwd(env);
    char *str = "OLDPWD=";
    char *my_oldpwd = my_strcpy(env[nbr], str);
    char *new_oldpwd = my_strcat(my_oldpwd, line);
    return (new_oldpwd);
}