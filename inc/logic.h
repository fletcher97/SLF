/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:36:28 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/13 19:41:04 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H
# define LOGIC_H

# include "so_long.h"

# define UP 1
# define LEFT 2
# define DOWN 3
# define RIGHT 4

# define SEED 123456789

# define TICK_RATE 6

void	tick(t_game *app);
void	move(t_game *app);

#endif
