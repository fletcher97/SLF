/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:09:47 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/17 18:05:07 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "game.h"
#include "gui.h"
#include "map.h"

int is_fireball(char c)
{
	return (c == FIREBALL_U || c == FIREBALL_D || c == FIREBALL_L || c == FIREBALL_R);
}

int dir_fireball(char c)
{
	if (c == FIREBALL_D)
		return (0);
	if (c == FIREBALL_L)
		return (1);
	if (c == FIREBALL_U)
		return (2);
	if (c == FIREBALL_R)
		return (3);
	return (-1);
}

static int move(t_enemy *e, t_game *g)
{
	int i, j;
	int new;
	int dir;

	j = -1;
	while (++j < 4)
	{
		i = j == 2 ? -1 : j == 3 ? 2 : j;
		dir = e->dir + i;
		dir = dir >= 4 ? dir - 4 : dir < 0 ? dir + 4 : dir;
		printf("dir: %d\n", dir);
		if (dir == 0)
			new = e->y + 1;
		else if (dir == 1)
			new = e->x - 1;
		else if (dir == 2)
			new = e->y - 1;
		else if (dir == 3)
			new = e->x + 1;
		if (dir % 2)
		{
			if (new < 0 || new >= g->width)
				continue ;
			if (!is_solid(g->map[e->y][new])){
				e->dir = dir;
				e->x = new;
				return 1;
			}
		}
		else
		{
			if (new < 0 || new >= g->height)
				continue ;
			if (!is_solid(g->map[new][e->x])){
				e->dir = dir;
				e->y = new;
				return 1;
			}
		}
	}
	return 0;
}

int update_fireball(void *g, void *e)
{
	t_game *game;
	t_enemy *enemy;
	game = (t_game *)g;
	enemy = (t_enemy *)e;
	if (enemy->x == game->player.x && enemy->y == game->player.y)
	{
		game->player.dead = 1;
		return 1;
	}
	if (move(enemy, game)) {
		if (enemy->x == game->player.x && enemy->y == game->player.y)
			game->player.dead = 1;
	}
	return 1;
}

int render_fireball(void *g, void *enemy)
{
	t_app *app;
	t_enemy *e;
	int x, y;
	const int tile_id = 53;

	app = (t_app*)g;
	e = (t_enemy *)enemy;
	x = e->x + (4 - app->game.player.x);
	y = e->y + (4 - app->game.player.y);
	if (x < 0 || x >= 9 || y < 0 || y >= 9)
		return 0;
	put_tile(&app->screen, x, y, tile_id);
	return 1;
}
