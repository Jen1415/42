# ifndef EX05_H
#define EX05_H
#include <unistd.h>
int	ft_atoi(char *str);
int	ft_operation(int nbr1, char *op, int nbr2);
int	ft_putnbr(int nbr);
int add(int a, int b); 
int sub(int a, int b); 
int mul(int a, int b); 
int div_(int a, int b);
int mod(int a, int b);

typedef struct {
    char op;
    int (*f)(int, int);
} t_op;


# endif 