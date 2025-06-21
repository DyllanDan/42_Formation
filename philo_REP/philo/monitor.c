/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:50:12 by dydaniel          #+#    #+#             */
/*   Updated: 2025/05/13 21:11:28 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	eat_control(t_protagonists *philos)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < philos[0].comrades)
	{
		pthread_mutex_lock(philos[i].p_meal_lock);
		if (philos[i].must_eat == 0)
		{
			pthread_mutex_unlock(philos[i].p_meal_lock);
			return (0);
		}
		else if (philos[i].has_eated == philos[i].must_eat)
			j++;
		pthread_mutex_unlock(philos[i].p_meal_lock);
		i++;
	}
	if (j == philos[0].comrades)
		return (1);
	else
		return (0);
}

size_t	a_death(t_protagonists *philos, size_t time)
{
	size_t	i;

	i = 0;
	while (i < philos[0].comrades)
	{
		pthread_mutex_lock(philos->p_meal_lock);
		if (get_time() - philos[i].last_meal >= philos[i].to_die)
		{
			pthread_mutex_lock(philos[i].p_death_door);
			*philos->is_alive = 0;
			usleep(((philos[i].to_die - \
				(get_time() - philos[i].last_meal)) * 1000));
			pthread_mutex_lock(philos[i].p_print_lock);
			printf("%lu Philo %d died\n", \
					get_time() - time, philos[i].id);
			pthread_mutex_unlock(philos[i].p_print_lock);
			pthread_mutex_unlock(philos[i].p_death_door);
			pthread_mutex_unlock(philos->p_meal_lock);
			return (1);
		}
		pthread_mutex_unlock(philos[i].p_meal_lock);
		i++;
	}
	return (0);
}

void	*vigilance(void *ptr)
{
	t_protagonists	*philos;
	size_t			time;

	philos = (t_protagonists *)ptr;
	time = get_time();
	while (1)
	{
		if (eat_control(philos))
			break ;
		if (a_death(philos, time))
			break ;
	}
	return ((void *)0);
}
