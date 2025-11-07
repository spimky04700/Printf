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
int count; // Compteur de caractères imprimés


count = 0; // Initialisation
if (n < 0) // Si le nombre est négatif
{
count += ft_putchar('-'); // Affiche le signe négatif
n = -n; // Passe le nombre en positif
}
if (n >= 10) // Tant que le nombre a plus d’un chiffre
count += ft_putnbr(n / 10); // Appel récursif sur la partie entière
count += ft_putchar((n % 10) + '0'); // Affiche le dernier chiffre
return (count); // Retourne le total affiché
}

int ft_putnbr_unsigned(unsigned int n)
{
int count; // Compteur de caractères

count = 0; // Initialisation
if (n >= 10) // Si plus d’un chiffre
count += ft_putnbr_unsigned(n / 10); // Affiche les chiffres avant
count += ft_putchar((n % 10) + '0'); // Affiche le dernier chiffre
return (count); // Retourne le total
}


int ft_putnbr_base_unsigned(unsigned long val, int base, int upper)
{
char buffer[32]; // Buffer pour stocker les chiffres à inverser
char digits[17]; // Liste des caractères possibles (base)
int count; // Nombre total de caractères
int i; // Index temporaire


if (upper == 1) // Si on veut des majuscules
ft_strcpy(digits, "0123456789ABCDEF"); // Copie l’alphabet majuscule
else // Sinon, alphabet minuscule
ft_strcpy(digits, "0123456789abcdef");
i = 0; // Initialise le compteur
if (val == 0) // Si le nombre est 0
buffer[i++] = '0'; // Stocke '0'
while (val > 0) // Tant qu’il reste des chiffres
{
buffer[i++] = digits[val % base]; // Stocke le chiffre correspondant
val /= base; // Réduit le nombre
}
count = i; // Nombre de caractères à afficher
while (i-- > 0) // Parcourt à l’envers (car on a inversé l’ordre)
write(1, &buffer[i], 1); // Affiche chaque chiffre
return (count); // Retourne le nombre total de caractères écrits
}


int ft_putptr(void *ptr)
{
unsigned long val; // Conversion du pointeur en entier
int count; // Nombre total affiché


if (!ptr) // Si pointeur nul
{
write(1, "(nil)", 5); // Affiche (nil)
return (5); // Retourne 5
}
val = (unsigned long)ptr; // Convertit en entier
write(1, "0x", 2); // Préfixe des pointeurs
count = 2; // On a déjà affiché 2 caractères
count += ft_putnbr_base_unsigned(val, 16, 0); // Affiche l’adresse en hexa
return (count); // Retourne le total
}