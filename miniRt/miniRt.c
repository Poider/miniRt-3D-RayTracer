/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:45:49 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/15 15:26:15 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	initializemlx(t_parameters *param)
{
	param->mlx_ptre = mlx_init();
	param->win_ptre = mlx_new_window(param->mlx_ptre, \
		param->camera.hsize, param->camera.vsize, "MINIRT");
	param->img_ptre = mlx_new_image(param->mlx_ptre, \
						param->camera.hsize, param->camera.vsize);
	param->address = mlx_get_data_addr(param->img_ptre, \
					&param->bitsperpixel, &param->linesize, &param->endian);
}

int	esc_hook(int button, void *param)
{
	if (button == 53 || button == 17)
	{
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_camera		camera;
	t_world			world;
	t_parameters	param;
	int				fd;

	if (argc != 2)
		failure_exit("Number argument not valid\n");
	check_extention(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		failure_exit("fail to open file\n");
	parse_file(&world, &camera, fd);
	close (fd);
	if (world.light == NULL || world.objects == NULL)
		failure_exit("Darkness\n");
	param.camera = camera;
	initializemlx(&param);
	render(camera, world, &param);
	free_ressource(&world, &camera);
	mlx_put_image_to_window(param.mlx_ptre, \
			param.win_ptre, param.img_ptre, 0, 0);
	mlx_hook(param.win_ptre, 02, 0L, esc_hook, &param);
	mlx_hook(param.win_ptre, 17, 0L, exitit, &param);
	mlx_loop(param.mlx_ptre);
	return (0);
}
