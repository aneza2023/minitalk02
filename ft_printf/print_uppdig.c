/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uppdig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:01:25 by ahavrank          #+#    #+#             */
/*   Updated: 2024/08/14 18:51:00 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uppdig(int i, unsigned int n)
{
	int		count;
	char	*hex_lett;

	count = 0;
	hex_lett = "ABCDEF";
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
		count += print_uppdig((unsigned int)i / n, n);
		count += print_uppdig((unsigned int)i % n, n);
	}
	return (count);
}
