/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:12:09 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/17 16:19:12 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_H
# define ENEMIES_H

int is_spider(char c);
int is_tank(char c);
int is_ship(char c);
int is_jaws(char c);
int is_fireball(char c);
int is_ball(char c);
int is_paramecium(char c);

int dir_spider(char c);
int dir_tank(char c);
int dir_ship(char c);
int dir_jaws(char c);
int dir_fireball(char c);
int dir_ball(char c);
int dir_paramecium(char c);

int update_spider(void *g, void* e);
int update_tank(void *g, void* e);
int update_ship(void *g, void* e);
int update_jaws(void *g, void* e);
int update_fireball(void *g, void* e);
int update_ball(void *g, void* e);
int update_paramecium(void *g, void* e);

int render_spider(void *g, void *e);
int render_tank(void *g, void *e);
int render_ship(void *g, void *e);
int render_jaws(void *g, void *e);
int render_fireball(void *g, void *e);
int render_ball(void *g, void *e);
int render_paramecium(void *g, void *e);

#endif //ENEMIES_H
