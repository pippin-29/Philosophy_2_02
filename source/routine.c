/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:38:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/13 09:16:46 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_args		*args;
	pthread_t	current_thread;
	int			id_please;

	current_thread = pthread_self();
	args = (t_args *)arg;
	id_please = id_check(args->philo, current_thread);
	if (id_please == -1)
		exit(-1);
	while (1)
	{
		if (id_please % 2)
			sleepbee(10);
		share(args, id_please);
	}
}

void	share(t_args *args, int address)
{
	eat(args, address);
	sleepy(args, address);
}

void	check_pulse(t_args *args, int address)
{
	if (args->philo_num == 1)
	{
		sleepbee(args->time_to_die);
		printf("Philosopher %d can no longer eat...\n", address + 1);
		exit(0);
	}
	if (args->philo[address]->eat_stamp != 0)
	{
		if (get_time() - args->philo[address]->eat_stamp > args->time_to_die)
		{
			printf("Philosopher %d can no longer eat...\n", address + 1);
			exit(0);
		}
	}
	else
	{
		if (get_time() - args->program->starttime > args->time_to_die)
		{
			printf("Philosopher %d can no longer eat...\n", address + 1);
			exit(0);
		}
	}
}

int	eat(t_args *args, int address)
{
	check_pulse(args, address);
	if (forks_acquired(args, address))
	{
		print(args, address, EATING);
		sleepbee(args->time_to_eat);
		args->philo[address]->eat_count++;
		args->philo[address]->eat_stamp = get_time();
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
	int	left;
	int	right;

	left = args->philo[address]->left;
	right = args->philo[address]->right;
	if (pthread_mutex_unlock(&args->philo[left]->fork) == 0)
		print(args, address, FORK_RETURNED);
	if (pthread_mutex_unlock(&args->philo[right]->fork) == 0)
		print(args, address, FORK_RETURNED);
}
