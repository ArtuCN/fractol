/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:10:43 by aconti            #+#    #+#             */
/*   Updated: 2024/02/13 21:57:23 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//4:800 = x : 500
// in map no old min for normie

void	my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * image->line_length + x * (image->bits_per_pixel / 8));
		*(unsigned int *)(image->addr + offset) = color;
	}
}

void	handle_pix(int x, int y, t_fractal *fractal)
{
	t_complex	new;
	int			iteration;
	int			color;

	new.real = (map (x, PIANOXP, PIANOXG, WIDTH)
			* fractal->zoom + fractal->shift_x);
	new.immaginary = (map (y, PIANOYG, PIANOYP, HEIGHT)
			* fractal->zoom + fractal->shift_y);
	iteration = iter_render(new, fractal);
	color = map (iteration, BLACK, WHITE, MAXITERATION + fractal->mod);
	my_pixel_put (x + fractal->shift_x, y + fractal->shift_y,
		&fractal->image, color);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pix (x, y, fractal);
	}
	mlx_put_image_to_window (fractal->mlx_connection, fractal->mlx_window,
		fractal->image.img_ptr, 0, 0);
}
