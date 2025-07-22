#include "utils.h"

//atoi
int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*(str + 1) == '+' || *(str + 1) == '-')
			return (0);
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = (value * 10) + (*str - '0');
		str++;
	}
	return (value * sign);
}

//split
static int	count_len(char const *s, char c)
{
	int	len_s;

	len_s = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len_s++;
			while (*s && *s != c)
				s++;
		}
	}
	return (len_s);
}

static char	*inner_word(const char *start, int length)
{
	char	*word;
	int		i;

	word = (char *)malloc(length + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	fill_result_loop(char **result, char const *s, char c, int *i)
{
	const char	*start;
	int			length;

	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = s;
			length = 0;
			while (*s && *s != c)
			{
				length++;
				s++;
			}
			result[*i] = inner_word(start, length);
			if (result[*i] == NULL)
				return (*i);
			(*i)++;
		}
	}
	result[*i] = NULL;
	return (-1);
}

static void	free_result(char **result, int i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	int		len_s;
	char	**result;
	int		fail_index;
	int		i;

	len_s = count_len(s, c);
	result = (char **)malloc(sizeof(char *) * (len_s + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	fail_index = fill_result_loop(result, s, c, &i);
	if (fail_index != -1)
	{
		free_result(result, fail_index);
		return (NULL);
	}
	return (result);
}
