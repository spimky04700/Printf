/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillier <tcillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:46:20 by tcillier          #+#    #+#             */
/*   Updated: 2025/11/07 16:46:20 by tcillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(const char *s)
{
	size_t len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return ((int)len);
}


char *ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}