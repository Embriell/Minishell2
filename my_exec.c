/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019
** File description:
** my_exec
*/

#include "include/my.h"
#include "include/mysh.h"

int my_strlen_env(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++);
    return (i);
}

char *my_strmult(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int get_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_printf("%s\n", env[i]);
    }
    return 0;
}

int clone_env(char **env)
{
    int coln_env = my_strlen_env(env);
    char **save = malloc(sizeof(char *) * (coln_env + 1));

    for (int i = 0; env[i] != NULL; i++) {
        save[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        save[i] = my_strmult(env[i]);
        my_printf("%s\n", save[i]);
    }
    return (0);
}

int my_sh(char **env)
{
    int nb;
    char *line = NULL;
    size_t len = 0;

    while (1) {
        my_printf("$> ");
        if (getline(&line, &len, stdin) == - 1) {
            my_printf("exit\n");
            exit (0);
        }
        nb = env_sh(env, line);
        clean_str(line);
        if (nb)
            exit(0);
    }
    return (0);
}