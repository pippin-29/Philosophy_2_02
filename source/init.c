/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:55:10 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 16:20:04 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_input(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!digit(argv[i][j]))
			{
				error_message();
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	init(t_args *args, char **argv)
{
	check_input(&argv[1]);
	args->philo_num = ascii_2_int(argv[1]);
	args->time_to_die = ascii_2_int(argv[2]);
	args->time_to_eat = ascii_2_int(argv[3]);
	args->time_to_sleep = ascii_2_int(argv[4]);
	if (argv[5])
		args->eat_goal = ascii_2_int(argv[5]);
	init_program(args);
	init_philos(args);
	start(args);
}

void	init_program(t_args *args)
{
	args->program = malloc(sizeof(t_program));
	args->program->starttime = get_time();
}

void	init_philos(t_args *args)
{
	int i;

	i = 0;
	args->philo = malloc(sizeof(t_philo *) * (args->philo_num + 1));
	while (i < args->philo_num)
	{
		args->philo[i] = malloc(sizeof(t_philo));
		args->philo[i]->iid = i;
		args->philo[i]->tid = NULL;
		args->philo[i]->left = -1;
		args->philo[i]->right = -1;
		args->philo[i]->eat_count = 0;
		args->philo[i]->eat_stamp = 0;
		pthread_mutex_init(&args->philo[i]->fork, NULL);
		i++;
	}
	args->philo[i] = NULL;
}