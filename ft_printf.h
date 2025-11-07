#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdarg.h> // Pour la gestion des arguments variables
# include <unistd.h> // Pour la fonction write()


// Prototype principal de ft_printf
int ft_printf(const char *fmt, ...);


// Fonctions utilitaires d'affichage
int ft_putchar(char c); // Affiche un caractère
int ft_putstr(const char *s); // Affiche une chaîne
int ft_putnbr(long n); // Affiche un nombre signé
int ft_putnbr_unsigned(unsigned int n); // Affiche un entier non signé
int ft_putnbr_base_unsigned(unsigned long val, int base, int upper); // Affiche en base donnée
int ft_putptr(void *ptr); // Affiche une adresse mémoire (pointeur)
int do_conversion(char spec, va_list *ap); // Gère les conversions selon le spécificateur


// Fonctions de manipulation de chaînes
size_t ft_strlen(const char *s); // Calcule la longueur d'une chaîne
char *ft_strcpy(char *dst, const char *src); // Copie une chaîne dans une autre


#endif