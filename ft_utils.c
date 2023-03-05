/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:12:00 by jvasseur          #+#    #+#             */
/*   Updated: 2023/01/18 15:56:39 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verifbackslashn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\n')
			{
				ft_printf("Error\nmap unvaible");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	nbargc(int argc)
{
	if (argc != 2)
		ft_printf("Error\nno enough argument");
}

void	free_splitdata(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free((*str));
}

void	freeall(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img[0]);
	mlx_destroy_image(data->mlx, data->img[1]);
	mlx_destroy_image(data->mlx, data->img[2]);
	mlx_destroy_image(data->mlx, data->img[3]);
	mlx_destroy_image(data->mlx, data->img[4]);
	free(data->img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_splitdata(&data->str);
	free(data);
	exit(0);
}
