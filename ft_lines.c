/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:05:22 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/23 12:37:19 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_rectangle(t_engine *engine, t_line rectangle)
{
	t_line	line;

	//printf("entered draw rectangle\n");
	line.start.color = rectangle.start.color;
	line.end.color = rectangle.end.color;
	line.start.x = rectangle.start.x;
	line.start.y = rectangle.start.y;
	line.end.x = rectangle.end.x;
	line.end.y = rectangle.start.y;
	ft_draw_line(engine, line);
	line.start.x = rectangle.end.x;
	line.start.y = rectangle.start.y;
	line.end.x = rectangle.end.x;
	line.end.y = rectangle.end.y;
	ft_draw_line(engine, line);
	line.start.x = rectangle.start.x;
	line.start.y = rectangle.end.y;
	line.end.x = rectangle.end.x;
	line.end.y = rectangle.end.y;
	ft_draw_line(engine, line);
	line.start.x = rectangle.start.x;
	line.start.y = rectangle.start.y;
	line.end.x = rectangle.start.x;
	line.end.y = rectangle.end.y;
	ft_draw_line(engine, line);
}

void	ft_draw_line(t_engine *engine, t_line line)
{
	//printf("entered draw line\n");
	if (!ft_at_least_one_point_on_screen(engine, &line))
		return ;
	ft_line_preparations(&line);
	if (ft_abs(line.dx) == ft_abs(line.dy) || line.dx == 0 || line.dy == 0)
		ft_draw_line_edge_case(engine, line);
	else
		ft_draw_line_algorythm(engine, line);
}
int		ft_at_least_one_point_on_screen(t_engine *engine, t_line *line)
{
	if ((line->start.x >= 0 && line->start.x < engine->screen->resolution.width)
		|| (line->start.y >= 0 &&line->start.y < engine->screen->resolution.height)
		|| (line->end.x >= 0 && line->end.x < engine->screen->resolution.width)
		|| (line->end.y >= 0 && line->end.y < engine->screen->resolution.height))
		return (1);
	return (0);
}

void	ft_line_preparations(t_line *line)
{
	int	*primary;
	int	*secondary;

	line->dx = line->end.x - line->start.x;
	line->x_next = 0;
	if (line->dx > 0)
		line->x_next = 1;
	else if (line->dx < 0)
		line->x_next = -1;
	line->dy = line->end.y - line->start.y;
	line->y_next = 0;
	if (line->dy > 0)
		line->y_next = 1;
	else if (line->dy < 0)
		line->y_next = -1;
	primary = &line->dx;
	secondary = &line->dy;
	if (ft_abs(line->dy) > ft_abs(line->dx))
	{
		primary = &line->dy;
		secondary = &line->dx;
	}
	line->p_start = (2 * ft_abs(*secondary)) - ft_abs(*primary);
	line->p_less = (2 * ft_abs(*secondary));
	line->p_greater = (2 * ft_abs(*secondary)) - (2 * ft_abs(*primary));
	//printf("line preparations:\n dx=%i dy=%i\n x_next=%i y_next=%i\n", line->dx, line->dy, line->x_next, line->y_next);
}

void	ft_draw_line_edge_case(t_engine *engine, t_line line)
{
	ft_put_pixel(engine->img, line.start.x, line.start.y, line.start.color);
	while (line.start.x != line.end.x || line.start.y != line.end.y)
	{
		line.start.x += line.x_next;
		line.start.y += line.y_next;
		ft_put_pixel(engine->img, line.start.x, line.start.y, line.start.color);
	}
}

void	ft_draw_line_algorythm(t_engine *engine, t_line line)
{
	int	*primary;
	int	*secondary;
	int	*primary_next;
	int	*secondary_next;
	int	*primary_end;

	primary = &line.start.x;
	secondary = &line.start.y;
	primary_next = &line.x_next;
	secondary_next = &line.y_next;
	primary_end = &line.end.x;
	if (ft_abs(line.dy) > ft_abs(line.dx))
	{
		primary = &line.start.y;
		secondary = &line.start.x;
		primary_next = &line.y_next;
		secondary_next = &line.x_next;
		primary_end = &line.end.y;
	}
	//printf("primary=%i primary_next=%i\nsecondary=%i secondary_next=%i\n", *primary, *primary_next, *secondary, *secondary_next);
	//printf("p_start=%i p_less=%i p_greater=%i\n", line.p_start, line.p_less, line.p_greater);
	//printf("put pixel [%i][%i]\n", line.start.x, line.start.y);
	ft_put_pixel(engine->img, line.start.x, line.start.y, line.start.color);
	while (*primary != *primary_end)
	{
		*primary += *primary_next;
		if (line.p_start < 0)
			line.p_start += line.p_less;
		else
		{
			line.p_start += line.p_greater;
			*secondary += *secondary_next;
		}
		//printf("put pixel [%i][%i]\n", line.start.x, line.start.y);
		ft_put_pixel(engine->img, line.start.x, line.start.y, line.start.color);
	}
	//printf("draw line algorythm ended\n");
}
