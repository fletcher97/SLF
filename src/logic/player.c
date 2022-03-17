/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:08:35 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/17 10:42:38 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "game.h"
#include "map.h"
#include "gui.h"

static int is_ice(t_game *g, int x, int y)
{
	char c;

	c = g->map[y][x];
	return (c == ICE || c == CUR || c == CRD || c == CDL || c == CLU);
}

static int can_walk(int x, int y, t_game *g)
{
	int dir;

	dir = -1;
	if (x != g->player.x)
		dir = x > g->player.x ? 3 : 1;
	else if (y != g->player.y)
		dir = y > g->player.y ? 0 : 2;
	if (dir >= 0 && (is_ice(g, x, y) || is_ice(g, g->player.x, g->player.y)))
	{
		if (g->map[y][x] == CDL && (dir == 2 || dir == 3))
			return (1);
		if (g->map[y][x] == CLU && (dir == 0 || dir == 3))
			return (1);
		if (g->map[y][x] == CUR && (dir == 0 || dir == 1))
			return (1);
		if (g->map[y][x] == CRD && (dir == 2 || dir == 1))
			return (1);
		if (!is_solid(g->map[y][x]))
		{
			if (g->map[g->player.y][g->player.x] == CDL && (dir == 0 || dir == 1))
				return (1);
			if (g->map[g->player.y][g->player.x] == CLU && (dir == 2 || dir == 1))
				return (1);
			if (g->map[g->player.y][g->player.x] == CUR && (dir == 2 || dir == 3))
				return (1);
			if (g->map[g->player.y][g->player.x] == CRD && (dir == 0 || dir == 3))
				return (1);
			if (g->map[g->player.y][g->player.x] == CRD || g->map[g->player.y][g->player.x] == CDL
				|| g->map[g->player.y][g->player.x] == CLU || g->map[g->player.y][g->player.x] == CUR)
				return (0);
		}
	}
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

void proc_doors(t_game *g)
{
	if (g->map[g->player.y][g->player.x] == RDOOR && g->player.inv.rkey)
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
}

void proc_items(t_game *g)
{
	if (g->map[g->player.y][g->player.x] == RKEY)
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
	else if (g->map[g->player.y][g->player.x] == IBOOT)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.boots |= ICE_BOOT;
	}
	else if (g->map[g->player.y][g->player.x] == PBOOT)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.boots |= PUSH_BOOT;
	}
	else if (g->map[g->player.y][g->player.x] == FBOOT)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.boots |= FIRE_BOOT;
	}
	else if (g->map[g->player.y][g->player.x] == WBOOT)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->player.inv.boots |= WATER_BOOT;
	}
}

int proc_push(t_game *g)
{
	if (g->player.inv.boots & PUSH_BOOT)
		return (0);
	if (g->map[g->player.y][g->player.x] == PUP && can_walk(g->player.x, g->player.y - 1, g))
	{
		g->player.y--;
		g->player.dir = 2;
	}
	else if (g->map[g->player.y][g->player.x] == PDOWN && can_walk(g->player.x, g->player.y + 1, g))
	{
		g->player.y++;
		g->player.dir = 0;
	}
	else if (g->map[g->player.y][g->player.x] == PLEFT && can_walk(g->player.x - 1, g->player.y, g))
	{
		g->player.x--;
		g->player.dir = 1;
	}
	else if (g->map[g->player.y][g->player.x] == PRIGHT && can_walk(g->player.x + 1, g->player.y, g))
	{
		g->player.x++;
		g->player.dir = 3;
	}
	else
		return (0);
	return (1);
}

