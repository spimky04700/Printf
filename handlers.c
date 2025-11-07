/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillier <tcillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:52:28 by tcillier          #+#    #+#             */
/*   Updated: 2025/11/07 16:52:28 by tcillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_format(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*ap, const char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(*ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*ap, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_base_unsigned(va_arg(*ap, unsigned int), 16, 0));
	if (c == 'X')
		return (ft_putnbr_base_unsigned(va_arg(*ap, unsigned int), 16, 1));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int do_conversion(char spec, va_list *ap)
{
	return (handle_format(spec, ap));
}