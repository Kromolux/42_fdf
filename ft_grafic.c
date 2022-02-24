/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grafic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:40:02 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/23 13:45:19 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_render_frame(t_engine *engine)
{
	ft_apply_rotation(engine);
	ft_draw_map(engine);

	mlx_put_image_to_window(engine->mlx, engine->window, engine->img->img, 0, 0);
	if (engine->img == &engine->img0)
		engine->img = &engine->img1;
	else
		engine->img = &engine->img0;
	ft_clear_image(engine);
	ft_display_info(engine);
	return (0);
}

void	ft_clear_image(t_engine *engine)
{
	int	x;
	int	y;

	y = 0;
	while (y < engine->screen->resolution.height)
	{
		x = 0;
		while (x < engine->screen->resolution.width)
		{
			ft_put_pixel(engine->img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	//printf("clear image done! y=%i x=%i\n", engine->screen->resolution.height, engine->screen->resolution.width);
}
