/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:06:21 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 16:19:51 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    print(t_args *args, int address, int type)
{
	u64 stamp;

	stamp = get_time() - args->program->starttime;
    if (pthread_mutex_lock(&args->program->print_mutex) == 0)
    {
        {
            if (EATING == type)
                    printf("%lld - %d is eating\n", stamp, address + 1);
            else if (SLEEPING == type)
                    printf("%lld - %d is sleeping\n", stamp, address + 1);
            else if (CODING == type)
                    printf("%lld - %d is coding\n", stamp, address + 1);
            else if (FORK_PICKED_UP == type)
                    printf("%lld - %d has picked up a fork\n", stamp, address + 1);
			else if (FORK_RETURNED == type)
					printf("%lld - %d has returned a fork\n", stamp, address + 1);
        }
    }
        pthread_mutex_unlock(&args->program->print_mutex);
}

