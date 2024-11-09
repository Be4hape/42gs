<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:19:11 by si-park           #+#    #+#             */
/*   Updated: 2024/10/27 21:44:34 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// s1의 start 인덱스에 있는 문자를 받음.
// 문자열이 아니라 문자를 받음. 
// 이후 return 1을 하고, 만약 while문의 && 조건에 모두 부합한다면 start가 증가한다.
// s1문자가 탐색 문자 set과 하나라도 같을 경우 : set++ 하는 반복이 필요.
static int isInset(char s1, char *set)
{
    while(*set)
    {
        if(s1 == *set)
            return 1;
        set++;
    }
    return 0;
}



// s1  -> 잘라낼 대상 문자열
// set -> s1에서 set 문자열을 찾고 제거한다. 제거 조건은 s1의 앞과 뒤에서임
// "xxhelloxx"가 있을 때, set을 xx로 지정하면 xx는 지워지고 hello 가 나온다
// 반환값은 s1에서 set을 앞뒤에서 제거한 새로운 문자열, 이는 동적할당이 필요

char *ft_strtrim(char const *s1, char const *set)
{
    int i = 0;
    int start = 0;
    int end = ft_strlen(s1) - 1;

    while(s1[start] && isInset(s1[start], (char *)set))
        start++;
    while(end >= start && isInset(s1[end], (char *)set))
        end--;
    
    // start의 인덱스는 문자열이 시작하기 전 인덱스가 아니라 문자열이 시작한 후의 인덱스이기 때문에 
    // +1을 더 해야한다, 따라서 +2가 되는 것. ( null은 원래 +1을 해야하므로 )
    char *cc = malloc(end - start + 2);
    if(cc == NULL)
        return NULL;
    while(i < end - start + 1 )
    {
        cc[i] = s1[start + i];
        i++;
    }
    cc[i] = '\0';
    return cc;
}

// int main() {
//     char *result;

//     // Test case 1: 양쪽에서 지정된 문자 제거
//     result = ft_strtrim("xxHello Worldxx", "x");
//     printf("Test 1: %s (Expected: Hello World)\n", result);
//     free(result);

//     // Test case 2: 중간에 있는 문자는 남김
//     result = ft_strtrim(" xxhelloxx ", " x");
//     printf("Test 2: %s (Expected: xhello)\n", result);
//     free(result);

//     // Test case 3: 여러 문자가 set에 포함된 경우
//     result = ft_strtrim("!!Hello!!", "!");
//     printf("Test 3: %s (Expected: Hello)\n", result);
//     free(result);

//     // Test case 4: s1이 빈 문자열일 때
//     result = ft_strtrim("", "x");
//     printf("Test 4: %s (Expected: )\n", result);  // 빈 문자열 예상
//     free(result);

//     // Test case 5: set이 빈 문자열일 때 (s1 반환)
//     result = ft_strtrim("Hello", "");
//     printf("Test 5: %s (Expected: Hello)\n", result);
//     free(result);

//     // Test case 6: 공백 문자를 set으로 지정
//     result = ft_strtrim("   Hello World   ", " ");
//     printf("Test 6: %s (Expected: Hello World)\n", result);
//     free(result);

//     // Test case 7: s1과 set이 둘 다 NULL인 경우
//     result = ft_strtrim(NULL, NULL);
//     printf("Test 7: %s (Expected: (null))\n", result ? result : "(null)");

//     return 0;

// }
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:19:11 by si-park           #+#    #+#             */
/*   Updated: 2024/10/27 21:44:34 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// s1의 start 인덱스에 있는 문자를 받음.
// 문자열이 아니라 문자를 받음. 
// 이후 return 1을 하고, 만약 while문의 && 조건에 모두 부합한다면 start가 증가한다.
// s1문자가 탐색 문자 set과 하나라도 같을 경우 : set++ 하는 반복이 필요.
static int isInset(char s1, char *set)
{
    while(*set)
    {
        if(s1 == *set)
            return 1;
        set++;
    }
    return 0;
}



// s1  -> 잘라낼 대상 문자열
// set -> s1에서 set 문자열을 찾고 제거한다. 제거 조건은 s1의 앞과 뒤에서임
// "xxhelloxx"가 있을 때, set을 xx로 지정하면 xx는 지워지고 hello 가 나온다
// 반환값은 s1에서 set을 앞뒤에서 제거한 새로운 문자열, 이는 동적할당이 필요

char *ft_strtrim(char const *s1, char const *set)
{
    int i = 0;
    int start = 0;
    int end = ft_strlen(s1) - 1;

    while(s1[start] && isInset(s1[start], (char *)set))
        start++;
    while(end >= start && isInset(s1[end], (char *)set))
        end--;
    
    // start의 인덱스는 문자열이 시작하기 전 인덱스가 아니라 문자열이 시작한 후의 인덱스이기 때문에 
    // +1을 더 해야한다, 따라서 +2가 되는 것. ( null은 원래 +1을 해야하므로 )
    char *cc = malloc(end - start + 2);
    if(cc == NULL)
        return NULL;
    while(i < end - start + 1 )
    {
        cc[i] = s1[start + i];
        i++;
    }
    cc[i] = '\0';
    return cc;
}

// int main() {
//     char *result;

//     // Test case 1: 양쪽에서 지정된 문자 제거
//     result = ft_strtrim("xxHello Worldxx", "x");
//     printf("Test 1: %s (Expected: Hello World)\n", result);
//     free(result);

//     // Test case 2: 중간에 있는 문자는 남김
//     result = ft_strtrim(" xxhelloxx ", " x");
//     printf("Test 2: %s (Expected: xhello)\n", result);
//     free(result);

//     // Test case 3: 여러 문자가 set에 포함된 경우
//     result = ft_strtrim("!!Hello!!", "!");
//     printf("Test 3: %s (Expected: Hello)\n", result);
//     free(result);

//     // Test case 4: s1이 빈 문자열일 때
//     result = ft_strtrim("", "x");
//     printf("Test 4: %s (Expected: )\n", result);  // 빈 문자열 예상
//     free(result);

//     // Test case 5: set이 빈 문자열일 때 (s1 반환)
//     result = ft_strtrim("Hello", "");
//     printf("Test 5: %s (Expected: Hello)\n", result);
//     free(result);

//     // Test case 6: 공백 문자를 set으로 지정
//     result = ft_strtrim("   Hello World   ", " ");
//     printf("Test 6: %s (Expected: Hello World)\n", result);
//     free(result);

//     // Test case 7: s1과 set이 둘 다 NULL인 경우
//     result = ft_strtrim(NULL, NULL);
//     printf("Test 7: %s (Expected: (null))\n", result ? result : "(null)");

//     return 0;

// }
>>>>>>> 81752f0d6e25ee9ed1f5ad65f1e20e7b6e5c46cf
