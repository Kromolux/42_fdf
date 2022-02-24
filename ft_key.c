/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:57:03 by rkaufman          #+#    #+#             */
/*   Updated: 2022/02/24 17:09:33 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key(int keycode, t_engine *engine)
{
	ft_printf("key function called! keycode=%i\n", keycode);
	if (keycode == XK_Escape)
		ft_engine_destroy(engine);
	else if (keycode == XK_Left || keycode == XK_Right
			|| keycode == XK_Up || keycode == XK_Down)
		ft_key_screen_movement(keycode, engine);
	else if (keycode == XK_a || keycode == XK_d
			|| keycode == XK_s || keycode == XK_w
			|| keycode == XK_q || keycode == XK_e)
		ft_key_rotation(keycode, engine);
	else if (keycode == XK_i || keycode == XK_p)
		ft_key_projection_change(keycode, engine);
	else if (keycode == XK_Plus || keycode == XK_Minus
			|| keycode == XK_f || keycode == XK_v)
		ft_key_zoom(keycode, engine);
	else if (keycode == XK_Home)
		ft_key_center_view(keycode, engine);
	return (0);
}

void	ft_key_center_view(int keycode, t_engine *engine)
{
	if (keycode == XK_Home)
	{
		engine->screen->movement.x = 0;
		engine->screen->movement.y = 0;
		engine->screen->movement.z = 0;
	}
}

void	ft_key_projection_change(int keycode, t_engine *engine)
{
	if (keycode == XK_i)
	{
		engine->screen->angle.x = -35;
		engine->screen->angle.y = 35;
		engine->screen->angle.z = -35;
	}
	else if (keycode == XK_p)
	{

	}
}

void	ft_key_screen_movement(int keycode, t_engine *engine)
{
	if (keycode == XK_Left)
		engine->screen->movement.x -= 1 * (engine->screen->zoom / 2);
	else if (keycode == XK_Right)
		engine->screen->movement.x += 1 * (engine->screen->zoom / 2);
	else if (keycode == XK_Up)
		engine->screen->movement.y -= 1 * (engine->screen->zoom / 2);
	else if (keycode == XK_Down)
		engine->screen->movement.y += 1 * (engine->screen->zoom / 2);
}

void	ft_key_rotation(int keycode, t_engine *engine)
{
	if (keycode == XK_a)
		engine->screen->angle.y++;
	else if (keycode == XK_d)
		engine->screen->angle.y--;
	else if (keycode == XK_s)
		engine->screen->angle.x++;
	else if (keycode == XK_w)
		engine->screen->angle.x--;
	else if (keycode == XK_q)
		engine->screen->angle.z++;
	else if (keycode == XK_e)
		engine->screen->angle.z--;
}

void	ft_key_zoom(int keycode, t_engine *engine)
{
	if (keycode == XK_Plus)
	{
		if (engine->screen->zoom >= 10)
			engine->screen->zoom += 5;
		else
			engine->screen->zoom += 1;
	}
	else if (keycode == XK_Minus)
	{
		if (engine->screen->zoom >= 15)
			engine->screen->zoom -= 5;
		else if (engine->screen->zoom > 1)
			engine->screen->zoom -= 1;
	}
	else if (keycode == XK_f)
		engine->screen->zoom_z += 1;
	else if (keycode == XK_v)
		engine->screen->zoom_z -= 1;
}