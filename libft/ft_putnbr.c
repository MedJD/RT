
#include "libft.h"

void	ft_putnbr(int n)
{
	int chfr;
	int one;

	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n == -2147483648)
	{
		ft_putchar(50);
		n = 147483648;
	}
	chfr = 1;
	one = n;
	while ((one /= 10) != 0)
		chfr *= 10;
	while (chfr != 0)
	{
		one = n / chfr;
		n %= chfr;
		chfr /= 10;
		ft_putchar(one + '0');
	}
}
