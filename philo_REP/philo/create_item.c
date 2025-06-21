/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:40:30 by dydaniel          #+#    #+#             */
/*   Updated: 2025/05/17 13:52:56 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_times(t_argv values, t_protagonists *philo)
{
	philo->comrades = values.argv1;
	philo->to_die = values.argv2;
	philo->to_eat = values.argv3;
	philo->to_sleep = values.argv4;
	philo->must_eat = values.argv5;
	philo->last_meal = get_time();
}

void	create_philos(t_argv values, t_protagonists *philo, \
		t_monitor *monitor, pthread_mutex_t *forks)
{
	size_t	i;

	i = 0;
	while (i < values.argv1)
	{
		philo[i].id = i + 1;
		philo[i].is_alive = &monitor->alive;
		philo_times(values, &philo[i]);
		philo[i].has_eated = 0;
		philo[i].l_fork = &forks[i];
		if (i + 1 >= values.argv1)
			philo[i].r_fork = &forks[0];
		else
			philo[i].r_fork = &forks[i + 1];
		philo[i].p_death_door = &monitor->death_door;
		philo[i].p_meal_lock = &monitor->meal_lock;
		philo[i].p_print_lock = &monitor->print_lock;
		i++;
	}
}

void	create_forks(pthread_mutex_t *forks, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	create_monitor(t_monitor *monitor, t_protagonists *protagonists)
{
	monitor->alive = 1;
	pthread_mutex_init(&monitor->print_lock, NULL);
	pthread_mutex_init(&monitor->meal_lock, NULL);
	pthread_mutex_init(&monitor->death_door, NULL);
	monitor->philo = protagonists;
}
