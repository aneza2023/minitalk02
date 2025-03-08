/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lodig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:28 by ahavrank          #+#    #+#             */
/*   Updated: 2024/08/14 18:51:11 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c);

int	print_lodig(int i, unsigned int n)
{
	int		count;
	char	*hex_lett;

	count = 0;
	hex_lett = "abcdef";
	if ((unsigned int)i < n)
	{
		if ((unsigned int)i < 10)
			print_char((unsigned int)i + '0');
		else if (n == 16 && (unsigned int)i >= 10)
			print_char(hex_lett[(unsigned int)i - 10]);
		count++;
	}
	else
	{
		count += print_lodig((unsigned int)i / n, n);
		count += print_lodig((unsigned int)i % n, n);
	}
	return (count);
}
