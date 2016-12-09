/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:42:50 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/07 12:27:47 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit		*get_map(t_fillit *fillit)
{
	int i;

	i = -1;
	if (!(MAP = (char ***)malloc(sizeof(char **) * fillit->pieces + 1)))
	{
		ft_error(fillit, MALLOC);
		return (NULL);
	}
	while (++i < fillit->pieces)
	{
		if (!(MAP[i] = ft_strsplit(ft_strsub(BUF, i * 21, 21), '\n')))
		{
			ft_error(fillit, MALLOC);
			return (NULL);
		}
	}
	MAP[i] = NULL;
	return (fillit);
}
