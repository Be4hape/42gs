#include <stdio.h>
#include <stdlib.h>
//malloc

// 이중포인터임을 잊지 않아야함.

//space/tabs/new lines
//or by the start/end of the string
//문자열 하나를 받아 단어 단위로 분할한 뒤, 
//NULL-종료된 문자열 배열로 반환하는 함수를 작성하시오.

//“단어”란 공백(spaces), 탭(tabs), 개행(new lines) 또는 
// 문자열의 시작/끝으로 구분되는 부분 문자열을 의미한다.
char    **ft_split(char *str){
    int i = 0, j = 0;
    int word = 0;
    int blank = 0;
    int len;
    char **ss;
    
    while(str[i]){
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0'){
            blank++;
            i++;
        }
        word++;
        i++;
    }

    //word에는 단어의 개수가 저장되어있음.
    //전체 str의 길이를 잰 뒤, 전체-word 만큼 malloc을 한다.
    while(str[i])
        i++;
    len = i - word;
    ss = (char **)malloc(sizeof(char) * blank + 1);
    while(j < len){
        ss[j] = malloc(len + 1);
        
    }

    if(!ss)
        return NULL;

    i = 0;
    while(str[i]){


        i++;
    }



}

int main(){
    int i = 0;
    char **str = ft_split("hello world");
    while(str[i]){
        printf("%s\n", str[i]);
        i++;
    }

    i = 0;
    while(str[i])
        free(str[i]);

    return 0;
}
