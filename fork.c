/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell5
*/

#include "include/my.h"
#include "include/mysh.h"
int not_found(char **save)
{
    write(2, save[0], my_strlen(save[0]));
    write(2, ": Command not found.\n", 22);
    return (0);
}

int check_line_file(char **env, char *line)
{
    int i = 0;
    int count = 0;
    pid_t pid;
    char **save = my_str_to_word_array(line);

    for (;line[i] != '\0'; i++)
        if (line[i] == '/') {
            count = 1;
            break;
        }
    if (count == 0)
        return (1);
    if ((pid = fork()) == 0) {
        execve(save[0], save, env);
        exit (1);
    }
    wait(&pid);
    return (0);
}