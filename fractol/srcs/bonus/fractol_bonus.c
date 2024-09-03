/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:56:33 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/22 18:30:15 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

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
