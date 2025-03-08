/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:07:36 by anezkahavra       #+#    #+#             */
/*   Updated: 2024/08/14 18:46:54 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		count = 6;
	}
	while (s != NULL && s[count] != '\0')
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}
