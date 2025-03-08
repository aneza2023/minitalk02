/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:55:03 by ahavrank          #+#    #+#             */
/*   Updated: 2024/08/14 18:09:33 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_digit(int i, int n);
int	print_format(char specifier, va_list args);
int	print_lodig(int i, unsigned int n);
int	print_hexa(uintptr_t i, uintptr_t n);
int	print_string(char *s);
int	print_unsigndig(int i, int n);
int	print_uppdig(int i, unsigned int n);
int	print_pointer(void *ptr);

#endif
