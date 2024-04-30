/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:25:36 by aconti            #+#    #+#             */
/*   Updated: 2024/01/22 18:52:15 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-> or .

-> ptr
. no ptr


 ALL CASES NULL == fractal->something should be in a function for normy

	?	ENDIAN	?

*/

#include "fractol.h"

void	malloc_error(void)
{
	ft_putstr ("Malloc error!");
	exit (1);
}

void	data_init(t_fractal *fractal)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->mod = 1;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window (fractal->mlx_connection, WIDTH,
			HEIGHT, fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display (fractal->mlx_connection);
		free (fractal->mlx_connection);
		malloc_error();
	}
	fractal->image.img_ptr = mlx_new_image (fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (NULL == fractal->image.img_ptr)
	{
		mlx_destroy_window (fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display (fractal->mlx_connection);
		free (fractal->mlx_connection);
		malloc_error();
	}
	fractal->image.addr = mlx_get_data_addr(fractal->image.img_ptr,
			&fractal->image.bits_per_pixel,
			&fractal->image.line_length, &fractal->image.endian);
	events(fractal);
	data_init(fractal);
}
