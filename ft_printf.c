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

int ft_printf(const char *fmt, ...)
{
    va_list ap; // Liste d’arguments variables
    int total; // Nombre total de caractères imprimés


if (!fmt) // Si format NULL → erreur
    return (-1);
va_start(ap, fmt); // Démarre la lecture des arguments
total = 0; // Initialisation du compteur
while (*fmt) // Boucle sur toute la chaîne de format
{
    if (*fmt == '%') // Si on rencontre un spécificateur
    {
        fmt++; // Passe au caractère suivant
        if (!*fmt) // Fin de chaîne prématurée
            break ;
        total += do_conversion(*fmt, &ap); // Gère la conversion
        fmt++; // Passe au prochain caractère
    }
    else // Sinon, caractère normal
    {
        write(1, fmt, 1); // Affiche-le
        total++; // Incrémente le compteur
        fmt++; // Passe au suivant
    }
}
va_end(ap); // Termine la lecture d’arguments
return (total); // Retourne le total affiché
}