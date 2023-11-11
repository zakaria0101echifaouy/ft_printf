/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:29:36 by zech-chi          #+#    #+#             */
/*   Updated: 2023/11/11 17:58:43 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(unsigned long n, int baseValue, const char *base, int *counter)
{
	if (n < 0)
	{
		ft_putchar('-', counter);
		n *= -1;
	}
	if (n < (unsigned long)baseValue)
	{
		ft_putchar(base[n], counter);
	}
	else
	{
		ft_convert(n / baseValue, baseValue, base, counter);
		ft_convert(n % baseValue, baseValue, base, counter);
	}
}