/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:44:12 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/13 14:10:35 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <fcntl.h>

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "map.h"

static int	check_rect(const char *map, t_game *game)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(map, O_RDONLY);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		ft_putstr_fd("Error\nCouldn't read the map.\n", STDERR);
	if (ret == 0)
		ft_putstr_fd("Error\nMap is empty or has only one line.\n", STDERR);
	if (ret <= 0)
		return (-1);
	(game->width = ft_strlen(line)) && (game->height = 1);
	ft_free(line);
	while (ret > 0)
	{
		(ret = get_next_line(fd, &line)) && (game->height++);
		if ((ret > 0 && ft_strlen(line) != (size_t) game->width)
			|| (!ret && ft_strlen(line)
				&& ft_strlen(line) != (size_t) game->width))
			ret = -1;
		ft_free(line);
	}
	return ((close(fd) && 0) || ret != -1);
}

static int	check_cont(const char *map)
{
	int		fd;
	int		ret;
	char	*line;
	char	*curr;

	fd = open(map, O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		curr = line - 1;
		while (++curr && *curr)
		{
			if (!ft_strchr(MAP_CHARS, *curr) && curr)
			{
				ft_putstr_fd("Error\nMap contains unknown char.\n", STDERR);
				ft_free(line);
				return (close(fd) && 0);
			}
		}
		ft_free(line);
	}
	return ((close(fd) && 0) || 1);
}

int	check_boudaries(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if ((i == 0 || i == game->height - 1 || j == 0
					|| j == game->width - 1) && game->map[i][j] != WALL)
				return (0);
		}
	}
	return (1);
}

int	check_map(const char *map, t_app *app)
{
	int	ret;

	ret = check_rect(map, &(app->game));
	if (!ret)
		ft_putstr_fd("Error\nMap is not rectangle.\n", STDERR);
	if (!ret || ret == -1)
		return (0);
	ret = check_cont(map);
	if (!ret)
		return (0);
	return (ret);
}
