/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:47:51 by aconti            #+#    #+#             */
/*   Updated: 2024/03/05 09:03:51 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	arrow_julia(int keysym, t_fractal *fractal)
{
	if (keysym == LEFT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == RIGHT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == UP)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == DOWN)
		fractal->shift_y -= (0.05 * fractal->zoom);
	else if (!ft_strncmp (fractal->name, "julia", 6) && keysym == L)
		fractal->julia_x -= (0.09 * fractal->zoom);
	else if (!ft_strncmp (fractal->name, "julia", 6) && keysym == K)
		fractal->julia_x += (0.09 * fractal->zoom);
	else if (!ft_strncmp (fractal->name, "julia", 6) && keysym == N)
		fractal->julia_y -= (0.09 * fractal->zoom);
	else if (!ft_strncmp (fractal->name, "julia", 6) && keysym == M)
		fractal->julia_y += (0.09 * fractal->zoom);
	return (0);
}

int	iter_render(t_complex new, t_fractal *fractal)
{
	int	iteration;

	if (!ft_strncmp(fractal->name, "julia", 5))
		iteration = is_julia(new, fractal);
	else if (!ft_strncmp (fractal->name, "mandelbrot", 10))
		iteration = is_mandelbrot (new, fractal);
	else if (!ft_strncmp (fractal->name, "bonus", 5))
		iteration = is_bonus(new, fractal);
	return (iteration);
}
