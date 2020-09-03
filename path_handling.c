/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell4
*/

#include "include/my.h"
#include "include/mysh.h"

int check_function_path(char **env)
{
    int nbr;

    for (int i = 0; env[i] != NULL; i++) {
        nbr = my_strncmp(env[i], "PATH=", 5);
        if (nbr == 0) {
            return (i);
        }
    }
    return (-1);
}

char *create_space(char **env)
{
    int lin = check_function_path(env);

    for (int i = 0; env[lin][i] != '\0'; i++)
        if (env[lin][i] == ':')
            env[lin][i] = ' ';
    return (env[lin]);
}

char *done_space(char **env)
{
    int lin = check_function_path(env);

    for (int i = 0; env[lin][i] != '\0'; i++)
        if (env[lin][i] == ' ')
        env[lin][i] = ':';
    return (env[lin]);
}

int browse_file(char **env, char *line)
{
    pid_t pid;
    char *my_path = create_space(env);
    char **file = my_str_to_word_array(my_path);
    char **save = my_str_to_word_array(line);
    int check_value = -1;
    char *str;
    char *str2;

    if (check_line_file(env, line) == 0)
        return (0);
    pid = fork();
    for (int i = 1; file[i] != NULL; i++) {
        str = my_strcat(file[i], "/");
        str2 = my_strcat(str, save[0]);
        check_value = access(str2, X_OK);
        if (check_value == 0 && pid == 0) {
            if (execve(str2, save, env) == -1)
                browse_file2();
        }
        wait(&pid);
        break;
    }
    my_path = done_space(env);
    return (check_value);
}

int browse_file2(void)
{
    int pid = 0;
    int error = 0;

    if (pid == - 1)
        write(2, "Error fork", 45);
    else if (pid > 0) {
        if (error == 139) {
            write(2, "Segmentation fault (core dumped)\n", 34);
            write(2, "program exited with code: 139", 30);
            exit (139);
        }
    }
    return (0);
}