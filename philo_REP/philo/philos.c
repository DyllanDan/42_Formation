/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:53:28 by dydaniel          #+#    #+#             */
/*   Updated: 2025/05/17 13:56:25 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_alive(t_protagonists *philo)
{
	pthread_mutex_lock(philo->p_death_door);
	if (*philo->is_alive == 1)
	{
		pthread_mutex_unlock(philo->p_death_door);
		return (1);
	}
	pthread_mutex_unlock(philo->p_death_door);
	return (0);
}

int	eat_all(t_protagonists *philo)
{
	pthread_mutex_lock(philo->p_meal_lock);
	if (philo->must_eat == 0)
	{
		pthread_mutex_unlock(philo->p_meal_lock);
		return (1);
	}
	else if (philo->has_eated < philo->must_eat)
	{
		pthread_mutex_unlock(philo->p_meal_lock);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(philo->p_meal_lock);
		return (0);
	}
}

void	only_one(t_protagonists *philo, size_t time)
{
	if (is_alive(philo))
	{
		pthread_mutex_lock(philo->l_fork);
		ft_usleep(get_time() - time, philo, "takes its left fork");
		pthread_mutex_unlock(philo->l_fork);
	}
}

void	*activities(void *ptr)
{
	t_protagonists	*philo;
	size_t			start;

	start = get_time();
	philo = (t_protagonists *)ptr;
	if (philo->comrades == 1)
	{
		only_one(philo, start);
		return ((void *)0);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (is_alive(philo) && eat_all(philo) && philo->is_alive)
	{
		pthread_mutex_lock(philo->p_print_lock);
		printf("%lu Philo %d is thinking. \n", get_time() - start, philo->id);
		pthread_mutex_unlock(philo->p_print_lock);
		if (is_alive(philo))
			philo_eat(philo, start);
		if (is_alive(philo) && eat_all(philo))
			philo_sleep(philo, start);
	}
	return ((void *)0);
}
