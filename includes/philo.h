/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:41:12 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 12:28:22 by dhadding         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		tid;
	int				iid;
	int				eat_count;
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

/// START_C ///

/// TIME_C ///
u64	get_time(void);


#endif