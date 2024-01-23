/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:49:37 by kisikogl          #+#    #+#             */
/*   Updated: 2022/11/24 15:22:03 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

void	write_char(char c);
void	handle_sigusr1(int sig);
void	handle_sigusr2(int sig);
void	give_char(int pid, char *str);
void	send_signals(int pid, char c);

#endif
