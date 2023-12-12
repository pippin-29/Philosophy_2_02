/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:38:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 15:04:40 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void *arg)
{
	t_args *args;
	pthread_t current_thread;
	int	id_please;

	current_thread = pthread_self();
	args = (t_args *)arg;
	id_please = id_check(args->philo, current_thread);
	if (id_please == -1)
		exit(-1);
	while (1)
	{
		share(args, id_please);
	}
}

void share(t_args *args, int address)
{
	eat(args, address);
	sleepy(args, address);
}

int	eat(t_args *args, int address)
{
	if (forks_acquired(args, address))
	{
		printf("Philosopher %d is eating\n", address + 1);
		sleepbee(args->time_to_eat);
		args->philo[address]->eat_count++;
		return_forks(args, address);
		if (args->philo[address]->eat_count == args->eat_goal)
		{
			printf("Philosopher %d has completed the goal\n", address + 1);
			args->philo[address]->state = COMPLETE;
			pthread_exit(args->philo[address]->tid);
		}
		return (1);
	}	
	else
		return (0);

}

void	return_forks(t_args *args, int address)
{
	int left;
	int right;

	left = args->philo[address]->left;
	right = args->philo[address]->right;
	pthread_mutex_unlock(&args->philo[left]->fork);
	pthread_mutex_unlock(&args->philo[right]->fork);

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
		if (pthread_mutex_trylock(&args->philo[i]->fork))
		{
			fork_count++;
			printf("Philosopher %d has taken fork %d\n", address + 1, fork_count);
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

