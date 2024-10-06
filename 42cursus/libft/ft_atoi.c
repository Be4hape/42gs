/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:41:02 by si-park           #+#    #+#             */
/*   Updated: 2024/10/06 20:43:25 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	bs_skip(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		else if (str[i] == '-' || str[i] == '+')
		{
			while (str[i] == '-' || str[i] == '+')
			{
				if (str[i] == '-')
					*sign *= -1;
				i++;
			}
			break ;
		}
		else
			break ;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;

	value = 0;
	i = bs_skip(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	return (sign * value);
}
*/
int	ft_atoi(const char *str)
{
    int i = 0;
    int plma_len = 0;
    int sign;
    int value = 1;
    
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;

        if(plma_len >= 2)
            return 0;

        plma_len++;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
    return value * sign;
}


int main(void)
{
	// 정상적인 숫자 입력
	char *test1 = "12345";
	char *test2 = "-12345";
	char *test3 = "+12345";

	// 앞에 공백이 있는 입력
	char *test4 = "   6789";
	char *test5 = "   -6789";
	char *test6 = "   +6789";

	// 여러 개의 부호가 있는 입력
	char *test7 = "--123";
	char *test8 = "++456";
	char *test9 = "+-789";

	// 숫자가 아닌 문자가 포함된 입력
	char *test10 = "123abc";
	char *test11 = "abc123";

	// 빈 문자열과 숫자가 없는 문자열
	char *test12 = "";
	char *test13 = "   ";

	// 테스트 케이스 출력
	printf("Test1: %d\n", ft_atoi(test1));    // 12345
	printf("Test2: %d\n", ft_atoi(test2));    // -12345
	printf("Test3: %d\n", ft_atoi(test3));    // 12345
	printf("Test4: %d\n", ft_atoi(test4));    // 6789
	printf("Test5: %d\n", ft_atoi(test5));    // -6789
	printf("Test6: %d\n", ft_atoi(test6));    // 6789
	printf("Test7: %d\n", ft_atoi(test7));    // 0 or 처리 방식에 따라 달라짐
	printf("Test8: %d\n", ft_atoi(test8));    // 0 or 처리 방식에 따라 달라짐
	printf("Test9: %d\n", ft_atoi(test9));    // 0 or 처리 방식에 따라 달라짐
	printf("Test10: %d\n", ft_atoi(test10));  // 123
	printf("Test11: %d\n", ft_atoi(test11));  // 0
	printf("Test12: %d\n", ft_atoi(test12));  // 0
	printf("Test13: %d\n", ft_atoi(test13));  // 0

	return 0;
}