/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:36:13 by dydaniel          #+#    #+#             */
/*   Updated: 2025/05/13 21:25:16 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (error(3), -1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	interval(size_t ms)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(1000);
}

void	ft_usleep(size_t time, t_protagonists *philo, char *str)
{
	pthread_mutex_lock(philo->p_print_lock);
	printf("%zu Philo %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->p_print_lock);
}
