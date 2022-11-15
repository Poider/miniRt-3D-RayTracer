/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:35:38 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/26 14:45:21 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	check_extention(char *filename)
{
	char	*extention;

	extention = ft_substr(filename, ft_strlen(filename) - 3, 3);
	if (ft_strncmp(extention, ".rt", 3))
	{
		printf("Error\nfile extention not valid\n");
		free(extention);
		exit(1);
	}
	free(extention);
}

int	exitit(int button, void *unused)
{
	button = 1;
	exit (0);
}

void	failure_exit(char *message)
{
	printf("Error\n");
	if (message)
		printf("%s\n", message);
	exit(1);
}
