/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:09:47 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/17 15:59:55 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "game.h"
#include "gui.h"
#include "map.h"

int is_tank(char c)
{
	return (c == TANK_D || c == TANK_U || c == TANK_L || c == TANK_R);
}

int dir_tank(char c)
{
	if (c == TANK_D)
		return (0);
	if (c == TANK_L)
		return (1);
	if (c == TANK_U)
		return (2);
	if (c == TANK_R)
		return (3);
	return (-1);
}

int update_tank(void *g)
{
	(void)g;
	//printf("Update a\n");
	return 1;
}

int render_tank(void *g, void *enemy)
{
	t_app *app;
	t_enemy *e;
	int x, y;
	const int tile_id = 44;

	app = (t_app*)g;
	e = (t_enemy *)enemy;
	x = e->x + (4 - app->game.player.x);
	y = e->y + (4 - app->game.player.y);
	if (x < 0 || x >= 9 || y < 0 || y >= 9)
		return 0;
	put_tile(&app->screen, x, y, tile_id + e->dir);
	return 1;
}
