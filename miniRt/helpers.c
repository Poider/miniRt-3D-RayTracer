/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:49:50 by mel-amma          #+#    #+#             */
/*   Updated: 2022/04/03 21:54:39 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;

	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (j < len && s[start])
	{
		str[j] = s[start];
		start++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (str == 0)
		return (0);
	len = ft_strlen((char *)s1);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int whitespaces(char c)
{
		return (c == '\n' || c == '\t' || c == ' ' || c == '\r' || c == '\v' || c == '\f');
}