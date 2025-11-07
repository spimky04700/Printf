*This project has been created as part of the 42 curriculum by Tcillier*

[![42](https://img.shields.io/badge/42-Project-blue)](https://www.42.fr/)

## Description

`ft_printf` est une réimplémentation simplifiée de la fonction standard `printf` en C.  
Le projet vise à reproduire le comportement du `printf` original avec :

- Un nombre limité de conversions (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`)  

---

## Fonctionnalités

- Affichage de caractères, chaînes, nombres signés et non signés, pointeurs, et  pourcentage.
- Support complet des cas limites :
  - Chaînes ou pointeurs `NULL`  
  - Zéros et nombres négatifs  
  - Grands nombres (`UINT_MAX`)  
- Comparaison visuelle et retour de valeurs avec `printf` 

---

## Compilation

make          # Compile la librairie libftprintf.a
make test     # Compile et exécute main.c avec la lib
make clean    # Supprime les fichiers objets
make fclean   # Supprime objets + lib + binaire de test
make re       # Nettoie et reconstruit

---

## Exemples d'usage

/*#include "ft_printf.h"

int main(void)
{
    int ret;

    ret = ft_printf("Hello %s, number: %d, pointer: %p\n", "World", 42, &ret);
    ft_printf("Nombre de caractères affichés : %d\n", ret);

    return 0;
}*/
