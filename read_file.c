/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:48:36 by jvasseur          #+#    #+#             */
/*   Updated: 2023/01/18 15:46:11 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verifmap(t_data *data)
{
	data->i = 0;
	while (data->str[data->i])
	{
		data->j = 0;
		while (data->str[data->i][data->j])
		{
			if (data->str[data->i][data->j] == 'C')
				return (0);
			data->j++;
		}
		data->i++;
	}
	return (1);
}

void	verifexit(char *str, t_data *data)
{
	if (verifbackslashn(str) == 0)
	{
		free(str);
		free(data);
		exit (0);
	}
}

char	**create_map(int fd, t_data *data)
{
	char	*tmp;
	char	*tmp2;
	char	*str;
	char	**result;

	str = ft_calloc(1, 1);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
		{
			break ;
			free(tmp);
		}
		tmp2 = str;
		str = ft_strjoin(tmp2, tmp);
		verifexit(str, data);
		free(tmp);
		free(tmp2);
	}
	result = ft_split(str, '\n');
	free(str);
	return (result);
}
