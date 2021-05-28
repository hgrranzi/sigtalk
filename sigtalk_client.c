/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"
#include <stdio.h>
#include <string.h>

void	send_char(pid_t server_pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < BITS)
	{
		if (c & 128)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		c = c << 1;
		i++;
		sleep(1);
	}
}

void	send_message(pid_t server_pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(server_pid, (unsigned char)message[i]);
		i++;
	}
	send_char(server_pid, (unsigned char)message[i]);
}

int	main(int argc, char **argv)
{
	pid_t			server_pid;

	if (argc != 3)
		write(2, "Error\n", 6);
	else
	{
		server_pid = aka_atoi(argv[1]);
		if (server_pid)
			send_message(server_pid, argv[2]);
		else
			write(2, "Error\n", 6);
	}
	return (0);
}
