

Assignment name : flood_fill
Expected files : *.c, *.h
Allowed functions: -
char ** 형태의 2차원 char 배열과 t_point 구조체로 배열의 크기를,
t_point 구조체로 시작점을 받아, 주어진 ‘begin’ 좌표에서부터
동일한 문자로 이루어진 영역(zone)을 ‘F’ 문자로 채웁니다.
영역은 수평 및 수직으로 인접한 동일 문자의 집합으로,
다른 문자나 배열 경계에 의해 구분됩니다.
대각선 방향으로는 채우지 않습니다.

flood_fill 함수 원형:
void flood_fill(char **tab, t_point size, t_point begin);

t_point 구조체 정의:
typedef struct s_point
{
int x;
int y;
} t_point;

Example:
$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"
int main(void)
{
char **area;
t_point size = {8, 5};
t_point begin = {2, 2};
char *zone[] = {
"1 1 1 1 1 1 1 1",
"1 0 0 0 1 0 0 1",
"1 0 0 1 0 0 0 1",
"1 0 1 1 0 0 0 1",
"1 1 1 0 0 0 0 1",
};
area = make_area(zone);
print_tab(area);
flood_fill(area, size, begin);
putc('\n');
print_tab(area);
return (0);
}
$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill; ./flood_fill
1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1
1 0 1 0 0 0 0 1
1 1 0 0 0 0 0 0
1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 0 0 0 0 1
1 1 0 0 0 0 0 0
$>




==================================================

주어진 2차원 배열 t_point size 만큼의 크기 안에서 
t_point begin 에서 시작하여
1로 둘러쌓인 0인 지점을 모두 F로 채워넣어라.
대각선 방향으로는 채우지 않는다.



2차원 배열공간 t_point size 만큼의 크기를 받아서, 
t_point begin 과 같은 문자로 이루어진 구역을 채워라.
대각선 방향으로는 채우지 않는다.

t_point size  = {8, 5};
t_point begin = {2, 2};
char *zone[] = {
    "1 1 1 1 1 1 1 1",
    "1 0 0 0 1 0 0 1",
    "1 0 0 1 0 0 0 1",
    "1 0 1 1 0 0 0 1",
    "1 1 1 0 0 0 0 1",
};
area = make_area(zone);    // 내부적으로 strdup 등으로 2차원 배열 생성
print_tab(area);           // flood_fill 이전 출력
flood_fill(area, size, begin);
print_tab(area);           // flood_fill 이후 출력


로 들어왔다면,

1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 0 0 0 0 1
1 1 0 0 0 0 0 0

이런식으로 채워져야 한다.
begin이 0이고, 수직, 수평 방향으로 0이 있기 때문에 F로 채워줄 수 있음.


but, 아래의 상황에서

t_point size = { 4, 4 }
t_point begin = { 2,0 }
1 0 1 0
0 1 0 1
1 0 1 0

>>
1 0 F 0
0 1 0 1
1 0 1 0
이런식으로 채워지는 것.

대각으로 채울 수 없고, begin과 같은 숫자로 이뤄진 공간이 수직과 수평방향에 없기 때문.














































