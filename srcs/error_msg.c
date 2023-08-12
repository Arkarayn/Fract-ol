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
	ft_printf("\033[1;32mAvailable fractals:\033[3;31m\n");
	ft_printf("   -mandelbrot\n");
	ft_printf("   -julia\n");
	ft_printf("   -burningship\033[0m\n\n");
	ft_printf("Usage: \033[36m./fractol \033[3;33m'name of the fractal'\033[0m\n\n");
	ft_printf("\033[1;31mATTENTION\033[0m\n\n");
	ft_printf("For julia, you need \033[31mtwo\033[0m numbers as other arguments\n\n");
	ft_printf("Usage: \033[36m./fractol \033[3;33m'name of the fractal' 'number' 'number'\033[0m\n");
	ft_printf("\033[1;33mFor Julia default set: \033[1;3;31mset the mandelbrot and press 2.\033[0m\n\n");
}
