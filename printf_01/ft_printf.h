#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long int n);
int	ft_putnbr_x(int n);
int	ft_putnbr_xx(int n);
int	ft_putnbr_p(unsigned long n);
int	distinguish(va_list arge, char c);

#endif
