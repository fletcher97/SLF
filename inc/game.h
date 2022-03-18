/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:19:34 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/16 16:58:30 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "ft_list.h"

# include <time.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}				t_img;

typedef struct s_screen
{
	void	*win;
	int		width;
	int		height;
	char	*title;
	t_img	**img;
	t_img	*tiles;
}				t_screen;

typedef struct s_enemy
{
	int x;
	int y;
	int dir;
	int	type;
	int (*update)(void *, void *);
	int (*render)(void *, int, int);
}				t_enemy;

typedef struct s_inventory
{
	char	rkey;
	char	gkey;
	char	bkey;
	char	ykey;
	char	boots;
}				t_inventory;


typedef struct s_player
{
	t_inventory inv;
	int	x;
	int	y;
	int	x_mov;
	int	y_mov;
	int	x_ice;
	int	y_ice;
	int	dir;
	int	dead;
}				t_player;

typedef struct s_game
{
	int			width;
	int			height;
	int			coll_left;
	int			steps;
	char		**map;
	t_player	player;
	t_list		*enemy;
	clock_t		last_tick;
}				t_game;

typedef struct s_app
{
	void		*mlx;
	t_screen	screen;
	t_game		game;
}				t_app;

#endif //GAME_H
