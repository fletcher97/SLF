/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:08:35 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/16 15:43:31 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "game.h"
#include "map.h"
#include "gui.h"

static int can_walk(int x, int y, t_game *g)
{
	if (!is_solid(g->map[y][x]))
		return (1);
	if (g->map[y][x] == GATE && !g->coll_left)
		return (1);
	if (g->map[y][x] == RDOOR && g->player.inv.rkey)
		return (1);
	if (g->map[y][x] == GDOOR && g->player.inv.gkey)
		return (1);
	if (g->map[y][x] == BDOOR && g->player.inv.bkey)
		return (1);
	if (g->map[y][x] == YDOOR && g->player.inv.ykey)
		return (1);
	return (0);
}

void update_player(t_game *g)
{
	int new_x;
	int new_y;

	new_x = g->player.x + g->player.x_mov;
	new_y = g->player.y + g->player.y_mov;
	if (new_x != g->player.x && new_x >= 0 && new_x < g->width && can_walk(new_x, g->player.y, g))
	{
		g->player.dir = new_x > g->player.x ? 3 : 1;
		g->player.x = new_x;
	}
	else if (new_y != g->player.y && new_y >= 0 && new_y < g->height && can_walk(g->player.x, new_y, g))
	{
		g->player.dir = new_y > g->player.y ? 0 : 2;
		g->player.y = new_y;
	}
	if (g->map[g->player.y][g->player.x] == CHIP)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->coll_left--;
		printf("%d left\n", g->coll_left);
	}
	else if (g->map[g->player.y][g->player.x] == EXIT)
	{
		printf("You  won!!!\n");
		g->player.dead = 2;
	}
	else if (g->map[g->player.y][g->player.x] == GATE && !g->coll_left)
	{
		g->map[g->player.y][g->player.x] = VOID;
	}
	else if (g->map[g->player.y][g->player.x] == RDOOR && g->player.inv.rkey)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.rkey--;
	}
	else if (g->map[g->player.y][g->player.x] == GDOOR && g->player.inv.gkey)
	{
		g->map[g->player.y][g->player.x] = VOID;
	}
	else if (g->map[g->player.y][g->player.x] == BDOOR && g->player.inv.bkey)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.bkey--;
	}
	else if (g->map[g->player.y][g->player.x] == YDOOR && g->player.inv.ykey)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.ykey--;
	}
	else if (g->map[g->player.y][g->player.x] == RKEY)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.rkey++;
	}
	else if (g->map[g->player.y][g->player.x] == GKEY)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.gkey = 1;
	}
	else if (g->map[g->player.y][g->player.x] == BKEY)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.bkey++;
	}
	else if (g->map[g->player.y][g->player.x] == YKEY)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.ykey++;
	}
}

void render_player(t_app *a)
{
	put_tile(&a->screen, 4, 4, a->game.player.dir);
}
