/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:17:41 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/17 15:38:39 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "ft_string.h"
#include "ft_conv.h"
#include "ft_stdlib.h"

#include "logic.h"
#include "gui.h"
#include "map.h"
#include <stdio.h>
#include <math.h>

void	get_screen(t_app *app)
{
	app->screen.height = IMG_SIZE * 9 * SCALE;
	app->screen.width = IMG_SIZE * (9 + 3) * SCALE;
	app->screen.title = ft_strdup("chips");
}

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (color == 0xffc0ff)
		return ;
	int a = 0;
	for (int i = 0; i < SCALE; i++)
		for (int j = 0; j < SCALE; j++)
		{
			a++;
			dst = img->addr + ((y + i) * img->line + (x + j) * (img->bpp / 8));
			*(unsigned int *)dst = color;
		}
}

static void	get_color(t_img *img, int x, int y, int *color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*color = *(unsigned int *)dst;
}

void	put_tile(t_screen *screen, int x, int y, int id)
{
	int		i;
	int		j;
	int		tx;
	int		ty;
	t_img	*tiles;

	i = -1;
	tiles = screen->tiles;
	while (++i < IMG_SIZE)
	{
		j = -1;
		while (++j < IMG_SIZE) {
			tx = (id % 8) * IMG_SIZE + j;
			ty = (id / 8) * IMG_SIZE + i;
			int color;
			get_color(tiles, tx, ty, &color);
			my_mlx_pixel_put(screen->img[1], x * IMG_SIZE  * SCALE + j * SCALE, y * IMG_SIZE  * SCALE + i * SCALE,
				color);
		}
	}
}

void	render_enteties(t_app *app)
{
	t_list *enemies;
	t_enemy *enemy;

	enemies = app->game.enemy;
	while (enemies)
	{
		enemy = (t_enemy*)enemies->content;
		enemy->render(app, enemy);
		enemies = enemies->next;
	}
	render_player(app);
}

static void	put_tile_offset(t_screen *screen, int x, int y, int id)
{
	int		i;
	int		j;
	int		tx;
	int		ty;
	t_img	*tiles;

	i = -1;
	tiles = screen->tiles;
	while (++i < IMG_SIZE)
	{
		j = -1;
		while (++j < IMG_SIZE) {
			tx = (id % 8) * IMG_SIZE + j;
			ty = (id / 8) * IMG_SIZE + i;
			int color;
			get_color(tiles, tx, ty, &color);
			my_mlx_pixel_put(screen->img[1],
							(x * IMG_SIZE  * SCALE + j * SCALE) + IMG_SIZE * floor(SCALE/2),
							(y * IMG_SIZE  * SCALE + i * SCALE) + IMG_SIZE * floor(SCALE/2),
							color);
		}
	}
}

static int	get_inv_id(t_app *app, int x, int y)
{
	if (x == 9)
	{
		if (y == 2 && app->game.player.inv.rkey)
			return (get_tile_id(RKEY));
		else if (y == 3 && app->game.player.inv.gkey)
			return (get_tile_id(GKEY));
		else if (y == 4 && app->game.player.inv.bkey)
			return (get_tile_id(BKEY));
		else if (y == 5 && app->game.player.inv.ykey)
			return (get_tile_id(YKEY));
	}
	else if (x == 10)
	{
		if (y == 2 && (app->game.player.inv.boots & ICE_BOOT))
			return (get_tile_id(IBOOT));
		else if (y == 3 && (app->game.player.inv.boots & PUSH_BOOT))
			return (get_tile_id(PBOOT));
		else if (y == 4 && (app->game.player.inv.boots & FIRE_BOOT))
			return (get_tile_id(FBOOT));
		else if (y == 5 && (app->game.player.inv.boots & WATER_BOOT))
			return (get_tile_id(WBOOT));
	}
	return (get_tile_id(VOID));
}


void	render_inventory(t_app *app)
{
	int	i;
	int	j;
	int	id;

	i = 9;
	while (i < 12)
	{
		j = 0;
		while (j < 9)
		{	
			if (i < 11 && j < 6 && j > 1)
			{
				id = get_inv_id(app, i, j);
				put_tile_offset(&app->screen, i, j, id);
			}
			j++;
		}
		i++;
	}
}
	

void	render(t_app *app)
{
	int		i;
	int		j;
	int		mx;
	int		my;
	int		id;
	t_img	*tmp;

	mx = app->game.player.x - 4;
	my = app->game.player.y - 4;
	i = -1;
	(void)id;
	while(++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			if (mx + j < 0 || mx + j >= app->game.width || my + i < 0 || my + i >= app->game.height)
				id = get_tile_id(VOID);
			else
				id = get_tile_id(app->game.map[my + i][mx + j]);
			put_tile(&app->screen, j, i, id);
		}
	}
	render_enteties(app);
	render_inventory(app);
	tmp = app->screen.img[1];
	app->screen.img[1] = app->screen.img[0];
	app->screen.img[0] = tmp;
	mlx_put_image_to_window(app->mlx, app->screen.win, app->screen.img[0]->img, 0, 0);
	mlx_string_put(app->mlx,app->screen.win,
					9 * IMG_SIZE * SCALE + ((IMG_SIZE * SCALE) / 1.5),
					1 * IMG_SIZE * SCALE + floor((IMG_SIZE * SCALE) / 2),
					0xffffff,
					"CHIPS LEFT:");
	char *s = ft_itoa(app->game.coll_left);
	int len = ft_strlen(s);
	mlx_string_put(app->mlx,app->screen.win,
					9 * IMG_SIZE * SCALE + ((IMG_SIZE * SCALE) / 0.75),
					1 * IMG_SIZE * SCALE + floor((IMG_SIZE * SCALE)) - len,
					0xffffff,
					s);
	ft_free(s);
}
