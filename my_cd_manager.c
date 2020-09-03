/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd_manager
*/

#include "include/my.h"
#include "include/mysh.h"

int my_cd(char **env)
{
    char *my_home = get_home(env);
    int nbr = chdir(my_home);

    if (nbr == 0)
        modif_pwd(env);
    return (0);
}

int my_cd_file(char **env, char *line)
{
    char **save = my_str_to_word_array(line);
    char *pwd = get_pwd(env);
    char *my_pwd = malloc(sizeof(char) * my_strlen(pwd) + 2);
    my_pwd = my_strcat(pwd, "/");
    char *new_pwd = malloc(sizeof(char) * (my_strlen(my_pwd) +
    my_strlen(save[1]) + 2));
    for (int a = 0; my_pwd[a]; ++a) { 
        new_pwd[a] = my_pwd[a];
        new_pwd[a + 1] = 0;
    }
    new_pwd = my_strcat(new_pwd, save[1]);
    int nbr;

    nbr = chdir(new_pwd);
    if (nbr == 0) {
        char *save[4] = {"setenv", "PWD", getcwd(NULL, 0), NULL};
        my_setenv(env, save);
    }
    return (0);
}