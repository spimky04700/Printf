/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillier <tcillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:54:24 by tcillier          #+#    #+#             */
/*   Updated: 2025/11/07 16:54:24 by tcillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	int total;

	if (!format)
		return (-1);
	va_start(args, format);
	total = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			total += do_conversion(*format, &args);
			format++;
		}
		else
		{
			write(1, format, 1);
			total++;
			format++;
		}
	}
	va_end(args);
	return (total);
}