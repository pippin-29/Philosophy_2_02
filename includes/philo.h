/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:41:12 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 15:11:11 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include "../source/source_util/source_util.h"

#define COMPLETE 1

typedef struct s_philo
{
	pthread_t		tid;
	int				iid;
	int				eat_count;
	int				state;
	int				left;
	int				right;
	pthread_mutex_t	fork;
} t_philo;

typedef struct s_program
{
	u64			starttime;
	u64			timestamp;
	pthread_t	sup_id;
} t_program;

typedef struct s_args
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eat_goal;
	t_philo		**philo;
	t_program	*program;
} t_args;

/// ERROR_C ///
int	error_message(void);

/// INIT_C ///
int		digit(char c);
int		check_input(char **argv);
void	init(t_args *args, char **argv);
void	init_program(t_args *args);
void	init_philos(t_args *args);

/// ROUTINE_C ///
void	*routine(void *arg);
void	share(t_args *args, int address);
int		eat(t_args *args, int address);
void	return_forks(t_args *args, int address);
int		forks_acquired(t_args *args, int address);

/// ROUTINE2_C ///
void	sleepy(t_args *args, int address);
int		id_check(t_philo **philo, pthread_t thread_id);
// void	*supervisor_routine(void *arg);
// void	check_eat_goal(t_args *args);

/// START_C ///
void	start(t_args *args);
void	create_threads(t_args *args);
void	wait_for_exit(t_args *args);
// void	supervisor_thread(t_args *args);


/// TIME_C ///
u64		get_time(void);
void	sleepbee(int milliseconds);





#endif