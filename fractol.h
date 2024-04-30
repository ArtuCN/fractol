/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:41:53 by aconti            #+#    #+#             */
/*   Updated: 2024/02/13 21:57:56 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 1000
# define HEIGHT 500
# define PIANOXG 5
# define PIANOXP -5
# define PIANOYG 2.5
# define PIANOYP -2.5
# define MAXITERATION 350
# define EXIT_SUCCESS 0

# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)
// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red
//define key
# define A 97
# define B 98
# define C 99
# define D 100
# define E 101
# define F 102
# define G 103
# define H 104
# define I 105
# define J 106
# define K 107
# define L 108
# define M 109
# define N 110
# define O 111
# define P 112
# define Q 113
# define R 114
# define S 115
# define T 116
# define U 117
# define V 118
# define W 119
# define X 120
# define Y 121
# define Z 122

# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
//define message
# define INPUT_ERROR "Please type 'mandelbrot' or 'julia x y' or 'bonus'"

typedef struct s_complex
{
	double	real;
	double	immaginary;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	image;
	double	shift_y;
	double	shift_x;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		mod;
	double	mouse_imag;
	double	mouse_real;
}	t_fractal;

//init
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		malloc_error(void);
//render
void		fractal_render(t_fractal *fractal);
void		handle_pix(int x, int y, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_image *image, int color);
//events
int			key_handler(int keysym, t_fractal *fractal);
int			close_window(t_fractal *fractal);
void		events(t_fractal *fractal);
int			mouse_track(int x, int y, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
//str
double		atod(char *str);
int			ft_strncmp(const char *str1, const char *str2, int n);
void		ft_putstr(char *s);
//math
int			is_julia(t_complex n, t_fractal *fractal);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
int			is_mandelbrot(t_complex n, t_fractal *fractal);
int			is_bonus(t_complex n, t_fractal *fractal);

t_complex	calculate_iteration(t_complex t, t_complex n);
//other utils
int			arrow_julia(int keysym, t_fractal *fractal);
int			iter_render(t_complex new, t_fractal *fractal);
//bonus
t_complex	bonus_calculate_it(t_complex t, t_complex c);

#endif