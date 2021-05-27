/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"

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
