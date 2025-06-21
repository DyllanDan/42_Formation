/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:52:56 by dydaniel          #+#    #+#             */
/*   Updated: 2025/05/17 13:57:01 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_threads(t_monitor *monitor, t_argv values)
{
	pthread_t	vigil;
	size_t		i;

	i = 0;
	pthread_create(&vigil, NULL, &vigilance, monitor->philo);
	while (i < values.argv1)
	{
		pthread_create(&monitor->philo[i].action, NULL, \
			&activities, &monitor->philo[i]);
		i++;
	}
	i = 0;
	while (i < values.argv1)
	{
		pthread_join(monitor->philo[i].action, NULL);
		i++;
	}
	pthread_join(vigil, NULL);
	pthread_mutex_destroy(&monitor->print_lock);
	pthread_mutex_destroy(&monitor->death_door);
	pthread_mutex_destroy(&monitor->meal_lock);
}

void	argv_values(char **argv, t_argv *values)
{
	values->argv1 = ft_atoi_base(argv[1], 10);
	values->argv2 = ft_atoi_base(argv[2], 10);
	values->argv3 = ft_atoi_base(argv[3], 10);
	values->argv4 = ft_atoi_base(argv[4], 10);
	if (argv[5])
		values->argv5 = ft_atoi_base(argv[5], 10);
	else
		values->argv5 = 0;
}

int	main(int argc, char **argv)
{
	t_protagonists	protagonists[MAX_PHILO];
	t_monitor		monitor;
	pthread_mutex_t	forks[MAX_PHILO];
	t_argv			values;
	size_t			i;

	if (argc < 5 || argc > 6)
		return (error(1));
	if (check_argv(argv))
		return (error(5));
	argv_values(argv, &values);
	if (!check_values(values))
		return (0);
	create_forks(forks, values.argv1);
	create_monitor(&monitor, protagonists);
	create_philos(values, protagonists, &monitor, forks);
	philos_threads(&monitor, values);
	i = 0;
	while (i < values.argv1)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	return (0);
}
