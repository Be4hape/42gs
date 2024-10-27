/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-park <si-park@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:41:27 by si-park           #+#    #+#             */
/*   Updated: 2024/10/26 21:35:13 by si-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*cc;
	unsigned int	i;
	unsigned int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	cc = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	if (cc == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		cc[i] = s[start + i];
		i++;
	}
	cc[i] = '\0';
	return (cc);
}
/*
---TEST CODE---
int main() {
    char *result;

    // Test case 1: 기본 테스트
    result = ft_substr("hello", 0, 2);
    printf("Test 1: %s (Expected: he)\n", result);
    free(result);

    // Test case 2: 문자열 중간에서 추출
    result = ft_substr("hello", 1, 3);
    printf("Test 2: %s (Expected: ell)\n", result);
    free(result);

    // Test case 3: len이 너무 클 때
    result = ft_substr("hello", 2, 10);
    printf("Test 3: %s (Expected: llo)\n", result);
    free(result);

    // Test case 4: start가 문자열 길이 이상일 때
    result = ft_substr("hello", 10, 5);
    printf("Test 4: %s (Expected: )\n", result);  // 빈 문자열 예상
    free(result);

    // Test case 5: len이 0일 때
    result = ft_substr("hello", 1, 0);
    printf("Test 5: %s (Expected: )\n", result);  // 빈 문자열 예상
    free(result);

    // Test case 6: 문자열 전체 추출
    result = ft_substr("hello", 0, 5);
    printf("Test 6: %s (Expected: hello)\n", result);
    free(result);

    // Test case 7: NULL 문자열 테스트
    result = ft_substr(NULL, 0, 5);
    printf("Test 7: %s (Expected: (null))\n", result ? result : "(null)");  // NULL 예상

    return 0;
}
*/