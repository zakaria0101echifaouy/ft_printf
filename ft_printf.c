/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:03:04 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/11 01:23:36 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// va_arg(args, type ) type = int or char or char * ...

int	ft_printf(const char * str, ...)
{
	size_t	i;
	int	counter;
	va_list	args;
	va_start(args, str);

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &counter);
		else
		{
			i++;
			if (str[i] == '\0')
				break;
			else if (str[i] == '%')
				ft_putchar('%', &counter);
			else if (str[i] == 'c')
				ft_putchar((char)va_arg(args, int), &counter);
			else if (str[i] == 's')
				ft_putstr(va_arg(args, char *), &counter);
			//else if (str[i] == 'p')
			//	continue;
			else if (str[i] == 'd')
				ft_convert(va_arg(args, int), 10, "0123456789", &counter);
			else if (str[i] == 'i')
				ft_convert(va_arg(args, int), 10, "0123456789", &counter);
			else if (str[i] == 'u')
				ft_convert((long)(va_arg(args, unsigned int)), 10, "0123456789", &counter);
			else if (str[i] == 'x')
				ft_convert((long)(va_arg(args, unsigned int)), 16, "0123456789abcdef", &counter);
			else if (str[i] == 'X')
				ft_convert((long)(va_arg(args, unsigned int)), 16, "0123456789ABCDEF", &counter);
		}
		if (str[i])
			i++;
	}
	va_end(args);
	return (counter);
}
