/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:29:32 by mansoor           #+#    #+#             */
/*   Updated: 2024/07/26 20:40:26 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 53)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		exit(0);
	}
	else if (keysym == LEFT_ARROW)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == RIGHT_ARROW)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == UP_ARROW)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == DOWN_ARROW)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == PLUS)
		fractal->iterations_definition += 10;
	else if (keysym == MINUS)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->zoom *= 1.05;
	}
	else if (button == 5)
	{
		fractal->zoom *= 0.95;
	}
	fractal_render(fractal);
	return (0);
}

// Track the mouse to change julia dynamically

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, +2, -2, 0, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (map(y, -2, +2, 0, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
