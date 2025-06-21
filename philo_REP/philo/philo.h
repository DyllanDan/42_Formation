/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:54:28 by dydaniel          #+#    #+#             */
/*   Updated: 2025/05/17 14:47:45 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILO 200 

typedef struct s_philo
{
	pthread_t		action;
	int				*is_alive;
	int				id;
	size_t			to_die;
	size_t			comrades;
	size_t			to_eat;
	size_t			to_sleep;
	size_t			has_eated;
	size_t			last_meal;
	size_t			must_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*p_meal_lock;
	pthread_mutex_t	*p_print_lock;
	pthread_mutex_t	*p_death_door;
}	t_protagonists;

typedef struct s_monitor
{
	int				alive;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_door;
	t_protagonists	*philo;
}	t_monitor;

typedef struct s_argv
{
	size_t	argv1;
	size_t	argv2;
	size_t	argv3;
	size_t	argv4;
	size_t	argv5;
}	t_argv;

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
long	ft_atoi_base(const char *nptr, int base);
int		check_argv(char **argv);
int		error(int i);
int		check_values(t_argv values);
int		ft_isdigit(int c);
void	ft_usleep(size_t time, t_protagonists *philo, char *str);
size_t	get_time(void);
void	*activities(void *ptr);
void	*vigilance(void *ptr);
void	philo_sleep(t_protagonists *philo, size_t time);
void	philo_eat(t_protagonists *philo, size_t time);
int		is_alive(t_protagonists *philo);
void	philo_times(t_argv values, t_protagonists *philo);
void	create_philos(t_argv values, t_protagonists *philo, \
		t_monitor *monitor, pthread_mutex_t *forks);
void	create_monitor(t_monitor *monitor, t_protagonists *protagonists);
void	create_forks(pthread_mutex_t *forks, int num_philo);
void	only_one(t_protagonists *philo, size_t time);

#endif
