/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jaws.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:09:47 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/17 16:25:33 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "game.h"
#include "gui.h"
#include "map.h"

int is_jaws(char c)
{
	return (c == JAWS_D || c == JAWS_U || c == JAWS_L || c == JAWS_R);
}

int dir_jaws(char c)
{
	if (c == JAWS_D)
		return (0);
	if (c == JAWS_L)
		return (1);
	if (c == JAWS_U)
		return (2);
	if (c == JAWS_R)
		return (3);
	return (-1);
}

static int move(t_enemy *e, t_game *g)
{
	int i;
	int new;

	i = -2;
	while (++i < 3)
	{
		if ((e->dir + i) % 4 == 0)
			new = e->x + 1;
		else if ((e->dir + i) % 4 == 1)
			new = e->y - 1;
		else if ((e->dir + i) % 4 == 2)
			new = e->x - 1;
		else if ((e->dir + i) % 4 == 3)
			new = e->y + 1;
		if ((e->dir + i) % 2)
		{
			if (new < 0 || new >= g->height)
				continue ;
			if (g->map[new][e->x] == VOID){
				e->dir = (e->dir + i) % 4;
				e->y = new;
				return 1;
			}
		}
		else
		{
			if (new < 0 || new >= g->width)
				continue ;
			if (g->map[e->y][new] == VOID){
				e->dir = (e->dir + i) % 4;
				e->x = new;
				return 1;
			}
		}
	}
	return 0;
}

//TODO: move to spider
int update_jaws(void *g, void *e)
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
	if (move(enemy, game)){
		if (enemy->x == game->player.x && enemy->y == game->player.y)
		{
			game->player.dead = 1;
			return 1;
		}
	}
	return 1;
}

int render_jaws(void *g, void *enemy)
{
	t_app *app;
	t_enemy *e;
	int x, y;
	const int tile_id = 68;

	app = (t_app*)g;
	e = (t_enemy *)enemy;
	x = e->x + (4 - app->game.player.x);
	y = e->y + (4 - app->game.player.y);
	if (x < 0 || x >= 9 || y < 0 || y >= 9)
		return 0;
	put_tile(&app->screen, x, y, tile_id + e->dir);
	return 1;
}
