/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"

int	aka_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	aka_putchar(char c)
{
	write(1, &c, 1);
}

void	aka_putnbr(int nbr)
{
	if (nbr < 0)
	{
		aka_putchar('-');
		aka_putnbr(-1 * nbr);
	}
	else
	{
		if (nbr > 9)
			aka_putnbr(nbr / 10);
		aka_putchar(nbr % 10 + 48);
	}
}

size_t	aka_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	aka_atoi(char *str)
{
	long	nbr;
	long	sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] && aka_isdigit(str[i]) && nbr <= INT_MAX)
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (!i || str[i] != '\0' || nbr > INT_MAX)
		sign = -1;
	return ((int)(nbr * sign));
}
