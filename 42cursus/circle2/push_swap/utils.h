#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

