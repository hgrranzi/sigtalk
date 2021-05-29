/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef SIGTALK_H
# define SIGTALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <string.h>

# define INT_MAX 2147483647
# define BITS 8

typedef struct s_data
{
	unsigned char	*str;
	unsigned char	code;
	int				bit;
	int				index;
	int				size;
}					t_data;

int		aka_isdigit(char c);
void	aka_putchar(char c);
void	aka_putnbr(int nbr);
int		aka_atoi(char *str);

void	handle_signal(int sig_number);

pid_t	check_pid(char *arg_pid);
void	send_message(pid_t server_pid, char *message);

#endif
