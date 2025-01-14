/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:02:36 by si-park           #+#    #+#             */
/*   Updated: 2025/01/14 16:10:00 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);

    int count_byte = 0;
    int n;
    char *numch;

    while (*str)
    {
        if(*str == '%')
        {
            if(*(str+1) == 'c') 
            {
                char c = (char)va_arg(args, int);
                ft_putchar_fd(c, 1);
                count_byte++;
            }
            else if(*(str+1) == 's')
            {
                char *nstr = va_arg(args, char *);
                ft_putstr_fd(nstr, 1);
                count_byte += ft_strlen(nstr);
            }
            else if(*(str + 1) == 'p')
            {
                void *pnum = va_arg(args, void *);
                count_byte += ft_print_p(pnum);
            }
            else if(*(str+1) == 'd' || *(str+1) == 'i' || *(str + 1) == 'u')
            {
                if(*(str + 1) == 'u')
                {
                    n = va_arg(args, int);
                    if(n < 0 ){
                        numch = ft_itoa(-n);
                    }
                }
                n = va_arg(args,int);
                numch = ft_itoa(n);
                if(numch)
                {
                    ft_putstr_fd(numch, 1);
                    count_byte += ft_strlen(numch);
                    free(numch);
                }
            }
            else if(*(str+1) == 'x' || *(str + 1) == 'X')
            {
                unsigned int n = va_arg(args, unsigned int);
                if(*(str + 1) == 'x') 
                    count_byte += ft_putnbr_hex(n, 0);
                else 
                    count_byte += ft_putnbr_hex(n, 1); 
            }
            else if(*(str+1) == '%')
            {
                ft_putstr_fd("%", 1);
                count_byte += 2;
            }
        }
        else{
            ft_putchar_fd(*str, 1);
            count_byte++;
        }        
        str++;
    }
    return count_byte;
}

int main(void)
{
    ft_printf("Hello, %s! Your score is %d%%.\n", "World", 95);
    ft_printf("Pointer test: %p\n", (void *)12345);
    ft_printf("Hex test (lowercase): %x\n", 255);
    ft_printf("Hex test (uppercase): %X\n", 255);
    ft_printf("Unsigned test: %u\n", 3000000000U);
    ft_printf("Percent test: %%\n");
    return 0;
}