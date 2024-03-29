/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atedesch <atedesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:16:05 by atedesch          #+#    #+#             */
/*   Updated: 2024/02/22 21:19:21 by atedesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned long long n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static void	print_pointer(unsigned long long n)
{
	if (n > 15)
	{
		print_pointer(n / 16);
		print_pointer(n % 16);
	}
	else if (n > 9)
		ft_putchar(n + 'a' - 10);
	else
		ft_putchar(n + '0');
}

int	ft_putpointer(unsigned long long n)
{
	if (n == 0)
		return (ft_putstr(NIL_STRING));
	ft_putstr("0x");
	print_pointer(n);
	return (get_size(n) + 2);
}
