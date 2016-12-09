/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:41:00 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/07 15:40:23 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

# define SUCCESS 0
# define ARGUMENT 1
# define OPEN 2
# define READ 3
# define MALLOC 4
# define TETRIMINOS 5
# define MAP_ERROR 6

# define BUF_SIZE 546

# define BUF fillit->buf
# define HEIGHT fillit->height
# define WIDTH fillit->width
# define MAP fillit->map

typedef struct	s_fillit
{
	int			pieces;
	int			fd;
	int			height;
	int			width;
	size_t		faulty_piece;
	size_t		line;
	char		*buf;
	char		***map;
	int			x;
	int			y;
}				t_fillit;

void			ft_error(t_fillit *fillit, int error);
t_fillit		*get_map(t_fillit *fillit);
int				checkbuf(t_fillit *fillit);

#endif
