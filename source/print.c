/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:06:21 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/14 08:03:04 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print(t_args *args, int address, int type, int *fork)
{
	pthread_mutex_lock(&args->program->print_mutex);
	if (EATING == type)
		print_eating(args, address);
	else if (SLEEPING == type)
		print_sleeping(args, address);
	else if (CODING == type)
		print_coding(args, address);
	else if (FORK_PICKED_UP == type)
		print_fork_picked_up(args, address, fork);
	else if (FORK_RETURNED == type)
		print_fork_returned(args, address, fork);
	else if (DIED == type)
		print_died(args, address);
	else if (COMPLETE == type)
		print_complete(args, address);
	pthread_mutex_unlock(&args->program->print_mutex);
}

void	print_sleeping(t_args *args, int address)
{
	t_u64	stamp;

	stamp = get_time() - args->program->starttime;
	printf("\e[0;32mTIMESTAMP: %10lld - ", stamp);
	printf("\e[1;37mPsycho Number %d ", address + 1);
	printf("\e[1;33mis sleeping\n\e[0;m");
}

void	print_eating(t_args *args, int address)
{
	t_u64	stamp;

	stamp = get_time() - args->program->starttime;
	printf("\e[0;32mTIMESTAMP: %10lld - ", stamp);
	printf("\e[1;37mPsycho Number %d ", address + 1);
	printf("\e[1;31mis eating\n\e[0;m");
}

void	print_coding(t_args *args, int address)
{
	t_u64	stamp;

	stamp = get_time() - args->program->starttime;
	printf("\e[0;32mTIMESTAMP: %10lld - ", stamp);
	printf("\e[1;37mPsycho Number %d ", address + 1);
	printf("\e[1;34mis coding\n\e[0;m");
}
