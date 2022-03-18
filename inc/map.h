/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:41:21 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/17 17:26:31 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"
//TUVWXZ
# define MAP_CHARS " 123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSY^<>"

# define VOID ' '
# define WALL '1'
# define GATE '2'
# define BLOCK '3'
# define WATER '4'
# define FIRE '5'
# define EXIT 'E'

# define CHIP 'C'
# define PLAY 'P'

# define SPIDER_U 'a'
# define SPIDER_D 'c'
# define SPIDER_L 'd'
# define SPIDER_R 'e'

# define TANK_U 'f'
# define TANK_D 'h'
# define TANK_L 'j'
# define TANK_R 'k'

# define SHIP_U 'l'
# define SHIP_D 'm'
# define SHIP_L 'n'
# define SHIP_R 'o'

# define JAWS_U 'p'
# define JAWS_D 'q'
# define JAWS_L 's'
# define JAWS_R 't'

# define FIREBALL_U 'u'
# define FIREBALL_D 'w'
# define FIREBALL_L 'x'
# define FIREBALL_R 'z'

# define BALL_U 'A'
# define BALL_D 'D'
# define BALL_L 'H'
# define BALL_R 'M'

# define PARAMECIUM_U 'N'
# define PARAMECIUM_D 'O'
# define PARAMECIUM_L 'Q'
# define PARAMECIUM_R 'S'

# define RKEY 'r'
# define GKEY 'g'
# define BKEY 'b'
# define YKEY 'y'

# define RDOOR 'R'
# define GDOOR 'G'
# define BDOOR 'B'
# define YDOOR 'Y'

# define PUP '^'
# define PDOWN 'v'
# define PLEFT '<'
# define PRIGHT '>'

# define ICE 'i'

// CXY = change x-y
# define CLU 'I'
# define CUR 'L'
# define CRD 'K'
# define CDL 'J'

# define IBOOT '6'
# define PBOOT '7'
# define FBOOT '8'
# define WBOOT '9'

# define ICE_BOOT 1
# define PUSH_BOOT 2
# define FIRE_BOOT 4
# define WATER_BOOT 8

int	parse_map(t_app *app, const char *map);
int	check_map(const char *map, t_app *app);
int	check_boudaries(t_game *game);
int	get_tile_id(char c);
int	is_solid(char c);
int	is_enemy(char c);

#endif
