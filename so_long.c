/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:20:37 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/05 17:01:55 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fileimage(t_data *data)
{
	int	img_width;
	int	img_height;

	img_height = 64;
	img_width = 64;
	data->img[0] = mlx_xpm_file_to_image(data->mlx, "sprites/grass.xpm",
			&img_width, &img_height);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "sprites/baobab.xpm",
			&img_width, &img_height);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "sprites/banana.xpm",
			&img_width, &img_height);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "sprites/monkey.xpm",
			&img_width, &img_height);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "sprites/cavern.xpm",
			&img_width, &img_height);
}

int	destroy(t_data *data)
{
	freeall(data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{	
	if (keycode == 65307)
		destroy(data);
	if (keycode == 0x77)
		up(data);
	if (keycode == 0x61)
		left(data);
	if (keycode == 0x73)
		down(data);
	if (keycode == 0x64)
		rigth(data);
	return (0);
}

int	graph(char **argv, int h, int w, t_data *data)
{
	data->fd = open(argv[1], O_RDONLY);
	data->str = create_map(data->fd, data);
	close(data->fd);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (w * 64), (h * 64), "So_long");
	positionp(data);
	data->img = malloc(sizeof(void *) * 5);
	runmap(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 1L << 0, destroy, data);
	mlx_loop(data->mlx);
	freeall(data);
	return (1);
}

int	main(int argc, char **argv)
{
	int		h;
	int		w;
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->cpt = 0;
	data->i = 0;
	data->k = 0;
	if (checkfull(argc, argv, data) == 0)
	{
		free(data);
		return (0);
	}
	h = height(argv, data);
	w = weight(argv, data);
	graph(argv, h, w, data);
}
