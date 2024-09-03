/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:22:16 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/23 16:25:39 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	close_all(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(1);
}

static int	mouse_events(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		fractal->zoom *= 1.05;
	}
	else if (button == 4)
	{
		fractal->zoom *= 0.95;
	}
	fractal_render(fractal);
	return (0);
}

static int	key_events(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		close_all(fractal);
	fractal_render(fractal);
	return (0);
}

void	init_events(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_all,
		fractal);
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_events, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_events,
		fractal);
}
