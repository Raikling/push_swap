#include "ft_printf.h"

void	ft_putnbr(int nbr, int *counter)
{
	if (nbr == -2147483648)
		ft_putstr("-2147483648", counter);
	else if (nbr < 0)
	{
		ft_putchar('-', counter);
		nbr = -nbr;
	}
	else
	{
		if (nbr > 10)
		{
			ft_putnbr(nbr / 10, counter);
			ft_putnbr(nbr % 10, counter);
		}
		else
			ft_putchar((nbr + '0'), counter);
	}
}
