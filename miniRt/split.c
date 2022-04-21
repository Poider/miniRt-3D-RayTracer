/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:58:37 by mel-amma          #+#    #+#             */
/*   Updated: 2022/04/03 21:58:50 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

static size_t	skip_left(char const *s1, char c)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == c)
		i++;
	return (i);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*allocate_cpy(const char *src, size_t len)
{
	char	*p;

	p = (char *)malloc(len);
	if (!p)
		return (NULL);
	ft_strlcpy(p, src, len);
	return (p);
}

static void	fill_split(char const *s, char c, char **res)
{
	size_t	strnb;
	size_t	i;
	size_t	sindex;

	strnb = 0;
	i = 0;
	sindex = 0;
	while (strnb < count_words(s, c))
	{
		i = i + skip_left(s + i, c);
		sindex = i;
		while (s[i] && s[i] != c)
			i++;
		res[strnb] = allocate_cpy(s + sindex, i - sindex + 1);
		if (res[strnb] == NULL)
		{
			while (strnb > 0)
				free(res[strnb--]);
			free(res[strnb]);
			free(res);
			return ;
		}
		strnb++;
	}
	res[strnb] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (0);
	if ((!ft_strlen(s) && !c) || (!ft_strlen(s)))
	{
		res = malloc(1 * sizeof(char *));
		res[0] = NULL;
		return (res);
	}
	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	fill_split(s, c, res);
	return (res);
}
