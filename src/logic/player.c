/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:08:35 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/16 14:24:34 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "game.h"
#include "map.h"
#include "gui.h"

void update_player(t_game *p)
{
	int new_x;
	int new_y;

	new_x = p->player.x + p->player.x_mov;
	new_y = p->player.y + p->player.y_mov;
	if (new_x != p->player.x && new_x >= 0 && new_x < p->width && (!is_solid(p->map[p->player.y][new_x]) || (p->map[p->player.y][new_x] == GATE && !p->coll_left)))
	{
		p->player.dir = new_x > p->player.x ? 3 : 1;
		p->player.x = new_x;
	}
	else if (new_y != p->player.y && new_y >= 0 && new_y < p->height && (!is_solid(p->map[new_y][p->player.x]) || (p->map[new_y][p->player.x] == GATE && !p->coll_left)))
	{
		p->player.dir = new_y > p->player.y ? 0 : 2;
		p->player.y = new_y;
	}
	if (p->map[p->player.y][p->player.x] == CHIP)
	{
		p->map[p->player.y][p->player.x] = VOID;
		p->coll_left--;
		printf("%d left\n", p->coll_left);
	}
	else if (p->map[p->player.y][p->player.x] == EXIT)
	{
		printf("You  won!!!\n");
		p->player.dead = 2;
	}
	else if (p->map[p->player.y][p->player.x] == GATE && !p->coll_left)
	{
		p->map[p->player.y][p->player.x] = VOID;
	}
}

void render_player(t_app *a)
{
	put_tile(&a->screen, 4, 4, a->game.player.dir);
}
