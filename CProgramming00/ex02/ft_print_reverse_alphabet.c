#include <unistd.h>

void ft_print_reverse_alphabet(void) {
    char ch = 'z';
    while (ch >= 'a') {
        write(1, &ch, 1);
        ch--;
    }
}

int main(void) {
    ft_print_reverse_alphabet();
    write(1, "\n", 1);
    return (0);
}