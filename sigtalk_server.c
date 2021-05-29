/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "sigtalk.h"

t_data	g_data;

void	init_message(t_data *data)
{
	data->str = malloc((BITS + 1) * sizeof(unsigned char));
	if (!data->str)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	bzero(data->str, BITS + 1); // need to weite my own function
	data->code = 0;
	data->bit = 0;
	data->index = 0;
	data->size = BITS + 1;
}

int	is_full(t_data *data)
{
	return (data->index == data->size);
}

void	resize_str(t_data *data)
{
	unsigned char	*new_str;
	int				i;

	new_str = malloc((data->index + BITS) * sizeof(unsigned char));
	if (!new_str)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	bzero(new_str, data->index + BITS); // my own
	i = 0;
	while (i < data->index)
	{
		new_str[i] = data->str[i];
		i++;
	}
	free(data->str);
	data->str = new_str;
}

void	add_byte(t_data *data)
{
	if (is_full(data))
		resize_str(data);
	data->str[data->index] = data->code;
	if (data->str[data->index] == 0)
	{
		write(1, data->str, aka_strlen((char *)data->str));
		write(1, "\n", 1);
		free(data->str);
		data->str = NULL;
	}
	data->index++;
	data->code = 0;
	data->bit = 0;
}

void	handle_signal(int sig_number)
{
	if (sig_number == SIGUSR2)
		g_data.code |= (1 << g_data.bit);
	g_data.bit++;
	if (g_data.bit == BITS)
		add_byte(&g_data);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = &handle_signal;
	g_data.str = NULL;
	if (argc != 1 || !argv)
		write(2, "Error\n", 6);
	else
	{
		pid = getpid();
		aka_putnbr(pid);
		aka_putchar('\n');
		while (pid)
		{
			if (!g_data.str)
				init_message(&g_data);
			sigaction(SIGUSR1, &sa, NULL);
			sigaction(SIGUSR2, &sa, NULL);
		}
	}
	return (0);
}
