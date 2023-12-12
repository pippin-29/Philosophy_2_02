/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:02:14 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 14:16:40 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void sleepy(t_args *args, int address)
{
	printf("Philosopher %d is sleeping\n", address + 1);
	sleepbee(args->time_to_sleep);
	printf("Philosopher %d is coding\n", address + 1);
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

void	*supervisor_routine(void *arg)
{
	t_args *args;

	args = (t_args *)arg;
	while (1)
	{
		check_eat_goal(args);
	}
}

void	check_eat_goal(t_args *args)