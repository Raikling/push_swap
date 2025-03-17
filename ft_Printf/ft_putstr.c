#include "ft_printf.h"

void	ft_putstr(char *str, int *counter)
{
	while (*str)
	{
		ft_putchar(*str, counter);
		str++;
	}
}
