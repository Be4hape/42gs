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

static int count_len(char const *s, char c)
{
    int len_s = 0;
    //s 문자열에서 c를 만날 때
    while(*s)
    {
        while(*s == c)
            s++;
        len_s++;
        s++;
    }
    return len_s;
}


static char *innerWord(const char *start, int length)
{
    int i = 0;
    char *word = (char *)malloc(length + 1);
    if(word == NULL)
        return NULL;

    while(i < length)
    {
        word[i] = start[i];
        i++;
    }
    word[i] = '\0';
    return word;
}


//문자열 s를 구분자 c로 나누어 배열로 반환.
char **ft_split(char const *s, char c)
{
    int length = 0;
    int len_s = count_len(s, c);
    int i = 0;
    char const *start;
    
    //null의 공간 + 1
    char **result = (char **)malloc(sizeof(char*) * (len_s + 1));

    if(result == NULL)
        return NULL;

    while(*s)
    {
        if(*s == c)
            s++;
        //구분자 다음 시작 주소 저장
        if(*s){
            start = s;
            length = 0;
            //단어 길이 저장
            while(*s && *s != c)
            {
                length++;
                s++;
            }
        }
        result[i] = innerWord(start, length);
        i++;
    }
    result[i] = NULL;
}

// 결과를 출력하고 메모리를 해제하는 함수
void print_split_result(char **result) {
    if (!result) {
        printf("NULL\n");
        return;
    }

    int i = 0;
    while (result[i]) {
        printf("String %d: %s\n", i, result[i]);
        free(result[i]);  // 각 문자열 메모리 해제
        i++;
    }
    free(result);  // 배열 메모리 해제
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