#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_point{
    int x;
    int y;
} t_point;

char **make_area(char *zone[]);
void print_tab(char **tab);
void  flood_fill(char **tab, t_point size, t_point begin);

#endif