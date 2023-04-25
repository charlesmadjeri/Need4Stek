/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-sami.benkirane-saadi [WSL: Ubuntu]
** File description:
** my_putstr
*/

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}
