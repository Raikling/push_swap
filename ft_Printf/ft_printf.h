#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchar(char c, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_putnbr(int nbr, int *counter);
void	ft_puthex(unsigned int nbr, int cas, int *counter);
void	ft_putptr(void *ptr, int *counter);
void	ft_putnbr_unsigned(unsigned int ui, int *counter);
int		ft_printf(const char *format, ...);

#endif
