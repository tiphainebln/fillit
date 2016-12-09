/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:49:08 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/07 16:18:49 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_valid(t_fillit *fillit, size_t i)
{
	if (fillit->line == 0)
	{
		if (BUF[i + 1] == '#' || (i > 0 && BUF[i - 1] == '#') || \
			BUF[i + 5] == '#')
			return (0);
	}
	if (fillit->line == 3)
	{
		if (BUF[i + 1] == '#' || BUF[i - 1] == '#' || BUF[i - 5] == '#')
			return (0);
	}
	if (fillit->line > 0 && fillit->line < 3)
	{
		if (BUF[i + 1] == '#' || BUF[i - 1] == '#' || BUF[i + 5] == '#' || \
				BUF[i - 5] == '#')
			return (0);
	}
	return (-1);
}

static int		check_char(t_fillit *fillit, size_t i)
{
	int		key;

	key = 0;
	while (BUF[i] != '\0')
	{
		fillit->faulty_piece = (i / 21) + 1;
		key = (BUF[i] == '#') ? key + 1 : key;
		if (BUF[i] == '#')
			if (is_valid(fillit, i) == -1)
				ft_error(fillit, TETRIMINOS);
		if (BUF[i] == '\n' && (BUF[i + 1] == '\n' || BUF[i + 1] == '\0'))
		{
			if (key != 4)
				ft_error(fillit, TETRIMINOS);
			key = 0;
			fillit->line = 0;
		}
		else if (BUF[i] == '\n' && BUF[i - 1] != '\n')
			fillit->line++;
		i++;
	}
	return (0);
}

static int		check(t_fillit *fillit, size_t i, size_t count)
{
	while (BUF[i++])
	{
		WIDTH++;
		fillit->faulty_piece = i / 21;
		if (BUF[i - 1] != '\n' && BUF[i - 1] != '.' && BUF[i - 1] != '#')
			ft_error(fillit, MAP_ERROR);
		if (BUF[i - 1] == '\n' && WIDTH != 5 && HEIGHT != 4)
			ft_error(fillit, TETRIMINOS);
		if (HEIGHT == 4)
		{
			if (BUF[i] != '.' && BUF[i] != '#')
				ft_error(fillit, TETRIMINOS);
			count++;
			HEIGHT = 0;
			WIDTH = 0;
		}
		if (WIDTH == 5)
		{
			if (BUF[i - 1] != '\n')
				ft_error(fillit, TETRIMINOS);
			HEIGHT++;
			WIDTH = 0;
		}
	}
	return ((count > 26 || check_char(fillit, 0) != 0) ? -1 : count);
}

int				checkbuf(t_fillit *fillit)
{
	if (!BUF)
		ft_error(fillit, MAP_ERROR);
	return (check(fillit, 0, 1));
}
