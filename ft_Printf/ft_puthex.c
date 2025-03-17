#include "ft_printf.h"

void	ft_puthex(unsigned int nbr, int cas, int *counter)
{
	char	*hex_base;

	if (cas == 1)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	if (nbr >= 16)
		ft_puthex(nbr / 16, cas, counter);
	ft_putchar(hex_base[nbr % 16], counter);
}
