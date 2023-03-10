/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:28:12 by jvasseur          #+#    #+#             */
/*   Updated: 2022/11/05 15:10:30 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int,
char*))
{
	int	cpt;

	cpt = 0;
	if (s)
	{
		while (s[cpt])
		{
			(*f)(cpt, s + cpt);
			cpt++;
		}
	}
}
