#include <unistd.h>


void ft_putchar(char ch)
{
    write(1, &ch, 1);
    write(1, "&c", 1);
    write(1,  "\na", 2);
    write(1, "f\n", 2);
}

int main()
{
    char  str1 = 'A';
    char *str2 = "Hello";

    ft_putchar(str1);
}