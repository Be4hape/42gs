#include <unistd.h>

void ft_print_alphabet(void)
{
    char alphabet = 'a';

    while(1)
    {
        write(1, &alphabet, 1);
        if(alphabet == 'z')
            break;
        alphabet += 1;
    }   

}

int main()
{
    ft_print_alphabet();

    return 0;
}