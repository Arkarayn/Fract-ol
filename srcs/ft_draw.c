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
	ft_window_label(data);
}

void	ft_window_label(t_data *data)
{
	int	color;

	color = 0xffffff;
	if (data->color >= color - 0x080808 && data->color <= 0x080808)
		color = 0x000000;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 60,
		color, "Zoom in and out with mouse wheel");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 40,
		color, "Press Arrow Keys to move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 80,
		color, "Press 'C' to change color");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 100,
		color, "Press 'R' to reset fractal");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 120,
		color, "Press 'Esc' to exit");
}