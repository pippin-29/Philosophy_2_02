/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:07:20 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/05 14:50:13 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_message(void)
{
	printf("Provide programs arguments in this format...\n");
	printf("	- `./philo 1 800 200 200` or `./philo 1 800 200 200 7`\n");
	printf("	- numbers are in milliseconds and represent\n");
	printf("	- number_of_philosophers time_to_die time_to_eat \n");
	printf("	  time_to_sleep [number_of_times_each_philosopher_must_eat]");
	return (1);
}