/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:06:21 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/13 09:11:01 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print(t_args *args, int address, int type)
{
	t_u64	stamp;

	stamp = get_time() - args->program->starttime;
	if (EATING == type)
		printf("%lld - %d is eating\e[0m\n", stamp, address + 1);
	else if (SLEEPING == type)
		printf("%lld - %d is sleeping\e[0m\n", stamp, address + 1);
	else if (CODING == type)
		printf("%lld - %d is coding\e[0m\n", stamp, address + 1);
	else if (FORK_PICKED_UP == type)
		printf("%lld - %d has picked up a fork\e[0m\n", stamp, address + 1);
	else if (FORK_RETURNED == type)
		printf("%lld - %d has returned a fork\e[0m\n", stamp, address + 1);
}
