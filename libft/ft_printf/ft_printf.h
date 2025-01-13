
#ifndef FT_PRINTF_A
#define FT_PRINTF_A

#include <unistd.h>
#include <stdio.h>
#include "../libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int ft_pick(va_list args,char format);

int    ft_printf(const char *str, ...);

int ft_putchar(char c);

int ft_uint(unsigned int nbr);

int ft_printadress(void *n,char *format);

int ft_dividenbr(int d);

int ft_putstr(char *str);

char	*ft_putunsignednbr(unsigned int n);

int	ft_putnbr(int n);

int ft_putnbrbase(unsigned int n, char *format);

int ft_putnbrbasep(unsigned long long n, char *format);

int ft_dividenbrbase(long long int n, int base);

size_t  ft_putnbr_unsigned(unsigned int n);

#endif
