/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:19:18 by si-park           #+#    #+#             */
/*   Updated: 2024/11/08 14:19:18 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//문자열 s를 구분자 c로 나누어 배열로 반환.
char **ft_split(char const *s, char c)
{
    while(*s)
    {
        if(c)
        {
            s++;
        }
        s++;
    }
    
}


int main() 
{
    char str[] = "hello,world,this,is,a,test";
    char delimiter = ',';

    printf("Original string: \"%s\"\n", str);
    printf("Delimiter: '%c'\n", delimiter);

    // ft_split 호출
    char **result = ft_split(str, delimiter);

    // 결과 출력
    printf("Split result:\n");
    print_split_result(result);

    return 0;
}