/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:50:01 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/15 15:50:04 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	ft_reset_fractal(t_data *data)
{
	data->x_min = -2.0;
	data->x_max = 2.0;
	data->y_min = -2.0;
	data->y_max = 2.0;
	data->move_x = 0;
	data->move_y = 0;
	data->zoom = 1.0;
	data->label = 1;
	data->julia_multiplier = 0.01;
	data->coord.max_iter = MAX_ITER;
	data->color = 262400;
}

void	ft_zoom_in(t_data *data, int px, int py)
{
	data->mouse_x = data->x_min + (px + data->move_x)
		* (data->x_max - data->x_min) / data->small_side;
	data->mouse_y = data->y_max - (data->move_y + py)
		* (data->y_max - data->y_min) / data->small_side;
	data->zoom_decr = data->zoom / 1;
	data->new_zoom = fabsl(data->zoom - data->zoom_decr);
	if (data->new_zoom <= data->zoom_decr)
	{
		data->zoom_decr /= 10;
		data->new_zoom = data->zoom - data->zoom_decr;
	}
	data->zoom_factor = data->new_zoom / data->zoom;
	data->x_min = data->mouse_x
		- (data->mouse_x - data->x_min) * data->zoom_factor;
	data->y_min = data->mouse_y
		- (data->mouse_y - data->y_min) * data->zoom_factor;
	data->x_max = data->mouse_x
		+ (data->x_max - data->mouse_x) * data->zoom_factor;
	data->y_max = data->mouse_y
		+ (data->y_max - data->mouse_y) * data->zoom_factor;
	data->zoom = data->new_zoom;
	data->coord.max_iter += 8;
}

void	ft_zoom_out(t_data *data, int px, int py)
{
	data->mouse_x = data->x_min + (px + data->move_x)
		* (data->x_max - data->x_min) / data->small_side;
	data->mouse_y = data->y_max - (data->move_y + py)
		* (data->y_max - data->y_min) / data->small_side;
	data->zoom_incr = data->zoom / 10;
	data->new_zoom = fabsl(data->zoom + data->zoom_incr);
	if (data->new_zoom <= data->zoom_decr)
	{
		data->zoom_decr /= 10;
		data->new_zoom = data->zoom + data->zoom_incr;
	}
	data->zoom_factor = data->new_zoom / data->zoom;
	data->x_min = data->mouse_x
		- (data->mouse_x - data->x_min) * data->zoom_factor;
	data->y_min = data->mouse_y
		- (data->mouse_y - data->y_min) * data->zoom_factor;
	data->x_max = data->mouse_x
		+ (data->x_max - data->mouse_x) * data->zoom_factor;
	data->y_max = data->mouse_y
		+ (data->y_max - data->mouse_y) * data->zoom_factor;
	data->zoom = data->new_zoom;
	data->coord.max_iter -= 8;
}

int	ft_mouse_handler(int keycode, int px, int py, t_data *data)
{
	if (keycode == 4)
		ft_zoom_in(data, px, py);
	else if (keycode == 5)
		ft_zoom_out(data, px, py);
	else if (keycode == 1)
		instant_pointed_zoom(data, px, py, 1);
	else if (keycode == 3)
		instant_pointed_zoom(data, px, py, 0);
	else
		return (0);
	ft_draw(data);
	return (1);
}

int	ft_key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == XK_q)
	{
		ft_destroy_fractal(data);
		return (0);
	}
	else if (keycode == XK_Up)
		data->move_y -= (WIN_HEIGHT / 20);
	else if (keycode == XK_Left)
		data->move_x -= (WIN_HEIGHT / 20);
	else if (keycode == XK_Down)
		data->move_y += (WIN_HEIGHT / 20);
	else if (keycode == XK_Right)
		data->move_x += (WIN_HEIGHT / 20);
	else if (keycode == XK_x)
		data->color += 5;
	else if (keycode == XK_z)
		data->color -= 5;
	else if (keycode == XK_s)
		data->color += 20000;
	else if (keycode == XK_a)
		data->color -= 20000;
	else
		hook_handler_2(keycode, data);
	ft_draw(data);
	return (0);
}
