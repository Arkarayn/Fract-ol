/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:34:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/15 11:34:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	ft_error_msg(void)
{
	ft_printf("Available fractals:\n");
	ft_printf("-mandelbrot\n");
	ft_printf("-julia\n");
	ft_printf("-burningship\n\n");
	ft_printf("Usage: ./fractol 'name of the fractal'\n\n");
	ft_printf("ATTENTION\n\n");
	ft_printf("For julia, you need two numbers as other arguments\n\n");
	ft_printf("Usage: ./fractol 'name of the fractal' 'number' 'number'\n");
	ft_printf("Advised numbers: -0.67 0.42\n\n");
}
