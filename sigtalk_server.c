/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"

void	init_message(t_data *data)
{
	data->str = malloc(BITS * sizeof(unsigned char));
	if (!data->str)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	data->bit = 0;
	data->index = 0;
}

void	handle_signal(int sig_number)
{
	if (sig_number == SIGUSR1)
		write(1, "Signal recieved 0\n", 18);
	else if (sig_number == SIGUSR2)
		write(1, "Signal recieved 1\n", 18);
}

void	wait_for_message(void)
{
	t_data			data;

	init_message(&data);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
	}
	free(data.str);
}

int	main(int argc, char **argv)
{
	pid_t			pid;

	if (argc != 1 || !argv)
		write(2, "Error\n", 6);
	else
	{
		pid = getpid();
		aka_putnbr(pid);
		aka_putchar('\n');
		while (pid)
			wait_for_message();
	}
	return (0);
}
