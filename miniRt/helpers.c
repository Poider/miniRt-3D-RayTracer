/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:49:50 by mel-amma          #+#    #+#             */
/*   Updated: 2022/11/15 15:24:17 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	if (!s1 && !s2 && n != 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	white_spaces(char c)
{
	return (c == '\n' || c == '\t' || c == ' ' \
			|| c == '\r' || c == '\v' || c == '\f');
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = ft_strlen(src);
	if (!dest || !src)
		return (0);
	if (size == 0)
		return (count);
	if (size > 0)
	{
		while (i + 1 < size && *src)
		{
			*dest++ = *src++;
			i++;
		}
	}
	*dest = '\0';
	return (count);
}

int	ft_toupper(int a)
{
	if (a >= 97 && a <= 122)
		a -= 32;
	return (a);
}

char	*to_upper(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		line[i] = ft_toupper(line[i]);
		i++;
	}
	return (line);
}
