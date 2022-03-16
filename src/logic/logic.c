/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:10:18 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/16 14:23:04 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "so_long.h"
#include "logic.h"
#include "gui.h"

static void tick(t_game *p)
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
