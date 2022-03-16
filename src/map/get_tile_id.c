/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tile_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:39:10 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/16 15:45:37 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_solid(char c)
{
	return (c == WALL || c == GATE || c == RDOOR || c == GDOOR || c == BDOOR
		|| c == YDOOR);
}

int get_tile_id(char c)
{
	if (c == VOID)
		return 80;
	if (c == WALL)
		return 96;
	if (c == EXIT)
		return 122;
	if (c == CHIP)
		return 81;
	if (c == GATE)
		return 82;
	if (c == BLOCK)
		return 98;
	if (c == WATER)
		return 104;

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
	return 80;
}
