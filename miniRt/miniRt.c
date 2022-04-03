/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:34:33 by mel-amma          #+#    #+#             */
/*   Updated: 2022/04/03 20:56:03 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

int	exitit(int button, void *unused)
{
	button = 1;
	exit(0);
	return (0);
}

void failure_exit(char *message)
{
	//free stuff
	printf("Error\n");
	if(message)
	printf("%s\n",message);
	exit(1);
}

void	put_menu(t_parameters *param)
{
	/*
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 15, 130140150, "Rotate around (x,y,z): A-W-D");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 30, 130140150, "Reverse rotate around (x,y,z): UP-RIGHT-LEFT");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 45, 130140150, "Zoom : + -");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 60, 130140150, "Shift : I-J-K-L");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 75, 130140150, "Swap projection: / *");
		*/
}

void	initializemlx(t_parameters *param)
{
	param->mlx_ptre = mlx_init();
	param->win_ptre = mlx_new_window(param->mlx_ptre,
			WINDOW_WIDTH, WINDOW_HEIGHT, "mi ferst windew");
	param->img_ptre = mlx_new_image(param->mlx_ptre, WINDOW_WIDTH, WINDOW_HEIGHT);
	param->address = mlx_get_data_addr(param->img_ptre,
			&param->bitsperpixel, &param->linesize, &param->endian);

}


int esc_hook(int button, void *param)
{
if (button == 53 || button == 17)
	{
		// freestuff(hooker);
		exit(0);
	}
	return(0);
}

int	main(int argc, char **argv)
{	
	t_parameters		*param;

	//error handling

	//init
	param = malloc(sizeof(t_parameters));
	initializemlx(param);

	//for all keys
	mlx_hook(param->win_ptre, 02, 0L, esc_hook, param /*(the parameter)*/);
	
	//for closin window
	mlx_hook(param->win_ptre, 17, 0L, exitit, param /*(the parameter)*/);
	
	
	put_menu(param);
	mlx_loop(param->mlx_ptre);


	return (0);
}
