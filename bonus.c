/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:15:31 by aconti            #+#    #+#             */
/*   Updated: 2024/01/22 18:58:32 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	bonus_calculate_it(t_complex t, t_complex c)
{
	t_complex	result;

	result.real = t.real * t.real - t.immaginary * t.immaginary + c.real;
	result.immaginary = 2 * t.real * t.immaginary + c.immaginary;
	if (result.real > 0)
		result.real *= -1;
	if (result.immaginary < 0)
		result.immaginary *= -1;
	return (result);
}
