/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:48:45 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/05 14:51:45 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cpt_line(char **str)
{
	int	j;
	int	cpt;

	cpt = 0;
	j = 0;
	while (str[0][j])
	{
		cpt++;
		j++;
	}
	return (cpt);
}

int	cpt_nbline(char **str)
{
	int	cpt;
	int	i;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		cpt++;
		i++;
	}
	return (cpt);
}

int	check_consumable(char **str, char c)
{
	int	i;
	int	j;
	int	cpt;

	cpt = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				cpt++;
			j++;
		}
		i++;
	}
	return (cpt);
}

int	existing_letter(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'P'
			&& str[i][j] != 'C' && str[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_wall(char **str)
{
	int	i;
	int	j;
	int	tmp;
	int	tmp2;

	tmp2 = cpt_line(str) - 1;
	tmp = cpt_nbline(str) - 1;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][0] != '1' || str[0][j] != '1'
			|| str[tmp][j] != '1' || str[i][tmp2] != '1' )
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
