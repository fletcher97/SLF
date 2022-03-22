/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:39:50 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/17 16:42:43 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_norm.h"

#include "map.h"
#include "logic.h"
#include "enemies.h"

static int	map_to_arr(t_game *game, const char *map)
{
	int		fd;
	int		i;
	int		ret;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	ret = 1;
	game->map = ft_calloc(game->height, sizeof(char *));
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) > 0)
			game->map[i++] = line;
		else
			ft_free(line);
	}
	return (ret);
}

static t_enemy *new_enemy(char type, int x, int y)
{
	t_enemy *ret;
	ret = ft_calloc(1, sizeof(t_enemy));
	ret->x = x;
	ret->y = y;
	if (is_spider(type))
	{
		ret->update = update_spider;
		ret->render = render_spider;
		ret->dir = dir_spider(type);
	}
	else if (is_tank(type))
	{
		ret->update = update_tank;
		ret->render = render_tank;
		ret->dir = dir_tank(type);
	}
	else if (is_ship(type))
	{
		ret->update = update_ship;
		ret->render = render_ship;
		ret->dir = dir_ship(type);
	}
	else if (is_jaws(type))
	{
		ret->update = update_jaws;
		ret->render = render_jaws;
		ret->dir = dir_jaws(type);
	}
	else if (is_fireball(type))
	{
		ret->update = update_fireball;
		ret->render = render_fireball;
		ret->dir = dir_fireball(type);
	}
	else if (is_ball(type))
	{
		ret->update = update_ball;
		ret->render = render_ball;
		ret->dir = dir_ball(type);
	}
	else if (is_paramecium(type))
	{
		ret->update = update_paramecium;
		ret->render = render_paramecium;
		ret->dir = dir_paramecium(type);
	}
	return ret;
}

static int	map_read_cont(t_game *game)
{
	int	i;
	int	j;
	int	exit;
	t_enemy	*enemy;

	(i = -1) && (exit = 0);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == PLAY)
			{
				(game->map[i][j] = VOID) && (game->player.x = j);
				game->player.y = i;
				game->player.dir = LEFT;
			}
			else if (is_enemy(game->map[i][j]))
			{
				enemy = new_enemy(game->map[i][j], j, i);
				ft_lstadd_back(&game->enemy, ft_lstnew(enemy));
				game->map[i][j] = VOID;
			}
			else if (game->map[i][j] == CHIP)
				game->coll_left++;
			else if (game->map[i][j] == EXIT)
				exit = 1;
		}
	}
	return (exit && game->coll_left > 0 && game->player.dir);
}

int	parse_map(t_app *app, const char *map)
{
	int	fd;
	int	size;

	fd = open(map, O_RDONLY);
	if (fd == -1 || !ft_strendw(map, ".ber"))
		ft_putstr_fd("Error\nCouldn't read the map.\n", STDERR);
	if (fd == -1)
		return (0);
	close(fd);
	size = check_map(map, app);
	if (!size)
		return (0);
	map_to_arr(&(app->game), map);
	if (!check_boudaries(&(app->game)))
	{
		ft_putstr_fd("Error\nMap is not closed.\n", STDERR);
		return (0);
	}
	if (!map_read_cont(&(app->game)))
	{
		ft_putstr_fd("Error\nMap is missing elements.\n", STDERR);
		return (0);
	}
	return (1);
}
