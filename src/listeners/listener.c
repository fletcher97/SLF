/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:01:15 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/08 22:55:07 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"
#include "listeners.h"

void	set_listeners(t_app *app)
{
	mlx_hook(app->screen.win, MLX_DESTROY_NOTIFY, 1L, stop, app);
	mlx_hook(app->screen.win, MLX_KEY_PRESS, (1L << 0), on_key_press, app);
	mlx_hook(app->screen.win, MLX_KEY_RELEASE, (1L << 1),
		on_key_release, app);
}
