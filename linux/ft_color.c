/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:54:51 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/02 20:24:53 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_color(t_line *line)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (line->dx > line->dy)
		percentage = ft_get_percentage(line->start.x, line->end.x, line->pos.x);
	else
		percentage = ft_get_percentage(line->start.y, line->end.y, line->pos.y);
	red = ft_get_rgb((line->start.color >> 16) & 0xff,
			(line->end.color >> 16) & 0xff, percentage);
	green = ft_get_rgb((line->start.color >> 8) & 0xff,
			(line->end.color >> 8) & 0xff, percentage);
	blue = ft_get_rgb((line->start.color) & 0xff,
			(line->end.color) & 0xff, percentage);
	return ((red << 16) | (green << 8) | blue);
}

double	ft_get_percentage(int start, int end, int pos)
{
	double	place;
	double	distance;

	place = (double) pos - start;
	distance = (double) end - start;
	if (distance == 0)
		return (1.0);
	else
		return (place / distance);
}

int	ft_get_rgb(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}
