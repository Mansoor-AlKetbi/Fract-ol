/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:32 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/07/26 21:07:08 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE                                                                        \
	"Please enter \n\t/fractol mandelbrot\" or \n\t\" ./fractol julia <value_1> <value_2>\n" \
	""
# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define ESC_KEY 53
# define PLUS 69
# define MINUS 78
# define KEY_PRESS 2

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_pointer;
	char	*pixels_pointer;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;
# define ERROR_MESSAGE "Please enter \n\t/fractol mandelbrot\" or \n\t\" ./fractol julia <value_1> <value_2>\n" \""

int			ft_strlen(char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, char *s2, size_t n);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
double		map(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		my_pixel_put(int x, int y, t_img *img, int color);
void		mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		atoidbl(char *s);

#endif
