/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:00:11 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/24 16:25:35 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	perror_malloc(void)
{
	perror("Problems with malloc");
	exit(1);
}

void	display_error_arg(void)
{
	ft_putstr_fd("Error argument.\n", 2);
	ft_putstr_fd("For Example:\n", 2);
	ft_putstr_fd("\t./fractol mandelbrot\n", 2);
	ft_putstr_fd("\t\tor\n", 2);
	ft_putstr_fd("\t./fractol julia <value1> <value2>\n", 2);
	ft_putstr_fd("\t\tor\n", 2);
	ft_putstr_fd("\t./fractol tricorn\n", 2);
	exit(1);
}

void	ft_free_mlx(t_fractal *fractal, int i)
{
	if (i == 2)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		perror_malloc();
	}
	else if (i == 3)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		perror_malloc();
	}
}
