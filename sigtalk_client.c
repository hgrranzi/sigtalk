/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"

pid_t	check_pid(char *arg_pid)
{
	pid_t	nbr;

	return (nbr);
}

void	send_message(pid_t server_pid, char *message)
{
	return ;
}


int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
		write(1, "Please, provide the server pid and a meesge to send\n", 52);
	else
	{
		server_pid = check_pid(argv[1]);
		send_message(server_pid, argv[2]);
	}
	return (0);
}
