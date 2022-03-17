/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 23:41:56 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/13 19:19:46 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "game.h"

# define IMG_SIZE 32
# define SCALE 2

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

void	get_screen(t_app *app);
void	render(t_app *app);
void	put_tile(t_screen *screen, int x, int y, int id);

#endif
