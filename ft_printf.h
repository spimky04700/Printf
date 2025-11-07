#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdarg.h>
# include <unistd.h>


int ft_printf(const char *fmt, ...);


int ft_putchar(char c);
int ft_putstr(const char *s);
int ft_putnbr(long n);
int ft_putnbr_unsigned(unsigned int n);
int ft_putnbr_base_unsigned(unsigned long val, int base, int upper);
int ft_putptr(void *ptr);
int do_conversion(char spec, va_list *ap);


size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);


#endif