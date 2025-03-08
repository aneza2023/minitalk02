/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:30:45 by anezkahavra       #+#    #+#             */
/*   Updated: 2024/08/14 18:50:05 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c);

int	print_digit(int i, int n)
{
	int		count;

	count = 0;
	if (i >= 0 && i < n)
	{
		print_char(i + '0');
		count++;
	}
	else if (i == -2147483648)
	{
		write (1, "-2147483648", 11);
		count += 11;
	}
	else if (i < 0 && n == 10)
	{
		count += write (1, "-", 1);
		count += print_digit(i * (-1), n);
	}
	else
	{
		count += print_digit(i / n, n);
		count += print_digit(i % n, n);
	}
	return (count);
}
