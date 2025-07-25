#include <stdlib.h>

int	*ft_range(int start, int end)
{
    int size;
    int *arr;
    int step;
    int i;
    int current;

    if (end >= start)
        size = end - start + 1;
    else
        size = start - end + 1;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);

    if (end >= start)
        step = 1;
    else
        step = -1;

    i = 0;
    current = start;
    while (i < size)
    {
        arr[i] = current;
        current += step;
        i++;
    }
    return (arr);
}
