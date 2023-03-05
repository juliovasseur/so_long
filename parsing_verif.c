/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:20:16 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/05 14:51:20 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position(char ***str, int *i, int *j)
{
	(*i) = 0;
	while ((*str)[*i])
	{
		(*j) = 0;
		while ((*str)[*i][*j])
		{
			if ((*str)[*i][*j] == 'P')
			{
				(*str)[*i][*j] = '2';
				return ;
			}
			(*j)++;
		}
		(*i)++;
	}
}

char	**flood_fill(char **str)
{
	int	i;
	int	j;

	position(&str, &i, &j);
	if (str[i + 1][j] == 'C' || str[i + 1][j] == '0' || str[i + 1][j] == 'E')
	{
		str[i + 1][j] = 'P';
		flood_fill(str);
	}
	if (str[i][j - 1] == 'C' || str[i][j - 1] == '0' || str[i][j - 1] == 'E')
	{
		str[i][j - 1] = 'P';
		flood_fill(str);
	}
	if (str[i][j + 1] == 'C' || str[i][j + 1] == '0' || str[i][j + 1] == 'E')
	{
		str[i][j + 1] = 'P';
		flood_fill(str);
	}
	if (str[i - 1][j] == 'C' || str[i - 1][j] == '0' || str[i - 1][j] == 'E')
	{
		str[i - 1][j] = 'P';
		flood_fill(str);
	}
	return (str);
}

int	check_twomap(char **map)
{
	int		i;
	int		j;
	char	**map2;

	i = 0;
	map2 = flood_fill(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == '0' ||
				map[i][j] == 'E' || map[i][j] == 'P')
			{
				if (map2[i][j] != 2)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	checkfull(int argc, char **argv, t_data *data)
{
	int		fd;
	char	**str;

	nbargc(argc);
	if (argc != 2)
		return (0);
	if (checkber(argv[1]) == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nmap not exist or unavaible");
		return (0);
	}
	str = create_map(fd, data);
	close(fd);
	if (fullcheck(str) == 0)
	{
		write(1, "Error\n", 7);
		fullchecktwo(str);
		free_split(str);
		return (0);
	}
	free_split(str);
	return (1);
}
