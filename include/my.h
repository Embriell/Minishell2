/*
** EPITECH PROJECT, 2019
** my
** File description:
** header file that contains the protorypes of all the funtions
*/

#ifndef MY_H_
#define MY_H_

char *clean_str(char *str);

char *new_str(char *str);

void remove_char(char *str, int index);

int check_char(char *str, int index);

char *put_start(char *str);

void put_end(char *str);

int is_char(char c);

void move_str(char *str);

int englober(char *str);

int my_printf(char *s, ...);

char **my_str_to_word_array(char *str);

int *nbr_char_word(char *str);

int check_nbr_word(char *str);

int my_strlen_function(char *str);

void init_function(void(**function)());

long int my_put_adress(long int nb);

void prefixe_adress(long int nb);

long int my_put_adress(long int nb);

void print_modulo(char c);

unsigned int my_put_unsigned_int(unsigned int nb);

int my_put_hexa_maj(int nb);

int my_put_hexa_x(int nb);

int my_put_bin(int nb);

int my_put_octa(int nb);

int my_strncpy_strlen ( char const *str);

void my_putchar(char c);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

char *my_strdup(char *dest, char const *src);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

#endif /* MY_H_ */
