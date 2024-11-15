#include "ft_printf.h"

int	ft_putnbr_xx(int n)
{
	unsigned int	m;
	int				count;
	unsigned int	o;
	int				test;

	o = (unsigned int)n;
	m = o;
	count = 0;
	if (o > 15)
	{
		ft_putnbr_xx(o / 16);
		ft_putnbr_xx(o % 16);
	}
	else
	{
		test = ft_putchar("0123456789ABCDEF"[n % 16]);
		if (test == -1)
			return (-1);
	}
	while (m > 15)
	{
		m = m / 16;
		count++;
	}
	return (count + 1);
}

int	distinguish(va_list arge, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(arge, int));
	if (c == 's')
		i = ft_putstr(va_arg(arge, char *));
	if (c == 'p')
	{
		ft_putstr("0x");
		i = ft_putnbr_p(va_arg(arge, unsigned long long)) + 2;
	}
	if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(arge, int));
	if (c == 'u')
		i = ft_putnbr(va_arg(arge, unsigned int));
	if (c == 'x')
		i = ft_putnbr_x(va_arg(arge, int));
	if (c == 'X')
		i = ft_putnbr_xx(va_arg(arge, int));
	if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	arge;
	int		printed_chars;
	int		i;
	int		count;
	int		check;

	i = -1;
	check = 0;
	count = 0;
	va_start(arge, format);
	printed_chars = 0;
	while (format[++i] != '\0')
	{
		check = count;
		if (format[i] != '%')
			count += ft_putchar(format[i]);
		else
			count += distinguish(arge, format[++i]);
		if (check > count)
			return (-1);
	}
	return (count);
}
