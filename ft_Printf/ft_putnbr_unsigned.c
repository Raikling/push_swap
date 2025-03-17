#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int ui, int *counter)
{
	if (ui > 10)
		ft_putnbr_unsigned(ui / 10, counter);
	ft_putchar((ui % 10) + '0', counter);
}
