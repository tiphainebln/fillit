/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:43:06 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/07 15:35:40 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void				free_pointers(t_fillit *fillit)
{
	int		i;
	int		j;

	i = 0;
	if (MAP)
	{
		while (MAP[i])
		{
			j = 0;
			while (MAP[i][j])
			{
				free(MAP[i][j]);
				MAP[i][j++] = NULL;
			}
			free(MAP[i]);
			MAP[i++] = NULL;
		}
		free(MAP);
		MAP = NULL;
	}
	if (BUF)
	{
		free(BUF);
		BUF = NULL;
	}
}

static void				exit_fillit(t_fillit *fillit, int error)
{
	if (fillit)
	{
		free_pointers(fillit);
		free(fillit);
	}
	exit(error);
}

void					ft_error(t_fillit *fillit, int error)
{
	if (error == ARGUMENT)
		ft_putendl_fd("Usage: ./fillit [tetriminos source file]", 2);
	else if (error == OPEN)
		ft_putendl_fd("open failed", 2);
	else if (error == READ)
		ft_putendl_fd("read failed", 2);
	else if (error == MALLOC)
		ft_putendl_fd("malloc error", 2);
	else if (error == TETRIMINOS)
	{
		ft_putnbr_fd(fillit->faulty_piece, 2);
		ft_putendl_fd(" is an invalid tetrimino", 2);
	}
	else if (error == MAP_ERROR)
		ft_putendl_fd("invalid map", 2);
	exit_fillit(fillit, error);
}