void ice_change_dir(t_game *g)
{
	if (g->map[g->player.y][g->player.x] == CDL)
	{
		g->player.y_ice = g->player.y_ice ? 0 : 1;
		g->player.x_ice = g->player.x_ice ? 0 : -1;
		g->player.dir = g->player.dir == 2 ? 1 : 0;
	}
	else if (g->map[g->player.y][g->player.x] == CLU)
	{
		g->player.y_ice = g->player.y_ice ? 0 : -1;
		g->player.x_ice = g->player.x_ice ? 0 : -1;
		g->player.dir = g->player.dir == 3 ? 2 : 1;
	}
	else if (g->map[g->player.y][g->player.x] == CUR)
	{
		g->player.y_ice = g->player.y_ice ? 0 : -1;
		g->player.x_ice = g->player.x_ice ? 0 : 1;
		g->player.dir = g->player.dir == 0 ? 3 : 2;
	}
	else if (g->map[g->player.y][g->player.x] == CRD)
	{
		g->player.y_ice = g->player.y_ice ? 0 : 1;
		g->player.x_ice = g->player.x_ice ? 0 : 1;
		g->player.dir = g->player.dir == 1 ? 0 : 3;
	}
}

int proc_ice(t_game *g)
{
	if (g->player.inv.boots & ICE_BOOT)
		return (0);
	if (!is_ice(g, g->player.x, g->player.y))
	{
		g->player.x_ice = 0;
		g->player.y_ice = 0;
		return (0);
	}
	else if (!g->player.x_ice && !g->player.y_ice)
	{
		g->player.x_ice = g->player.x_mov;
		if (!g->player.x_ice)
			g->player.y_ice = g->player.y_mov;
		return (0);
	}

	if (g->map[g->player.y][g->player.x] == ICE && can_walk(g->player.x + g->player.x_ice, g->player.y + g->player.y_ice, g))
	{
		g->player.x += g->player.x_ice;
		g->player.y += g->player.y_ice;
	}
	else if (g->map[g->player.y][g->player.x] == ICE)
	{
		g->player.x_ice = -g->player.x_ice;
		g->player.y_ice = -g->player.y_ice;
		g->player.dir = (g->player.dir + 2) % 4;
		g->player.x += g->player.x_ice;
		g->player.y += g->player.y_ice;
	}
	else
	{
		ice_change_dir(g);
		if (!can_walk(g->player.x + g->player.x_ice, g->player.y + g->player.y_ice, g))
			ice_change_dir(g);
		g->player.x += g->player.x_ice;
		g->player.y += g->player.y_ice;
	}
	return (1);
}

void update_player(t_game *g)
{
	int new_x;
	int new_y;
	static char f = 0;

	new_x = g->player.x + g->player.x_mov;
	new_y = g->player.y + g->player.y_mov;
	if (f)
		f = (f + 1) % 3;
	if (!f && proc_push(g))
	{
		f = 1;
	}
	else if (new_x != g->player.x && new_x >= 0 && new_x < g->width && can_walk(new_x, g->player.y, g) && (!is_ice(g, g->player.x, g->player.y) || g->player.inv.boots & ICE_BOOT))
	{
		g->player.dir = new_x > g->player.x ? 3 : 1;
		g->player.x = new_x;
		proc_ice(g);
	}
	else if (new_y != g->player.y && new_y >= 0 && new_y < g->height && can_walk(g->player.x, new_y, g) && (!is_ice(g, g->player.x, g->player.y) || g->player.inv.boots & ICE_BOOT))
	{
		g->player.dir = new_y > g->player.y ? 0 : 2;
		g->player.y = new_y;
		proc_ice(g);
	}
	else if (f != 1)
		if (!proc_push(g))
			proc_ice(g);

	// collect chips
	if (g->map[g->player.y][g->player.x] == CHIP)
	{
		g->map[g->player.y][g->player.x] = VOID;
		g->coll_left--;
		printf("%d left\n", g->coll_left);
	}
	// exit level
	else if (g->map[g->player.y][g->player.x] == EXIT)
	{
		printf("You  won!!!\n");
		g->player.dead = 2;
	}
	// open gate
	else if (g->map[g->player.y][g->player.x] == GATE && !g->coll_left)
	{
		g->map[g->player.y][g->player.x] = VOID;
	}
	else
	{
		// open doors
		proc_doors(g);
		// collect key
		proc_items(g);

	}
}

void render_player(t_app *a)
{
	put_tile(&a->screen, 4, 4, a->game.player.dir + 4);
}
