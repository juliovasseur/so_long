/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runmap_and_verif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:19:10 by jvasseur          #+#    #+#             */
/*   Updated: 2023/01/18 15:45:55 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	height(char **argv, t_data *data)
{
	char	**tab;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	tab = create_map(fd, data);
	while (tab[i])
		i++;
	free_split(tab);
	return (i);
}

int	weight(char **argv, t_data *data)
{
	char	**tab;
	int		fd;
	int		i;
	int		j;

	j = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	tab = create_map(fd, data);
	while (tab[0][j])
		j++;
	free_split(tab);
	return (j);
}

void	positionp(t_data *data)
{
	data->i = 0;
	while (data->str[data->i])
	{
		data->j = 0;
		while (data->str[data->i][data->j])
		{
			if (data->str[data->i][data->j] == 'P')
			{
				data->posx = data->i * 64;
				data->posy = data->j * 64;
				return ;
			}
			data->j++;
		}
		data->i++;
	}
	data->k = 0;
}

void	helpmap(t_data *data)
{
	if (data->str[data->i][data->j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[0], data->e, data->k);
	else if (data->str[data->i][data->j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[1], data->e, data->k);
	else if (data->str[data->i][data->j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[2], data->e, data->k);
	else if (data->str[data->i][data->j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[3], data->e, data->k);
	else if (data->str[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[4], data->e, data->k);
}

void	runmap(t_data *data)
{
	fileimage(data);
	data->i = 0;
	data->e = 0;
	data->k = 0;
	while (data->str[data->i])
	{
		data->j = 0;
		data->e = 0;
		while (data->str[data->i][data->j])
		{
			helpmap(data);
			data->e += 64;
			data->j++;
		}
		data->k += 64;
		data->i++;
	}
}
