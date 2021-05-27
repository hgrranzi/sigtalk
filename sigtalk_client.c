/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"

void	send_message(pid_t server_pid, char *message)
{
	if (server_pid && message)
		kill(server_pid, SIGUSR1);
	return ;
}


int	main(int argc, char **argv)
{
	pid_t	server_pid;

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
