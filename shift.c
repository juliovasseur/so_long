/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:15:08 by jvasseur          #+#    #+#             */
/*   Updated: 2023/01/18 15:50:50 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_data *data)
{
	int	t;
	int	p;

	p = data->posx / 64;
	t = data->posy / 64;
	if (data->str[t][p] != 'E')
		data->str[t][p] = '0';
	if (data->str[t - 1][p] == '1')
		return ;
	else if (data->str[t - 1][p] == 'E')
	{
		if (verifmap(data) == 1)
			destroy(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img[0],
		data->posx, data->posy);
	mlx_put_image_to_window(data->mlx, data->win, data->img[3],
		data->posx, data->posy -64);
	data->cpt += 1;
	ft_printf("%d %c", data->cpt, '\n');
	if (data->str[t][p] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img[4],
			data->posx, data->posy);
	data->posy = data->posy - 64;
}

void	left(t_data *data)
{
	int	t;
	int	p;

	p = data->posx / 64;
	t = data->posy / 64;
	if (data->str[t][p] != 'E')
		data->str[t][p] = '0';
	if (data->str[t][p - 1] == '1')
		return ;
	else if (data->str[t][p - 1] == 'E')
	{
		if (verifmap(data) == 1)
			destroy(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img[0],
		data->posx, data->posy);
	mlx_put_image_to_window(data->mlx, data->win, data->img[3],
		data->posx -64, data->posy);
	data->cpt += 1;
	ft_printf("%d %c", data->cpt, '\n');
	if (data->str[t][p] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img[4],
			data->posx, data->posy);
	data->posx = data->posx - 64;
}

void	down(t_data *data)
{
	int	t;
	int	p;

	p = data->posx / 64;
	t = data->posy / 64;
	if (data->str[t][p] != 'E')
		data->str[t][p] = '0';
	if (data->str[t + 1][p] == '1')
		return ;
	else if (data->str[t + 1][p] == 'E')
	{
		if (verifmap(data) == 1)
			destroy(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img[0],
		data->posx, data->posy);
	mlx_put_image_to_window(data->mlx, data->win, data->img[3],
		data->posx, data->posy + 64);
	data->cpt += 1;
	ft_printf("%d %c", data->cpt, '\n');
	if (data->str[t][p] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img[4],
			data->posx, data->posy);
	data->posy = data->posy + 64;
}

void	rigth(t_data *data)
{
	int	t;
	int	p;

	p = data->posx / 64;
	t = data->posy / 64;
	if (data->str[t][p] != 'E')
		data->str[t][p] = '0';
	if (data->str[t][p + 1] == '1')
		return ;
	else if (data->str[t][p + 1] == 'E')
	{
		if (verifmap(data) == 1)
			destroy(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img[0],
		data->posx, data->posy);
	mlx_put_image_to_window(data->mlx, data->win, data->img[3],
		data->posx +64, data->posy);
	data->cpt += 1;
	ft_printf("%d %c", data->cpt, '\n');
	if (data->str[t][p] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img[4],
			data->posx, data->posy);
	data->posx = data->posx + 64;
}
