/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:13:46 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/12 15:17:58 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

typedef unsigned long long  u64;

u64	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * (u64)1000) + (time.tv_usec / 1000));
}

int main(void)
{
	u64 start = get_time();

	while (1)
		printf("%lld\n", get_time() - start);
}