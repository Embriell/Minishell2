/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019
** File description:
** main
*/

#include "include/my.h"
#include "include/mysh.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    int i = 0;
    int coln_env = my_strlen_env(env);
    char **my_env = malloc(sizeof(char *) * (coln_env + 2));

    for (; env[i] != NULL; i++) {
        my_env[i] = my_strmult(env[i]);
    }
    my_env[i] = NULL;

    if (my_sh(my_env) == 0)
        return (0);

    return (0);
}