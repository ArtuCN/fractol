/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:59:23 by aconti            #+#    #+#             */
/*   Updated: 2024/03/05 09:04:37 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ac 2 = mandelbrot
ac 4 = julia (a.out, julia, n, n)

name = mandelbrot || julia

*/

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 11))
		|| ((4 == ac) && !ft_strncmp(av[1], "julia", 6))
		|| (2 == ac && !ft_strncmp(av[1], "bonus", 6)))
	{
		fractal.name = av[1];
		fractal.julia_x = 0;
		fractal.julia_y = 0;
		if (!ft_strncmp(av[1], "julia", 6))
		{
			fractal.julia_x = atod(av[2]);
			fractal.julia_y = atod(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		ft_putstr(INPUT_ERROR);
}
