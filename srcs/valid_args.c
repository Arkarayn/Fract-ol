/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:35:04 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/15 11:35:08 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	fractal_change(t_data *data, int n)
{
	data->fractal = n;
	ft_reset_fractal(data);
	if (n == 2)
		instant_zoom(data);
}

void	instant_zoom(t_data *data)
{
	int	i;

	i = 13;
	while (i > 0)
	{
		ft_zoom_in(data, data->small_side / 2, data->small_side / 2);
		i--;
	}
}

void	ft_sprintf(char *str, double x)
{
	int	i;

	sprintf(str, "%f", x);
	i = 5;
	while (i > 0)
	{
		if (str[i] == '0')
			str[i] = '\0';
		else
			break ;
		i--;
	}
}

int	ft_julia_args(t_data *data, int argc, char **argv)
{
	if (argc == 4)
	{
		data->coord.julia.re = ft_atof(argv[2]);
		data->coord.julia.im = ft_atof(argv[3]);
	}
	else
	{
		data->coord.julia.re = -1.2;
		data->coord.julia.im = -0.16;
	}
	if (data->coord.julia.re > -2 && data->coord.julia.re < 2
		&& data->coord.julia.im > -2 && data->coord.julia.im < 2)
		return (1);
	return (0);
}

int	ft_valid_args(t_data *data, int argc, char **argv)
{
	if (argc == 2)
	{
		ft_julia_args(data, argc, argv);
		if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
			return (1);
		else if (!ft_strncmp(argv[1], "burningship", ft_strlen(argv[1])))
			return (3);
	}
	else if (argc == 4)
		if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1]))
			&& ft_julia_args(data, argc, argv))
			return (2);
	return (0);
}
