/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell2
*/

#include "include/my.h"
#include "include/mysh.h"

int my_env(char **env, char **save)
{
    if (my_strcmp(save[0], "env") ==  0 && my_strlen_env(save) > 1) {
        write(2, "env: '", 6);
        write(2, save[1], my_strlen(save[1]));
        write(2, "': No such file or directory\n", 29);
    }
    else if (my_strcmp(save[0], "env") ==  0)
        get_env(env);
    return (0);
}

int one_unsetenv(char **env, char *save)
{
    int nbr_char = my_strlen(save);
    char *str = malloc(sizeof(char) * my_strlen(save) + 2);
    
    str = my_strcpy(str, save);
    my_strcat(str, "=");
    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], save, nbr_char) == 0 &&
            env[i][nbr_char] == '=')
            remove_line(env, i);
    return (0);
}

int my_unsetenv(char **env, char *line)
{
    char **save = my_str_to_word_array(line);

    if (my_strcmp(save[0], "unsetenv") == 0 && my_strlen_env(save) == 1)
        write(2, "Too few arguments.\n", 19);
    for (int i = 1; save[i] != NULL; i++)
        one_unsetenv(env, save[i]);
    return (0);
}

int check_var_env(char **env, char *save)
{
    int i = 0;
    int nbr_char = my_strlen(save);
    char *str = malloc(sizeof(char) * my_strlen(save) + 2);

    str = my_strcpy(str, save);
    str = my_strcat(str, "=");
    for (; env[i] != NULL; i++)
        if (my_strncmp(env[i], save, nbr_char) == 0 &&
            env[i][nbr_char] == '=') {
            return (i);
        }
    return (-1);
}

int my_is_char(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
        return (1);
    return (0);
}