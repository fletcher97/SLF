/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:41:21 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/16 18:53:08 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

# define MAP_CHARS " 1234ECP./!rRgGbByY^v<>iILKJ6789"

# define VOID ' '
# define WALL '1'
# define GATE '2'
# define BLOCK '3'
# define WATER '4'
# define EXIT 'E'

# define CHIP 'C'
# define PLAY 'P'

# define ENEM_A '.'
# define ENEM_B '/'
# define ENEM_C '!'

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

#endif
