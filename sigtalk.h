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
# define BYTES 32

typedef struct s_data
{
	unsigned char	*str;
	int				code;
	int				client_pid;
	int				str_len;
	int				bit;
	int				index;
}					t_data;

int		aka_isdigit(char c);
void	aka_putchar(char c);
void	aka_putnbr(int nbr);
size_t	aka_strlen(const char *s);
int		aka_atoi(char *str);

void	handle_signal(int sig_number);

pid_t	check_pid(char *arg_pid);
void	send_message(pid_t server_pid, char *message);
void	send_int(pid_t server_pid, int nbr);
void	send_char(pid_t server_pid, unsigned char c);

#endif
