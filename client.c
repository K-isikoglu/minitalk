/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:34:15 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/29 15:57:31 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	get_error(int count, char *args[])
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (count != 3)
		return ('A');
	while (i < (int)ft_strlen(args[1]))
	{
		if (!ft_isdigit(args[1][i]))
			return ('P');
		else if (args[1][i] == '0')
			k++;
		i++;
	}
	if (k == i)
		return ('P');
	return (0);
}

void	give_char(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		send_signals(pid, str[i]);
		i++;
	}
	send_signals(pid, '\n');
}

void	send_signals(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		if ((c & 1) == 0)
		{
			if (kill(pid, SIGUSR1) != 0)
			{
				ft_printf("Error: kill failed.\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)
			{
				ft_printf("Error: Kill failed.\n");
				exit(1);
			}
		}
		c >>= 1;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	char	err;

	err = get_error(argc, argv);
	if (err == 0)
	{
		give_char(ft_atoi(argv[1]), argv[2]);
	}
	else if (err == 'A')
	{
		ft_printf("Error: Give me the PID and the string to send.\n");
		return (1);
	}
	else if (err == 'P')
	{
		ft_printf("Error: What is this pid?\n");
		return (1);
	}
	return (0);
}
