/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"

void	handle_signal(sig_number)
{
	if (sig_number)
		write(1, "Signal recieved\n", 16);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 1 || !argv)
		write(1, "The server does not take any parameters.\n", 41);
	else
	{
		pid = getpid();
		aka_putnbr(pid);
		aka_putchar('\n');
		while (pid)
		{
			signal(SIGUSR1, handle_signal);
			signal(SIGUSR2, handle_signal);
		}
	}
	return (0);
}
