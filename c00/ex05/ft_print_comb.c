#include <unistd.h>

void ft_print_comb(void)
{
    int i = 0;
    int hunds, tens, ones;

    while(i < 1000){
        hunds = (i / 100) + '0';
        tens = ((i % 100) / 10) + '0';
        ones = (i % 10) + '0';

        if(hunds < tens && tens < ones && hunds < ones)
        {
            if(hunds != tens && tens != ones){
                write(1, &hunds, 1);
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

int main()
{
    ft_print_comb();

    return 0;
}