/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:02:14 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 16:18:09 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void sleepy(t_args *args, int address)
{
	return_forks(args, address);
	print(args, address, SLEEPING);
	sleepbee(args->time_to_sleep);
	print(args, address, CODING);
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

// void	*supervisor_routine(void *arg)
// {
// 	t_args *args;

// 	args = (t_args *)arg;
// 	while (1)
// 	{
// 		check_eat_goal(args);
// 	}
// }

// void	check_eat_goal(t_args *args)
// {
// 	int	i;
// 	int personal_goal_count;

// 	i = 0;
// 	personal_goal_count = 0;
// 	while (personal_goal_count != args->eat_goal)
// 	{
// 		if (args->philo[i]->eat_count == args->eat_goal)
// 		{
// 			pthread_exit(args->philo[i]->tid);
// 			args->philo[i]->eat_count = -1;
// 			printf("Philosopher %d Meal Goal Reached\n", i + 1);
// 			personal_goal_count++;
// 		}
// 		i++;
// 	}
// 	printf("All philosophers Ate %d times!\n", personal_goal_count);

// }