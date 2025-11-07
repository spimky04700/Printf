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


// Fonction interne qui choisit quoi faire selon le caractère de format
static int handle_format(char c, va_list *ap)
{
if (c == 'c') // Caractère
return (ft_putchar((char)va_arg(*ap, int)));
if (c == 's') // Chaîne
return (ft_putstr(va_arg(*ap, const char *)));
if (c == 'p') // Pointeur
return (ft_putptr(va_arg(*ap, void *)));
if (c == 'd' || c == 'i') // Entier signé
return (ft_putnbr(va_arg(*ap, int)));
if (c == 'u') // Entier non signé
return (ft_putnbr_unsigned(va_arg(*ap, unsigned int)));
if (c == 'x') // Hexa minuscule
return (ft_putnbr_base_unsigned(va_arg(*ap, unsigned int), 16, 0));
if (c == 'X') // Hexa majuscule
return (ft_putnbr_base_unsigned(va_arg(*ap, unsigned int), 16, 1));
if (c == '%') // Pourcentage littéral
return (ft_putchar('%'));
return (0); // Autre caractère non géré
}


int do_conversion(char spec, va_list *ap)
{
return (handle_format(spec, ap)); // Délègue à la fonction ci-dessus
}