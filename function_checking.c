/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell3
*/

#include "include/my.h"
#include "include/mysh.h"

int my_is_char2(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'
        || c == '.' || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

void remove_line(char **tab, int index)
{
    for (; tab[index] != NULL; index++)
        tab[index] = tab[index + 1];
}

int check_char_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (my_is_char2(str[i]) == 0)
            return (1);
    return (0);
}

int my_exit(char *line)
{
    if (my_strcmp(line, "exit\n") == 0) {
        my_printf("exit\n");
        exit (0);
    }
    return (0);
}