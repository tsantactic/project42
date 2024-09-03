/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:12:54 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/24 13:52:51 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

double	map(double num_min, double new_min, double new_max, double num_max)
{
	double	result;

	result = (new_max - new_min) * (num_min - 0) / (num_max - 0) + new_min;
	return (result);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z, t_fractal *fractal)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	if (!ft_strncmp(fractal->name, "tricorn", 7))
		result.y = -2 * z.x * z.y;
	else
		result.y = 2 * z.x * z.y;
	return (result);
}
