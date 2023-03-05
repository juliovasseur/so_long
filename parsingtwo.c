/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingtwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:32:08 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/05 15:06:40 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_rectangle(char **str)
{
	int	i;
	int	j;
	int	cpt;
	int	cpttwo;

	i = 0;
	cpt = ft_strlen(str[0]);
	if (cpt == 0)
		return (0);
	while (str[i])
	{
		j = 0;
		cpttwo = 0;
		while (str[i][j])
		{
			cpttwo++;
			j++;
		}
		if (cpt != cpttwo)
			return (0);
		i++;
	}
	return (1);
}

int	checkber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i == 4)
	{
		ft_printf("Error\nname of the map invalide");
		return (0);
	}
	if (str[i - 4] != '.' || str[i - 3] != 'b'
		|| str[i - 2] != 'e' || str[i - 1] != 'r')
	{
		ft_printf("Error\nname of the map invalide");
		return (0);
	}
	return (1);
}

int	fullcheck(char **str)
{
	if (check_rectangle(str) == 0)
		return (0);
	else if (check_consumable(str, 'E') != 1)
		return (0);
	else if (check_consumable(str, 'P') != 1)
		return (0);
	else if (check_consumable(str, 'C') < 1)
		return (0);
	else if (existing_letter(str) == 0)
		return (0);
	else if (check_map_wall(str) == 0)
		return (0);
	else if (check_twomap(str) == 0)
		return (0);
	return (1);
}

void	fullchecktwo(char **str)
{
	if (check_rectangle(str) == 0)
		ft_printf("your map is not rectangle");
	else if (check_consumable(str, 'E') != 1)
		ft_printf("your map dont have letter E");
	else if (check_consumable(str, 'P') != 1)
		ft_printf("your map dont have letter P");
	else if (check_consumable(str, 'C') < 1)
		ft_printf("your map dont have letter C");
	else if (existing_letter(str) == 0)
		ft_printf("your map contains an invalid character");
	else if (check_map_wall(str) == 0)
		ft_printf("your map must be completely closed off by walls");
	else if (check_twomap(str) == 0)
		ft_printf("your map is not possible");
}
