/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:56:33 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/24 17:12:47 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int arg, char **argv)
{
	t_fractal	fractal;

	if (check_args(arg, argv) == 0)
	{
		fractal.name = argv[1];
		fractal = is_julia(fractal, argv);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		display_error_arg();
	return (0);
}
