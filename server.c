/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:31:03 by ahavrank          #+#    #+#             */
/*   Updated: 2025/03/08 18:51:10 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <string.h>

char	*g_string;

void	handle_string(char letter)
{
	int	j;

	if (letter != '\0')
	{
		if (g_string == NULL)
		{
			g_string = malloc(sizeof(char) * 2);
			g_string[0] = letter;
			g_string[1] = '\0';
		}
		else
			g_string = ft_strjoin(g_string, letter);
	}
	else if (letter == '\0')
	{
		j = 0;
		while (g_string[j] != '\0')
		{
			write (1, &g_string[j], 1);
			j++;
		}
		free(g_string);
		g_string = NULL;
	}
}

void	handle_signal_sigusr1(int signal)
{
	static int	k;
	static char	letter;

	if (k <= 7 && signal == SIGUSR1)
	{
		letter |= (1 << k);
	}
	if (k == 7)
	{
		handle_string(letter);
		k = -1;
		letter = 0;
	}
	k++;
}

int	main(void)
{
	g_string = NULL;
	ft_printf("PID of server: %d\n", getpid());
	signal(SIGUSR1, handle_signal_sigusr1);
	signal(SIGUSR2, handle_signal_sigusr1);
	while (1)
	{
	}
	return (0);
}
