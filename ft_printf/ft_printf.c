/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:25:21 by ahavrank          #+#    #+#             */
/*   Updated: 2024/09/02 18:46:27 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), args);
		else
		{
			write (1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{
	// char *ptr = NULL;

	printf("%p", 0);

	return (0);
} */
