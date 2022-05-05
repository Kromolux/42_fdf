/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 08:20:52 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 18:15:16 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_x(t_engine *engine, int i_row, int i_column, t_sin_cos *calcs)
{
	int	tmp_y;
	int	tmp_z;

	tmp_y = engine->screen->proj[i_row][i_column].y;
	tmp_z = engine->screen->proj[i_row][i_column].z;
	engine->screen->proj[i_row][i_column].y
		= tmp_y * calcs->cos_x + tmp_z * calcs->sin_x;
	engine->screen->proj[i_row][i_column].z
		= tmp_y * (-calcs->sin_x) + tmp_z * calcs->cos_x;
}

void	ft_rotate_y(t_engine *engine, int i_row, int i_column, t_sin_cos *calcs)
{
	int	tmp_x;
	int	tmp_z;

	tmp_x = engine->screen->proj[i_row][i_column].x;
	tmp_z = engine->screen->proj[i_row][i_column].z;
	engine->screen->proj[i_row][i_column].x
		= tmp_x * calcs->cos_y + tmp_z * (-calcs->sin_y);
	engine->screen->proj[i_row][i_column].z
		= tmp_x * calcs->sin_y + tmp_z * calcs->cos_y;
}

void	ft_rotate_z(t_engine *engine, int i_row, int i_column, t_sin_cos *calcs)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = engine->screen->proj[i_row][i_column].x;
	tmp_y = engine->screen->proj[i_row][i_column].y;
	engine->screen->proj[i_row][i_column].x
		= tmp_x * calcs->cos_z + tmp_y * calcs->sin_z;
	engine->screen->proj[i_row][i_column].y
		= tmp_x * (-calcs->sin_z) + tmp_y * calcs->cos_z;
}
