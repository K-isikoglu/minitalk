/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:23:30 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/29 15:55:48 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr1(int sig)
{
	sig = sig + 0;
	write_char(0);
}

void	handle_sigusr2(int sig)
{
	sig = sig + 0;
	write_char(1);
}

void	handle_kill(int sig)
{
	sig = sig + 0;
	ft_printf("\nProcess terminated, Server stopped...\n");
	exit(0);
}

void	write_char(char c)
{
	static char	ch = 0;
	static int	i = 0;

	if (i < 7)
	{
		if (c == 1)
		{
			ch += 1 << i;
		}
		i++;
	}
	if (i == 7)
	{
		write(1, &ch, 1);
		ch = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Server started. Server process ID: %d\n", getpid());
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	signal(SIGINT, handle_kill);
	while (1)
	{
		pause();
	}
	return (0);
}
