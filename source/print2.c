/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 07:56:21 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/14 08:22:45 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_fork_returned(t_args *args, int address, int *fork)
{
	t_u64	stamp;

	stamp = get_time() - args->program->starttime;
	printf("\e[0;32mTIMESTAMP: %10lld - ", stamp);
	printf("\e[1;37mPsycho Number %d ", address + 1);
	printf("\e[1;32mhas returned fork %d\n\e[0;m", *fork + 1);
}

void	print_died(t_args *args, int address)
{
	t_u64	stamp;

	stamp = get_time() - args->program->starttime;
	printf("\e[0;32mTIMESTAMP: %10lld - ", stamp);
	printf("\e[1;37mPsycho Number %d has died.\n\e[0;m", address + 1);
	exit(1);
}

void	print_complete(t_args *args, int address)
{
	t_u64	stamp;

	stamp = get_time() - args->program->starttime;
	printf("\e[0;32mTIMESTAMP: %10lld - ", stamp);
	printf("\e[1;37mPsycho Number %d ", address + 1);
	printf("has completed the goal\n\e[0;m");
}

void	print_fork_picked_up(t_args *args, int address, int *fork)
{
	t_u64	stamp;

	stamp = get_time() - args->program->starttime;
	printf("\e[0;32mTIMESTAMP: %10lld - ", stamp);
	printf("\e[1;37mPsycho Number %d ", address + 1);
	printf("\e[1;35mhas picked up fork %d\n\e[0;m", *fork + 1);
}
