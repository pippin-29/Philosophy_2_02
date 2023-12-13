/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:02:14 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/14 07:27:51 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sleepy(t_args *args, int address)
{
	print(args, address, SLEEPING, NULL);
	sleepbee(args->time_to_sleep);
	print(args, address, CODING, NULL);
}

int	id_check(t_philo **philo, pthread_t thread_id)
{
	int	i;

	i = 0;
	while (philo[i])
	{
		if (pthread_equal(thread_id, philo[i]->tid))
			return (philo[i]->iid);
		i++;
	}
	printf("Thread_IDs not present.\n");
	return (-1);
}

int	forks_acquired(t_args *args, int address)
{
	int	i;
	int	fork_count;

	i = 0;
	fork_count = 0;
	while (1)
	{
		if (fork_count == 2)
			return (1);
		if (pthread_mutex_trylock(&args->philo[i]->fork) == 0)
		{
			fork_count++;
			print(args, address, FORK_PICKED_UP, &i);
			if (fork_count == 1)
				args->philo[address]->left = i;
			else if (fork_count == 2)
				args->philo[address]->right = i;
		}
		i++;
		if (i == args->philo_num)
			i = 0;
	}
	return (0);
}
