#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (!write(1, &c, 1))
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long int n)
{
	long int	m;
	int			count;

	m = n;
	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	while (m < -9 || m > 9)
	{
		m = m / 10;
		count++;
	}
	return (count + 1);
}

int	ft_putnbr_p(unsigned long n)
{
	unsigned long	m;
	int				count;

	m = n;
	count = 0;
	if (n > 15)
	{
		ft_putnbr_p(n / 16);
		ft_putnbr_p(n % 16);
	}
	else
		ft_putchar("0123456789abcdef"[n % 16]);
	while (m > 15)
	{
		m = m / 16;
		count++;
	}
	return (count + 1);
}

int	ft_putnbr_x(int n)
{
	unsigned int	m;
	int				count;
	unsigned int	o;

	o = (unsigned int)n;
	m = o;
	count = 0;
	if (o > 15)
	{
		ft_putnbr_x(o / 16);
		ft_putnbr_x(o % 16);
	}
	else
		ft_putchar("0123456789abcdef"[n % 16]);
	while (m > 15)
	{
		m = m / 16;
		count++;
	}
	return (count + 1);
}
