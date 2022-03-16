/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:36:28 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/16 14:20:34 by fletcher         ###   ########.fr       */
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

void	move(t_game *app);
void	update_player(t_game *p);
void	render_player(t_app *a);

#endif
