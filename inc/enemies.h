/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:12:09 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/13 20:33:09 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_H
# define ENEMIES_H

int update_a(void *g, void* e);
int update_b(void *g, void* e);
int update_c(void *g, void* e);

int render_a(void *g, int x, int y);
int render_b(void *g, int x, int y);
int render_c(void *g, int x, int y);

#endif //ENEMIES_H
