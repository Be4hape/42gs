#include <unistd.h>

void ft_print_comb(int i)
{
    int i = 0;
    int tens, ones;

    while(i < 100){
        tens = ((i % 100) / 10) + '0';
        ones = (i % 10) + '0';

        if(tens < ones && hunds < ones)
        {
            if(tens != ones){
                write(1, &tens, 1);
                write(1, &ones, 1);

                if(i != 789)
                    write(1, ", ", 2);
                else if(i == 789)
                        break;
            }
        }
        i++;
    }write(1, "\n", 1);
}


void ft_print_comb2(void)
{
    int i = 0;
    int j = 0;

    
}


int main()
{
    ft_print_comb2();

    return 0;
}