/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:28:57 by aconti            #+#    #+#             */
/*   Updated: 2024/03/05 08:55:55 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *str1, const char *str2, int n)
{
	int	i;

	i = 0;
	while (i < n && (unsigned char)str1[i] && (unsigned char)str2[i])
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	ft_putstr(char *s)
{
	while (*s != '\0')
		write(1, s++, 1);
}

int	check_param(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] < '.' || str[i] == '/' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	handle_signs(char *str, int *i, int *neg)
{
	if (str[*i] == '-')
		*neg = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}

double	atod(char *str)
{
	double	result;
	double	decimal;
	int		neg;
	int		i;

	i = 0;
	result = 0;
	decimal = 0;
	neg = 1;
	handle_signs(str, &i, &neg);
	if (!check_param(str, i))
		exit (write(1, "Only numbers accepted as params.\n", 33));
	while (str[i] && str[i] != '.')
		result = result * 10 + (double)(str[i++] - 48);
	if (str[i] == '.')
	{
		i++;
		while (str[i])
			decimal = decimal * 10 + (double)(str[i++] - 48);
	}
	while (decimal >= 1)
		decimal /= 10;
	return ((result + decimal) * neg);
}
