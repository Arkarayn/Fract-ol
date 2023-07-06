/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:23:05 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/15 14:23:14 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	ft_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "fract-ol");
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!data->mlx_ptr || !data->win_ptr || !data->img.mlx_img)
	{
		ft_printf("An error has occured. Please try again");
		return (MLX_ERROR);
	}
	return (0);
}

void	ft_hooks_init(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, 1l << 0, &ft_key_handler, data);
	mlx_mouse_hook(data->win_ptr, &ft_mouse_handler, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, &ft_destroy_fractal, data);
	mlx_loop(data->mlx_ptr);
}

int	ft_get_small_side(void)
{
	if (WIN_WIDTH < WIN_HEIGHT)
		return (WIN_WIDTH);
	else
		return (WIN_HEIGHT);
	return (0);
}

void	ft_draw_handler(t_data *data)
{
	data->x_min = -2.0;
	data->x_max = 2.0;
	data->y_min = -2.0;
	data->y_max = 2.0;
	data->move_x = 0;
	data->move_y = 0;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->small_side = ft_get_small_side();
	data->zoom = 1;
	data->label = 1;
	data->julia_multiplier = 0.01;
	data->zoom_incr = data->zoom / 10;
	data->zoom_decr = data->zoom_incr;
	data->coord.max_iter = MAX_ITER;
	data->color = 262400;
	ft_draw(data);
}

void	hook_handler_2(int keycode, t_data *data)
{
	if (keycode == XK_r)
		ft_reset_fractal(data);
	else if (keycode == XK_1)
		fractal_change(data, 1);
	else if (keycode == XK_2)
		fractal_change(data, 2);
	else if (keycode == XK_3)
		fractal_change(data, 3);
	else if (keycode == XK_l)
		data->label++;
	else if (keycode == XK_4)
		data->julia_multiplier -= 0.01;
	else if (keycode == XK_5)
		data->julia_multiplier += 0.01;
	else if (keycode == XK_6)
		data->coord.julia.re -= data->julia_multiplier;
	else if (keycode == XK_7)
		data->coord.julia.re += data->julia_multiplier;
	else if (keycode == XK_8)
		data->coord.julia.im -= data->julia_multiplier;
	else if (keycode == XK_9)
		data->coord.julia.im += data->julia_multiplier;
}
