#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
    char alphabet = 'z';

    while (1)
    {
        write(1, &alphabet, 1);
        if (alphabet == 'a')
            break;
        alphabet -= 1;
    }
}

int main()
{
    ft_print_reverse_alphabet();

    return 0;
}