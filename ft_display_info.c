/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:15:57 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 16:10:17 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_info(t_engine *engine)
{
	int		x;
	int		color;
	char	*str;

	x = 1200;
	color = 0x00FFFF00;
	mlx_string_put(engine->mlx, engine->window, x, 20, color, "screen resolution:");
	str = ft_get_screen_resolution_str(engine);//ft_itoa(engine->resolution->width);
	mlx_string_put(engine->mlx, engine->window, x + 120, 20, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 40, color, "open file:");
	mlx_string_put(engine->mlx, engine->window, x + 120, 40, color, engine->file);
	mlx_string_put(engine->mlx, engine->window, x, 60, color, "rows:");
	str = ft_int_to_string(engine->screen->rows);
	mlx_string_put(engine->mlx, engine->window, x + 120, 60, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 80, color, "columns:");
	str = ft_int_to_string(engine->screen->columns);
	mlx_string_put(engine->mlx, engine->window, x + 120, 80, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 100, color, "total points:");
	str = ft_int_to_string(engine->screen->rows * engine->screen->columns);
	mlx_string_put(engine->mlx, engine->window, x + 120, 100, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 120, color, "color:");

	mlx_string_put(engine->mlx, engine->window, x, 160, color, "move projection:  arrow keys");
	mlx_string_put(engine->mlx, engine->window, x, 180, color, "zoom in/out:      +/-");
	str = ft_int_to_string(engine->screen->zoom);
	mlx_string_put(engine->mlx, engine->window, x + 200, 180, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 200, color, "z inc/dec:        f/v");
	str = ft_int_to_string(engine->screen->zoom_z);
	mlx_string_put(engine->mlx, engine->window, x + 200, 200, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 220, color, "rotate x:         s/w");
	str = ft_int_to_string(engine->screen->angle.x);
	mlx_string_put(engine->mlx, engine->window, x + 200, 220, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 240, color, "rotate y:         a/d");
	str = ft_int_to_string(engine->screen->angle.y);
	mlx_string_put(engine->mlx, engine->window, x + 200, 240, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 260, color, "rotate z:         q/e");
	str = ft_int_to_string(engine->screen->angle.z);
	mlx_string_put(engine->mlx, engine->window, x + 200, 260, color, str);
	free(str);
	mlx_string_put(engine->mlx, engine->window, x, 280, color, "change projection:  i = isometric p = parallel");

}
