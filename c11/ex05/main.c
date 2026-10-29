#include "ex05.h"

int main(int argc, char **argv)
{
    t_op ops[5] = {
        {'+', add}, {'-', sub}, {'*', mul}, {'/', div_}, {'%', mod}
    };
    int a;
    int b;
    int i;

    if (argc != 4)
        return (0);
    a = ft_atoi(argv[1]);
    b = ft_atoi(argv[3]);
    i = 0;
    while (i < 5)
    {
        if (argv[2][0] == ops[i].op && argv[2][1] == '\0')
        {
            if (ops[i].op == '/' && b == 0)
                write(1, "Stop : division by zero\n", 24);
            else if (ops[i].op == '%' && b == 0)
                write(1, "Stop : modulo by zero\n", 22);
            else
                ft_putnbr(ops[i].f(a, b));
            return (0);
        }
        i++;
    }
    printf("0\n");
    return (0);
}