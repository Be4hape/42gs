#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);



/*
 * Complete the 'finalState' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts 2D_INTEGER_ARRAY operations as parameter.
 */


// 스위치는 초기에 모두 꺼져있는 상태.
// finalstate 함수의 반환값은 켜진 스위치의 모든 합
// 파라미터는 차례대로 행, 열, operations[L][R] 값
// 제약조건 : 시간 복잡도 q < 10만번, 
//           1 <= L <= R <= 10만
// 모든 스위칭을 연산할 시 10만번을 넘어감.
long finalState(int operations_rows, int operations_columns, int** operations) {
    
    int maxIndex = 0;
    for (int i = 0; i < operations_rows; i++) {
        int r = operations[i][1];
        if (r > maxIndex) maxIndex = r;
    }

    int *diff = calloc((size_t)maxIndex + 2, sizeof(int));
        if (!diff) exit(EXIT_FAILURE);

    for (int i = 0; i < operations_rows; i++) {
        int l = operations[i][0];
        int r = operations[i][1];
        diff[l] += 1;
        diff[r + 1] -= 1;
    }
    long answer = 0;
    int flips = 0;

    for (int i = 1; i <= maxIndex; i++) {
        flips += diff[i];
        if (flips & 1) {
            answer += i;
        }
    }

    free(diff);
    return answer;
}


int main()
{
    //입력은 파일의 형태
    //입력1 : q, 행(반복횟수)
    //입력2 : 열
    //L,R 을 반복횟수만큼 입력    
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    
    //문자열 읽고, 좌우측 공백 제거, 문자열 부분만 추출해서 atoi함수.> 정수. 전처리임
    int operations_rows = parse_int(ltrim(rtrim(readline())));

    int operations_columns = parse_int(ltrim(rtrim(readline())));

    int** operations = malloc(operations_rows * sizeof(int*));  

    //행열 동적할당
    for (int i = 0; i < operations_rows; i++) {
        *(operations + i) = malloc(operations_columns * (sizeof(int)));

        char** operations_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < operations_columns; j++) {
            int operations_item = parse_int(*(operations_item_temp + j));

            *(*(operations + i) + j) = operations_item;
        }
    }

    long result = finalState(operations_rows, operations_columns, operations);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

//문자열 읽기
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}


//좌우측 공백제거
char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

//split함수
char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

//atoi
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
