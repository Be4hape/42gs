#include <unistd.h>

void ft_is_negative(int n)
{
    if(n >= 0)
        write(1, "P", 1);
    else if(n < 0)
        write(1, "N", 1);    
}

int main()
{
    int input = 10;
    ft_is_negative(input);

    return 0;
}