/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tile_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:39:10 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/18 14:19:54 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_solid(char c)
{
	return (c == WALL || c == GATE || c == RDOOR || c == GDOOR || c == BDOOR
		|| c == YDOOR || c == CDL || c == CLU || c == CUR || c == CRD
		|| c == BLOCK);
}

int is_enemy(char c)
{
	return (c == SPIDER_U || c == SPIDER_D || c == SPIDER_L || c == SPIDER_R
	|| c == TANK_U || c == TANK_D || c == TANK_L || c == TANK_R
	|| c == SHIP_U || c == SHIP_D || c == SHIP_L || c == SHIP_R
	|| c == JAWS_U || c == JAWS_D || c == JAWS_L || c == JAWS_R
	|| c == FIREBALL_U || c == FIREBALL_D || c == FIREBALL_L || c == FIREBALL_R
	|| c == BALL_U || c == BALL_D || c == BALL_L || c == BALL_R
	|| c == PARAMECIUM_U || c == PARAMECIUM_D || c == PARAMECIUM_L || c == PARAMECIUM_R);
}

int get_tile_id(char c)
{
	if (c == VOID)
		return 80;
	if (c == WALL)
		return 96;
	if (c == GATE)
		return 82;
	if (c == BLOCK)
		return 98;
	if (c == WATER)
		return 104;
	if (c == FIRE)
		return 117;
	if (c == EXIT)
		return 122;

	if (c == CHIP)
		return 81;

	if (c == RKEY)
		return 16;
	if (c == GKEY)
		return 19;
	if (c == BKEY)
		return 17;
	if (c == YKEY)
		return 18;

	if (c == RDOOR)
		return 100;
	if (c == GDOOR)
		return 103;
	if (c == BDOOR)
		return 101;
	if (c == YDOOR)
		return 102;

	if (c == PUP)
		return 114;
	if (c == PDOWN)
		return 112;
	if (c == PLEFT)
		return 113;
	if (c == PRIGHT)
		return 115;

	if (c == ICE)
		return 105;

	if (c == CLU)
		return 110;
	if (c == CUR)
		return 111;
	if (c == CRD)
		return 108;
	if (c == CDL)
		return 109;

	if (c == IBOOT)
		return 24;
	if (c == PBOOT)
		return 25;
	if (c == FBOOT)
		return 26;
	if (c == WBOOT)
		return 27;
	return 80;
}
