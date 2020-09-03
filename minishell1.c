/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell1
*/

#include "include/my.h"
#include "include/mysh.h"

int my_exit2(char **save)
{
    int count = 0;

    if (my_strcmp(save[0], "exit") ==  0) {
        count = my_getnbr(save[1]);
        my_printf("exit\n");
        return (count);
    }
    return (0);
}

int my_setenv_b(char **save)
{
    int len = my_strlen_env(save);

    if (len > 1 && my_is_char(save[1][0]) == 0) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return (0);
    }
    else if (len > 1 && check_char_str(save[1]) == 1) {
        write(2, "setenv: Variable name must contain ", 36);
        write(2, "alphanumeric characters.\n", 26);
        return (0);
    }
    if (my_strcmp(save[0], "setenv") == 0 && my_strlen_env(save) > 3) {
        write(2, "setenv: Too many arguments.\n", 29);
        return (0);
    }
    return (1);
}

int my_setenv(char **env, char **save)
{
    int count = my_strlen_env(save);
    char *none = {""};
    int true = 0;

    if (my_strlen_env(save) > 1)
        true = check_var_env(env, save[1]);
    if (my_setenv_b(save) == 0)
        return (0);
    if (true > - 1 && my_strlen_env(save) > 1) {
        env[true] = value_env(save[1], save[2], count);
        return (0);
    }
    if (my_strcmp(save[0], "setenv") == 0 && my_strlen_env(save) == 3)
        set_env(env, save[1], save[2], count);
    else if (my_strcmp(save[0], "setenv") == 0 && my_strlen_env(save) == 2)
        set_env(env, save[1], none, count);
    else if (my_strcmp(save[0], "setenv") == 0 && my_strlen_env(save) == 1)
        get_env(env);
    return (0);
}

int env_sh2(char **env, char *line)
{
    char **save = my_str_to_word_array(line);
    int count = 0;

    count = my_exit2(save);
    if (count)
        exit(count);
    if (my_strcmp(save[0], "setenv") == 0)
        my_setenv(env, save);
    else if (my_strcmp(save[0], "unsetenv") == 0)
        my_unsetenv(env, line);
    if (my_strlen_env(save) == 1 && my_strcmp(save[0], "cd") == 0)
        my_cd(env);
    else if (my_strlen_env(save) > 1 && my_strcmp(save[0], "cd") == 0)
        my_cd_file(env, line);
    return (0);
}

int env_sh(char **env, char *line)
{
    char **save;

    if (my_exit(line))
        return (1);
    line[my_strlen(line) - 1] = '\0';
    save = my_str_to_word_array(line);
    if (my_strcmp(save[0], "env") == 0)
        my_env(env, save);
    if (my_strcmp(save[0], "setenv") != 0 && my_strcmp(save[0], "env") != 0
    && my_strcmp(save[0], "unsetenv") != 0 && my_strcmp(save[0], "exit")
    && my_strcmp(save[0], "cd")!= 0) {
        browse_file(env, line);
    }
    env_sh2(env, line);
    return (0);
}