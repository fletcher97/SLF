/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:47:54 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/13 15:10:02 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "game.h"

void	terminate(t_app *app, int i);
int		stop_hook(void *param);
int		update(void *param);

#endif //SO_LONG_H
