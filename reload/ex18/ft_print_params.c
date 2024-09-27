#include <unistd.h>

// allowed function is putchar
void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    int i = 1;
    int j = 0;

    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != 0)
        {
            ft_putchar(argv[i][j]);
            j++;
        }

        if (i != argc - 1)
            ft_putchar('\n');

        i++;
    }
    return 0;
}