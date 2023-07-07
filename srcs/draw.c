/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:57:24 by gmattei           #+#    #+#             */
/*   Updated: 2023/07/06 16:57:25 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)pixel = color;
}

void	ft_draw(t_data *data)
{
	if (data->mouse_x > WIN_WIDTH)
		data->mouse_x = WIN_WIDTH;
	if (data->mouse_y > WIN_HEIGHT)
		data->mouse_y = WIN_HEIGHT;
	if (data->mouse_y < 0)
		data->mouse_y = 0;
	if (data->fractal == 1)
		ft_equation(data);
	else if (data->fractal == 2)
		ft_julia(data);
	else
		ft_burning_ship(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	if (data->label % 2 == 1)
		ft_window_label(data);
}

void	window_label_2(int color, t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 275, 80,
		color, " Left Click and Right Click for instant zoom in and out");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 455, 15,
		color, "--> FRACTALS <--");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 455, 30,
		color, "'1' for Mandelbrot");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 455, 45,
		color, "'2' for Julia (default set)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 455, 60,
		color, "'3' for Burning Ship");
	if (data->fractal == 2)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 650, 15,
			color, "--> JULIA <--");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 650, 30,
			color, "'6' to decrease first parameter");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 650, 45,
			color, "'7' to increase first parameter");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 650, 60,
			color, "'8' to decrease second parameter");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 650, 75,
			color, "'9' to increase second parameter");
	}
}

void	ft_window_label(t_data *data)
{
	int	color;

	color = 0xffffff;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 15,
		color, "--> MOVEMENT <--");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 30,
		color, "Zoom in and out with mouse wheel");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 45,
		color, "Arrow Keys to move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 75,
		color, "--> COLOR <--");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 90,
		color, "'Z' to change color, 'X' to go back");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 105,
		color, "'A' and 'S' to do the same but more");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 275, 15,
		color, "--> SYSTEM <--");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 275, 30,
		color, "'R' to reset fractal");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 275, 45,
		color, "'L' to toggle all label");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 275, 60,
		color, "'Esc' or 'Q' to exit");
	window_label_2(color, data);
}
