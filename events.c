/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:47:34 by aconti            #+#    #+#             */
/*   Updated: 2024/03/05 09:00:53 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
		fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
		fractal->mlx_window);
	mlx_destroy_display (fractal-> mlx_connection);
	free (fractal-> mlx_connection);
	ft_putstr ("\nFinestra chiusa! :)\n");
	exit (EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 65307)
		close_window (fractal);
	else if ((keysym == LEFT || keysym == RIGHT || keysym == UP
			|| keysym == DOWN) || ((!ft_strncmp (fractal->name, "julia", 6))
			&& (keysym == L || keysym == K || keysym == N || keysym == M)))
		arrow_julia(keysym, fractal);
	else if (keysym == J)
		fractal->name = "julia";
	else if (keysym == F)
		fractal->name = "mandelbrot";
	else if (keysym == Q)
		fractal->shift_y = 0.0;
	if (keysym == Q)
		fractal->shift_x = 0.0;
	else if (keysym == P)
		fractal->mod += 50;
	else if (keysym == O)
		fractal->mod -= 50;
	else if (keysym == X)
		fractal->name = "bonus";
	mlx_clear_window (fractal->mlx_connection, fractal->mlx_window);
	fractal_render (fractal);
	return (0);
}

int	mouse_track(int x, int y, t_fractal *fractal)
{
	fractal->mouse_imag = y;
	fractal->mouse_real = x;
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_real;
	double	mouse_imag;
	double	new_mouse_real;
	double	new_mouse_imag;

	mouse_real = map (x, PIANOXP, PIANOXG, WIDTH)
		* fractal->zoom + fractal->shift_x;
	mouse_imag = map (y, PIANOYG, PIANOYP, HEIGHT)
		* fractal->zoom + fractal->shift_y;
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	new_mouse_real = map (x, PIANOXP, PIANOXG, WIDTH)
		* fractal->zoom + fractal->shift_x;
	new_mouse_imag = map (y, PIANOYG, PIANOYP, HEIGHT)
		* fractal->zoom + fractal->shift_y;
	fractal->shift_x += mouse_real - new_mouse_real;
	fractal->shift_y += mouse_imag - new_mouse_imag;
	fractal_render (fractal);
	return (0);
}

void	events(t_fractal *fractal)
{
	mlx_key_hook (fractal->mlx_window, key_handler, fractal);
	mlx_hook (fractal->mlx_window, 17, 1L << 2, close_window, fractal);
	mlx_mouse_hook (fractal->mlx_window, mouse_handler, fractal);
	mlx_hook (fractal->mlx_window, MotionNotify, PointerMotionMask,
		mouse_track, fractal);
}
