/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:32:48 by ahavrank          #+#    #+#             */
/*   Updated: 2025/03/06 12:47:25 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include "ft_printf.h" 

int		ft_atoi(const char *nptr);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char letter);

#endif