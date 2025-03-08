/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigndig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:01:46 by ahavrank          #+#    #+#             */
/*   Updated: 2024/08/15 21:34:49 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	tobinary(unsigned int i)
{
	int bin0;
    int bin1;
    int reminder;
    bin0 = 0;
    bin1 = 1;
    while (i != '\0')
    {
        reminder = i % 2;
        i = i / 2;
        bin0 = bin0 + reminder * bin1;
        bin1 = bin1 * 10;
    }
	return (bin1);
} */

int	print_unsigndig(int i, int n)
{
	unsigned int	unint;
	int				count;

	unint = ((unsigned int)i);
	count = 0;
	if (unint >= 0 && unint < 10)
	{
		print_char(unint + '0');
		count++;
	}
	else
	{
		count += print_unsigndig(unint / n, n);
		count += print_unsigndig(unint % n, n);
	}
	return (count);
}
