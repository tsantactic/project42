/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:22:16 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/24 16:08:43 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

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
	double	mouse_x;
	double	mouse_y;

	mouse_x = (map((double)x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	mouse_y = (map((double)y, 2, -2, HEIGHT) * fractal->zoom)
		+ fractal->shift_y;
	if (button == 5)
	{
		fractal->zoom = fractal->zoom * 1.05;
		fractal->shift_x += (mouse_x - fractal->shift_x) * (-0.05);
		fractal->shift_y += (mouse_y - fractal->shift_y) * (-0.05);
	}
	else if (button == 4)
	{
		fractal->zoom = fractal->zoom * 0.95;
		fractal->shift_x += (mouse_x - fractal->shift_x) * (0.05);
		fractal->shift_y += (mouse_y - fractal->shift_y) * (0.05);
	}
	fractal_render(fractal);
	return (0);
}

static int	key_events(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		close_all(fractal);
	else if (key == XK_Up)
		fractal->shift_y = fractal->shift_y + 0.005;
	else if (key == XK_Down)
		fractal->shift_y = fractal->shift_y - 0.005;
	else if (key == XK_Left)
		fractal->shift_x = fractal->shift_x - 0.005;
	else if (key == XK_Right)
		fractal->shift_x = fractal->shift_x + 0.005;
	else if (key == 65451)
		fractal->iteration += 1;
	else if (key == 65453)
		fractal->iteration -= 1;
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
