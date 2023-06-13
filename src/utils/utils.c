/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils
*/

void swap (int *a , int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int my_getnbr (char const *str)
{
    int i = 0;
    int n = 0;
    long long int nbr = 0;
    while (str[i] > '9' || str[i] < '0' && str[i])
        if (str[i++] == '-') n += 1;
    while (str[i] <= '9' && str[i] >= '0' && str[i]) {
        if (((nbr >= 214748364 && str[i] > '8') || nbr >= 214748365)
            || (n % 2 == 0 && nbr >= 214748364 && str[i] > '7'))
            return 0;
        nbr = nbr * 10 + str[i] - '0';
        i++;
    }
    if (n % 2 != 0) nbr = -nbr;
    return nbr;
}
