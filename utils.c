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
size_t i; // Compteur d'index


i = 0; // Initialisation à 0
if (!s) // Vérifie si le pointeur est nul
return (0); // Si oui, retourne 0
while (s[i]) // Parcourt la chaîne jusqu'au '\0'
i++; // Incrémente le compteur
return (i); // Retourne la longueur totale
}


int ft_putchar(char c)
{
write(1, &c, 1); // Écrit un caractère sur la sortie standard
return (1); // Retourne 1 car un seul caractère est affiché
}


int ft_putstr(const char *s)
{
size_t len; // Variable pour stocker la longueur


if (!s) // Si la chaîne est nulle
{
write(1, "(null)", 6); // Affiche (null)
return (6); // Retourne 6 car c’est le nombre de caractères imprimés
}
len = ft_strlen(s); // Calcule la longueur de la chaîne
write(1, s, len); // Écrit toute la chaîne sur la sortie standard
return ((int)len); // Retourne le nombre de caractères écrits
}


char *ft_strcpy(char *dst, const char *src)
{
int i; // Index de parcours


i = 0; // Initialisation
while (src[i]) // Tant qu’on n’atteint pas la fin de src
{
dst[i] = src[i]; // Copie chaque caractère
i++; // Incrémente
}
dst[i] = '\0'; // Termine la chaîne par un caractère nul
return (dst); // Retourne le pointeur de destination
}