/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:13:29 by si-park           #+#    #+#             */
/*   Updated: 2025/01/13 13:13:47 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

//for test, i include stdio
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	while (*s++)
        ft_putchar_fd(*(s-1), fd);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	j = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] == little[j])
			{
				j++;
				if (j == little_len)
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}





int ft_printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);

    int i = 0;
    char *dir;
    int index;    
    
    char *format[] = {"%c", "%s", "%p", "%d", "%i", "%u", "%x", "%X", "%%", NULL};

    while (format[i] != NULL){
        dir = ft_strnstr(str, format[i], ft_strlen(str));
        printf("%p\n", dir);
        if(dir) forprint(i);
        i++;
    }
}




void forprint(int i)
{
    if (i == 0) ft_printf_c();
    if (i == 1) ft_printf_s();
    if (i == 2) ft_printf_p();
    if (i == 3) ft_printf_d();
    if (i == 4) ft_printf_i();
    if (i == 5) ft_printf_u();
    if (i == 6) ft_printf_x();
    if (i == 7) ft_printf_X();
    if (i == 8) ft_printf_per();
}


char ft_printf_util(args)
{
    //가변인자를 받고 
    
}







int main(){
    /*
    const char *str = "hello %d %c %s";
    
    
    int i = 0;
    int index;
    char *dir;
    
    char *format[] = {"%c", "%s", "%p", "%d", "%i", "%u", "%x", "%X", "%%", NULL};
    //printf("%s\n", format[2]);


    
    while (format[i] != NULL){
        dir = ft_strnstr(str, format[i], ft_strlen(str));
        printf("%p\n", dir);
        //if(dir) forprint(i);
        i++;
    }
    
    printf("%d", i);
    */
    
    return 0;
}
