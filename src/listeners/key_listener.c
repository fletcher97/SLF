/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 07:24:09 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/13 19:39:09 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_keys.h"

int	stop(void *param)
{
	t_app	*app;

	app = ((t_app *) param);
	terminate(app, 0);
	return (0);
}

int	on_key_press(int key, void *param)
{
	t_app	*app;

	app = ((t_app *) param);
	if (key == MLX_KEY_ESC)
		terminate(app, 0);
	if (key == MLX_KEY_W)
		app->game.player.y_mov -= 1;
	else if (key == MLX_KEY_S)
		app->game.player.y_mov += 1;
	else if (key == MLX_KEY_D)
		app->game.player.x_mov += 1;
	else if (key == MLX_KEY_A)
		app->game.player.x_mov -= 1;
	return (0);
}

int	on_key_release(int key, void *param)
{
	t_app	*app;

	app = ((t_app *) param);
	if (key == MLX_KEY_ESC)
		terminate(app, 0);
	if (key == MLX_KEY_W)
		app->game.player.y_mov += 1;
	else if (key == MLX_KEY_S)
		app->game.player.y_mov -= 1;
	else if (key == MLX_KEY_D)
		app->game.player.x_mov -= 1;
	else if (key == MLX_KEY_A)
		app->game.player.x_mov += 1;
	return (0);
}
