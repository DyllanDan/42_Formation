/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:46:16 by dydaniel          #+#    #+#             */
/*   Updated: 2025/05/13 21:21:39 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_protagonists *philo, size_t time)
{
	size_t	start;

	start = get_time();
	ft_usleep(start - time, philo, "is spleeping");
	usleep(philo->to_sleep * 1000);
}

void	drop_forks(t_protagonists *philo, int i)
{
	if (i == 1)
		pthread_mutex_unlock(philo->l_fork);
	if (i == 2)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}

void	eat_action(t_protagonists *philo)
{
	usleep(philo->to_eat * 1000);
	pthread_mutex_lock(philo->p_meal_lock);
	philo->has_eated++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->p_meal_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_eat(t_protagonists *philo, size_t time)
{
	pthread_mutex_lock(philo->l_fork);
	if (is_alive(philo))
		ft_usleep(get_time() - time, philo, "has taken a fork");
	else
	{
		drop_forks(philo, 1);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	if (is_alive(philo))
	{
		ft_usleep(get_time() - time, philo, "has taken a fork");
		ft_usleep(get_time() - time, philo, "is eating");
	}
	else
	{
		drop_forks(philo, 2);
		return ;
	}
	eat_action(philo);
}
