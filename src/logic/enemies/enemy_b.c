/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:09:47 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/13 20:57:22 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "game.h"
#include "gui.h"
#include "map.h"

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

int update_b(void *g, void *e)
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

int render_b(void *g, int x, int y)
{
	t_app *app;

	app = (t_app*)g;
	if (x < 0 || x >= 9 || y < 0 || y >= 9)
		return 0;
	put_tile(&app->screen, x, y, 34);
	return 1;
}
