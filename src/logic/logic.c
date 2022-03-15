/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:10:18 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/13 21:09:18 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "so_long.h"
#include "logic.h"
#include "gui.h"
#include "map.h"

void update_player(t_game *p)
{
	int new_x;
	int new_y;

	new_x = p->player.x + p->player.x_mov;
	new_y = p->player.y + p->player.y_mov;
	if (new_x != p->player.x && new_x >= 0 && new_x < p->width && (!is_solid(p->map[p->player.y][new_x]) || (p->map[p->player.y][new_x] == GATE && !p->coll_left)))
		p->player.x = new_x;
	else if (new_y >= 0 && new_y < p->height && (!is_solid(p->map[new_y][p->player.x]) || (p->map[new_y][p->player.x] == GATE && !p->coll_left)))
		p->player.y = new_y;
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

void tick(t_game *p)
{
	t_list	*enemies;
	t_enemy	*enemy;

	update_player(p);
	enemies = p->enemy;
	while (enemies)
	{
		enemy = (t_enemy *)enemies->content;
		enemy->update(p, enemy);
		enemies = enemies->next;
	}
}

int	update(void *param)
{
	t_app		*app;
	clock_t		current = clock();

	app = ((t_app *) param);
	if (app->game.player.dead)
		terminate(app, 0);
	current = clock();
	while ((double)(current - app->game.last_tick) / CLOCKS_PER_SEC > (1.0 / TICK_RATE) * 1)
	{
		tick(&app->game);
		app->game.last_tick += (1.0 / TICK_RATE) * 1000000;
	}
	render(app);
	return (1);
}
