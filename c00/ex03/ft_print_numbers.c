#include <unistd.h>

void ft_print_numbers(void)
{
    char alphabet = '0';

    while (1)
    {
        write(1, &alphabet, 1);
        if (alphabet == '9')
            break;
        alphabet += 1;
    }
}

int main()
{
    ft_print_numbers();

    return 0;
}