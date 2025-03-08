/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:52:37 by ahavrank          #+#    #+#             */
/*   Updated: 2024/08/15 20:06:44 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += (print_char(va_arg(args, int)));
	if (specifier == 's')
		count += (print_string(va_arg(args, char *)));
	if (specifier == 'd')
		count += (print_digit((va_arg(args, int)), 10));
	if (specifier == 'x')
		count += (print_lodig(va_arg(args, int), 16));
	if (specifier == '%')
		count += write (1, "%", 1);
	if (specifier == 'i')
		count += (print_digit((va_arg(args, int)), 10));
	if (specifier == 'X')
		count += (print_uppdig(va_arg(args, int), 16));
	if (specifier == 'u')
		count += (print_unsigndig(va_arg(args, unsigned int), 10));
	if (specifier == 'p')
		count += (print_pointer((void *)(va_arg(args, void *))));
	return (count);
}
