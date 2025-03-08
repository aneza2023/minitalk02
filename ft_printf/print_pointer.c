/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:01:36 by ahavrank          #+#    #+#             */
/*   Updated: 2024/09/02 18:58:40 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(uintptr_t i, uintptr_t n)
{
	int		count;
	char	*hex_lett;

	count = 0;
	hex_lett = "abcdef";
	if (i < n)
	{
		if (i < 10)
			print_char(i + '0');
		else if (n == 16 && i >= 10)
			print_char(hex_lett[i - 10]);
		count++;
	}
	else
	{
		count += print_hexa(i / n, n);
		count += print_hexa(i % n, n);
	}
	return (count);
}

int	print_pointer(void *ptr)
{
	uintptr_t	address;
	int			count;

	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	count = 2;
	address = (uintptr_t)ptr;
	write (1, "0x", 2);
	count += print_hexa(address, 16);
	return (count);
}
