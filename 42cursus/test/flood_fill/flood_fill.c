#include "flood_fill.h"

void fill(char **tab, t_point size, char target, int row, int col){
    if(row < 0 || col < 0 || row >= size.y || col >= size.x)
        return;
        
    if(tab[row][col] == 'F' || tab[row][col] != target)
        return;

    tab[row][col] = 'F';

    fill(tab, size, target, row - 1, col);
    fill(tab, size, target, row + 1, col);
    fill(tab, size, target, row, col - 1);
    fill(tab, size, target, row, col + 1);
}


void  flood_fill(char **tab, t_point size, t_point begin){
    //tab   : map, 
    //size  : 만들어 낼 2차원 배열 size
    //begin : 시작 위치
    // tab[y][x] : 좌표 상 x는 열이어야 하고, y는 행이어야 함.
    char target = tab[begin.y][begin.x];
    fill(tab, size, target, begin.y, begin.x);
}

// test
char **make_area(char *zone[])
{
    int rows = 0;
    while (zone[rows])
        rows++;

    /* zone의 각 행에서 공백을 제외한 컬럼 수 */
    int cols = (int)((strlen(zone[0]) + 1) / 2);

    /* NULL-terminated 2차원 배열 할당 */
    char **area = malloc(sizeof(char*) * (rows + 1));
    if (!area) return NULL;

    for (int i = 0; i < rows; i++) {
        area[i] = malloc(cols + 1);
        if (!area[i]) return NULL;
        for (int j = 0; j < cols; j++) {
            /* "1 0 1 0" 같은 문자열에서 짝수 인덱스만 추출 */
            area[i][j] = zone[i][2*j];
        }
        area[i][cols] = '\0';
    }
    area[rows] = NULL;
    return area;
}

//test to print
void print_tab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            if (j) putchar(' ');
            putchar(tab[i][j]);
        }
        putchar('\n');
    }
}


int main(void)
{
	char **area;
	t_point size = {4, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1",
		"1 1 0 0",
		"1 0 0 1",
		"1 0 1 1",
		"1 1 1 0",
        NULL
	};
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area);
	return (0);
}