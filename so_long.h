/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:30:33 by jvasseur          #+#    #+#             */
/*   Updated: 2023/01/18 15:59:37 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include<string.h>
# include<stdlib.h>
# include<unistd.h>
# include<stddef.h>
# include<limits.h>
# include<fcntl.h>
# include "Libft/libft.h"

typedef struct s_data {
	void	*mlx;
	void	**img;
	void	*win;
	char	**str;
	int		posx;
	int		posy;
	int		fd;
	int		i;
	int		j;
	int		cpt;
	int		e;
	int		k;
}				t_data;

int		fullcheck(char **str);
int		check_map_wall(char **str);
int		check_consumable(char **str, char c);
int		check_map_wall(char **str);
int		existing_letter(char **str);
char	**create_map(int fd, t_data *data);
int		check_twomap(char **map);
int		check_rectangle(char **str);
int		cpt_nbline(char **str);
int		cpt_line(char **str);
char	**flood_fill(char **str);
int		checkber(char *str);
int		checkfull(int argc, char **argv, t_data *data);
void	fullchecktwo(char **str);
void	up(t_data *data);
void	left(t_data *data);
void	down(t_data *data);
void	rigth(t_data *data);
int		verifmap(t_data *data);
int		height(char **argv, t_data *data);
int		weight(char **argv, t_data *data);
void	positionp(t_data *data);
void	runmap(t_data *data);
void	fileimage(t_data *data);
int		destroy(t_data *data);
void	free_split(char **tab);
int		verifbackslashn(char *str);
void	nbargc(int argc);
void	freeall(t_data *data);

#endif
