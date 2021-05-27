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

void	aka_putchar(char c);
void	aka_putnbr(int nbr);

void	handle_signal(int sig_number);

pid_t	check_pid(char *arg_pid);
void	send_message(pid_t server_pid, char *message);


#endif
