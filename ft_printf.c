/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:38:53 by mel-kouc          #+#    #+#             */
/*   Updated: 2022/11/17 23:02:06 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		lenprint;

	i = 0;
	lenprint = 0;
	if (write(1, NULL, 0))
		return (-1);
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			ft_format(args, str[i + 1], &lenprint);
			i++;
		}
		else
			ft_putchar(str[i], &lenprint);
		i++;
	}
	va_end (args);
	return (lenprint);
}
