/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:40:30 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/13 09:11:22 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (argc == 5 || argc == 6)
	{
		init(args, argv);
		start(args);
	}
	else
		return (error_message());
}
