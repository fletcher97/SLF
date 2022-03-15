/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tile_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:39:10 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/13 21:03:16 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_solid(char c)
{
	return (c == WALL || c == GATE);
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
	return 80;
}
