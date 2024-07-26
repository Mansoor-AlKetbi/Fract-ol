/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:44:23 by mal-ketb          #+#    #+#             */
/*   Updated: 2024/07/26 20:55:34 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0) || (ac == 4
			&& ft_strncmp(av[1], "julia", 5) == 0))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		if ((ac == 4 && ft_strncmp(av[1], "julia", 5) == 0))
		{
			fractal.julia_x = atoidbl(av[2]);
			fractal.julia_y = atoidbl(av[3]);
		}
		mlx_hook(fractal.mlx_window, 2, 0, key_handler, &fractal);
		mlx_hook(fractal.mlx_window, 4, 1L << 2, mouse_handler, &fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
