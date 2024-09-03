/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:56:39 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/24 17:56:30 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include "../lib/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	int		iteration;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	escape_value;
	t_img	img;
}			t_fractal;

double		atodouble(char *s);
double		map(double num_min, double new_min, double new_max,
				double num_max);

int			check_args(int arg, char **argv);
int			check_values(char **argv);

void		ft_free_mlx(t_fractal *fractal, int i);
void		display_error_arg(void);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		init_events(t_fractal *fractal);
void		perror_malloc(void);
void		init_data(t_fractal *fractal);

t_fractal	is_julia(t_fractal fractal, char **argv);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z, t_fractal *fractal);

#endif
