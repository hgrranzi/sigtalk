/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"

t_data	g_data;

void	reset_data(t_data *data)
{
	free(data->str);
	data->str = NULL;
	data->code = 0;
	data->client_pid = 0;
	data->str_len = 0;
	data->bit = 0;
	data->index = 0;
}

unsigned char	*create_str(int str_len)
{
	unsigned char	*str;

	str = malloc((str_len + 1) * sizeof(unsigned char));
	if (str)
		str[str_len] = '\0';
	return (str);
}

void	take_int(t_data *data, int *what_take)
{
	if (data->bit == BYTES)
	{
		*what_take = data->code;
		data->code = 0;
		data->bit = 0;
	}
}

void	take_char(t_data *data)
{
	if (!data->str)
	{
		data->str = create_str(data->str_len);
		if (!data->str)
		{
			kill(data->client_pid, SIGUSR2);
			write(1, "Error\n", 6);
			exit(0);
		}
	}
	if (data->bit == BITS)
	{
		data->str[data->index] = data->code;
		data->code = 0;
		data->bit = 0;
		data->index++;
	}
	if (data->index == data->str_len)
	{
		write(1, data->str, data->str_len);
		write(1, "\n", 1);
		usleep(100);
		kill(data->client_pid, SIGUSR1);
		reset_data(data);
	}
}

void	handle_signal(int sig_number)
{
	if (sig_number == SIGUSR2)
		g_data.code |= (1 << g_data.bit);
	g_data.bit++;
	if (!g_data.client_pid)
		take_int(&g_data, &g_data.client_pid);
	else if (!g_data.str_len)
		take_int(&g_data, &g_data.str_len);
	else
		take_char(&g_data);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = &handle_signal;
	g_data.str = NULL;
	g_data.client_pid = 0;
	if (argc != 1 || !argv)
		write(2, "Error\n", 6);
	else
	{
		pid = getpid();
		aka_putnbr(pid);
		aka_putchar('\n');
		reset_data(&g_data);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (pid)
			;
	}
	return (0);
}
