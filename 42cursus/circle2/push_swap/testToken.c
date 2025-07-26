#include "utils.h"
// read, write, malloc, free

int is_strict_int(const char *s, int *out){
    long long acc = 0;
    int sign = 1;
    int i = 0;
    
    //문자열 체크
    if(!s[0]) 
        return 0;
    // 부호 체크
    if(s[i] == '+' || s[i] == '-'){
        if(s[i++] == '-')
            sign = -1;
        //부호만 있는 경우, return 0
        if(!s[i]) 
            return 0;
    }
    while(s[i]){
        //숫자가 아닐 경우, return 0
        if(!ft_isdigit(s[i]))
            return 0;
        acc = acc * 10 + (s[i++] - '0');
        //Over min max case, return 0;
        if(acc * sign >  2147483647 || acc * sign < -2147483648)
            return 0;
    }
    *out = acc * sign;
    return 1;
}



int main(int ac, char **av){
    //main함수에서의 return1은 모두 에러처리.
    char **sub;
    char **tokens;
    int *num;
    int tok_count = 0;
    int MAX_ARGS = 1024;

    if(ac < 2)
        return 0;
    
    //tokenization - agrv 분해, split
    tokens = malloc(sizeof(char *) * MAX_ARGS);
    if(!tokens)
        return 1;

    for(int i = 1; i < ac; i++){
        sub = ft_split(av[i], ' ');

        for(int j = 0; sub[j]; j++)
            tokens[tok_count++] = sub[j];
        free(sub);
    }

    //write의 fd=2 : 표준 에러 출력
    //숫자 검사, 변환
    num = malloc(sizeof(int) * tok_count);
    if(!num)
        return 1;

    for(int i = 0; i < tok_count; i++){
        if(!is_strict_int(tokens[i], &num[i])){
            write(2, "Error\n", 6);
            return 1;
        }
    }
    
    //중복 검사
    for(int i = 0; i < tok_count; i++){
        for(int j = i+1; j < tok_count; j++){
            if(num[i] == num[j]){
                write(2, "Error\n", 6);
                return 1;
            }
        }
    }

    for(int i = 0; i < tok_count; i++){
        free(tokens[i]);
    }
    free(tokens);
    free(num);
    return 0;
}