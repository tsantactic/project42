/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:00:01 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/24 17:40:36 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

int	check_args(int arg, char **argv)
{
	if ((arg == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0) || (arg == 2
			&& ft_strncmp(argv[1], "tricorn", 8) == 0) || (arg == 4
			&& ft_strncmp(argv[1], "julia", 6) == 0))
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0)
		{
			if (check_values(argv) == 1)
			{
				return (1);
			}
			else
				return (0);
		}
		return (0);
	}
	return (1);
}

t_fractal	is_julia(t_fractal fractal, char **argv)
{
	if (ft_strncmp(fractal.name, "julia", 6) == 0)
	{
		fractal.julia_x = atodouble(argv[2]);
		fractal.julia_y = atodouble(argv[3]);
	}
	return (fractal);
}

void	init_data(t_fractal *fractal)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->escape_value = 4;
	fractal->iteration = 100;
	fractal->zoom = 1.5;
}

double	atodouble(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		perror_malloc();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		perror_malloc();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (!fractal->img.img_ptr)
	{
		ft_free_mlx(fractal, 2);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	if (!fractal->img.pixels_ptr)
	{
		ft_free_mlx(fractal, 3);
	}
	init_events(fractal);
	init_data(fractal);
}
