#include <unistd.h>

// allowed function is putchar
void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main()
{

    return 0;
}