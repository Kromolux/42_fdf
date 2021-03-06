/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 07:18:56 by rkaufman          #+#    #+#             */
/*   Updated: 2022/03/01 07:19:13 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_rectangle(t_engine *engine, t_line rectangle)
{
	t_line	line;

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
