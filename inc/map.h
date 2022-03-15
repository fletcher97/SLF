/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:41:21 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/13 21:08:01 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

# define MAP_CHARS " 1ECPGBW./!"

# define VOID ' '
# define WALL '1'
# define EXIT 'E'
# define CHIP 'C'
# define PLAY 'P'
# define GATE 'G'
# define BLOCK 'B'
# define WATER 'W'
# define ENEM_A '.'
# define ENEM_B '/'
# define ENEM_C '!'

int	parse_map(t_app *app, const char *map);
int	check_map(const char *map, t_app *app);
int	check_boudaries(t_game *game);
int	get_tile_id(char c);
int	is_solid(char c);

#endif
