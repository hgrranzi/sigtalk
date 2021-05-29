/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"

void	send_char(pid_t server_pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < BITS)
	{
		if (c & 01)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(50);
	}
}

void	recieved(int sig_number)
{
	if (sig_number == SIGUSR1)
		write(1, "Message was successfully delivered.\n", 36);
	exit(0);
}

void	send_int(pid_t server_pid, int nbr)
{
	int	i;
	int	kill_return;

	i = BYTES;
	while (i > 0)
	{
		if (nbr & 01)
			kill_return = kill(server_pid, SIGUSR2);
		else
			kill_return = kill(server_pid, SIGUSR1);
		if (kill_return == -1)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		nbr = nbr >> 1;
		i--;
		usleep(50);
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
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = &recieved;
	if (argc != 3)
		write(2, "Error\n", 6);
	else
	{
		pid = getpid();
		server_pid = aka_atoi(argv[1]);
		if (server_pid)
		{
			send_int(server_pid, pid);
			send_int(server_pid, aka_strlen(argv[2]));
			send_message(server_pid, argv[2]);
			while (pid)
				sigaction(SIGUSR1, &sa, NULL);
		}
		else
			write(2, "Error\n", 6);
	}
	return (0);
}
