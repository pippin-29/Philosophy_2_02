/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:09:59 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 15:10:56 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void start(t_args *args)
{
	create_threads(args);
	wait_for_exit(args);
	pause();
}

void	create_threads(t_args *args)
{
	int	i;

	i = 0;
	while (args->philo[i])
	{
		if (pthread_create(&args->philo[i]->tid, NULL, routine, args) != 0)
			printf("Failed To Create Thread For Philosopher %d\n", args->philo[i]->iid + 1);
		i++;
	}
}

void	wait_for_exit(t_args *args)
{
	int i;

	i = 0;
	while (1)
	{
		while (args->philo[i])
		{
			if (args->philo[i]->state != COMPLETE)
				break;
			if (i == args->philo_num - 1)
				exit(0);
			i++;
		}
		
	}
}


// void	supervisor_thread(t_args *args)
// {	
// 	if (pthread_create(&args->program->sup_id, NULL, supervisor_routine, args) != 0)
// 		printf("Failed To Create Thread For Supervisor\n");
// }
