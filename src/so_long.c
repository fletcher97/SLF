/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:42:30 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/13 18:08:06 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "mlx.h"

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_conv.h"
#include "ft_string.h"

#include "so_long.h"
#include "listeners.h"
#include "map.h"
#include "gui.h"

static int	init(t_app *app, char **argv)
{
	int			i;
	t_screen	*s;
	t_img		*img;

	if (!parse_map(app, argv[1]))
		return (0);
	app->mlx = mlx_init();
	get_screen(app);
	s = &app->screen;
	s->win = mlx_new_window(app->mlx, s->width, s->height, s->title);
	s->img = ft_calloc(2, sizeof(t_img *));
	if (!s->img)
		return (0);
	s->img[0] = ft_calloc(1, sizeof(t_img));
	img = s->img[0];
	img->img = mlx_new_image(app->mlx, s->width, s->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line,
			&img->endian);
	s->img[1] = ft_calloc(1, sizeof(t_img));
	img = s->img[1];
	img->img = mlx_new_image(app->mlx, s->width, s->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line,
			&img->endian);
	s->tiles = ft_calloc(1, sizeof(t_img));
	img = s->tiles;
	img->img = mlx_xpm_file_to_image(app->mlx, "res/assets/Chips.xpm", &i, &i);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line,
			&img->endian);
	return (1);
}

//TODO: update
void	terminate(t_app *app, int i)
{
	//if (app->mlx && app->screen.img && app->screen.img->img)
	//	mlx_destroy_image(app->mlx, app->screen.img->img);
	if (app->screen.img)
		ft_free(app->screen.img);
	if (app->mlx && app->screen.win)
		mlx_destroy_window(app->mlx, app->screen.win);
	if (app->screen.title)
		ft_free(app->screen.title);
	if (app->mlx)
		ft_free(app->mlx);
	i = -1;
	while (++i < app->game.height)
		if (app->game.map && app->game.map[i])
			ft_free(app->game.map[i]);
	if (app->game.enemy)
		ft_free(app->game.enemy);
	if (app->game.map)
		ft_free(app->game.map);
	ft_free(app);
	exit(0);
}


int	main(int argc, char **argv)
{
	t_app	*app;

	if (argc != 2)
		ft_putstr_fd("Error\nWrong number of parameter.\n", STDERR);
	if (argc != 2)
		return (1);
	app = ft_calloc(1, sizeof(t_app));
	if (!init(app, argv))
		terminate(app, 0);
	set_listeners(app);
	mlx_loop_hook(app->mlx, update, app);
	app->game.last_tick = clock();
	for(int i = 0; i < app->game.height; i++)
		printf("%s\n", app->game.map[i]);
	mlx_loop(app->mlx);
	return (0);
}
