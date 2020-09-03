/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019
** File description:
** my_exec
*/

#ifndef MY_EXEC_H_
#define MY_EXEC_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <dirent.h>

int get_env(char **env);
int my_env(char **env, char **save);
char *my_strmult(char *src);
int my_strlen_env(char **env);
int clone_env(char **env);
int env_sh(char **env, char *line);
int my_sh(char **env);
int my_is_char(char c);
int my_is_char2(char c);
void set_env(char **env, char *name, char *value, int count);
char **line(char *str);
int my_exit(char *line);
void remove_line(char **tab, int index);
int my_setenv(char **env, char **save);
int my_setenv_b(char **save);
int my_unsetenv(char **env, char *line);
int one_unsetenv(char **env, char *save);
int check_var_env(char **env, char *save);
char *value_env(char *name, char *value, int count);
int check_char_str(char *str);
int env_sh2(char **env, char *line);
int check_function_path(char **env);
int my_open_dir(char **env);
int my_strlen_function2(char *str);
int check_nbr_word2(char *str);
int *nbr_char_word2(char *str);
char **my_str_to_word_array2(char *str);
char *create_space(char **env);
int browse_file(char **env, char *line);
int browse_file2(void);
int not_found(char **save);
int check_line_file(char **env, char *line);
char *done_space(char **env);
char *my_strmult(char *src);
int found_home(char **env);
char *remove_equal(char **env);
char *get_home(char **env);
int check_pwd(char **env);
char *modif_pwd(char **env);
int my_cd(char **env);
int found_oldpwd(char **env);
char *remove_equal2(char **env);
char *get_oldpwd(char **env);
char *remove_equal3(char **env);
char *get_pwd(char **env);
int my_cd_file(char **env, char *line);
char *create_pwd(char **env, char *line);
char *create_oldpwd(char **env, char *line);
int my_exit2(char **save);
#endif /* !MY_EXEC_H_ */
