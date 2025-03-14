#include "ft_printf.h"

void	ft_putptr(void *ptr, int *counter)
{
	unsigned long	add;

	if (!ptr)
	{
		ft_putstr("0x0", counter);
		return ;
	}
	add = (unsigned long)ptr;
	ft_putstr("0x1", counter);
	ft_puthex(add, 0, counter);
}
