/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillier <tcillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:47:18 by tcillier          #+#    #+#             */
/*   Updated: 2025/11/07 16:47:18 by tcillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(long n)
{
	int count;


	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10) + '0');
	return (count);
}

int ft_putnbr_unsigned(unsigned int n)
{
	int count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
		count += ft_putchar((n % 10) + '0');
	return (count);
}

int ft_putnbr_base_unsigned(unsigned long val, int base, int upper)
{
	char buffer[32];
	char digits[17];
	int count;
	int i;

	if (upper == 1)
		ft_strcpy(digits, "0123456789ABCDEF");
	else
		ft_strcpy(digits, "0123456789abcdef");
	i = 0;
	if (val == 0)
		buffer[i++] = '0';
	while (val > 0)
	{
		buffer[i++] = digits[val % base];
		val /= base;
	}
	count = i;
	while (i-- > 0) 
		write(1, &buffer[i], 1);
	return (count);
}

int ft_putptr(void *ptr)
{
	unsigned long val;
	int count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	val = (unsigned long)ptr;
	write(1, "0x", 2);
	count = 2;
	count += ft_putnbr_base_unsigned(val, 16, 0);
	return (count);
}