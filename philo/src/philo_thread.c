/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:08:33 by ltalia            #+#    #+#             */
/*   Updated: 2022/07/01 14:08:35 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_cycle_checker(void *arg)
{
	int			index;
	uint64_t	timestamp;
	t_env		*env;

	env = (t_env *)arg;
	index = 0;
	while (true)
	{
		if (env->count_done == env->n_philo)
			break ;
		if (index == env->n_philo)
			index = 0;
		usleep(1000);
		timestamp = get_time_ms();
		if (!env->philos[index].done
			&& (int)(timestamp - env->philos[index].last_eat) > env->tt_die)
		{
			print_state(&env->philos[index], DEAD, get_time_ms());
			env->is_running = false;
			break ;
		}
		index++;
	}
	return (NULL);
}

void	*life_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time_ms();
	if (philo->id % 2 == 0)
	{
		philo_think(philo);
		usleep(philo->env->tt_eat * 0.25 * 1000);
	}
	while (philo->env->is_running)
	{
		take_forks(philo, get_time_ms());
		philo_eat(philo, get_time_ms());
		leave_forks(philo);
		philo_think(philo);
		if (philo->eat_count == philo->env->must_eat)
		{
			philo->done = true;
			philo->env->count_done++;
			break ;
		}
		philo_sleep(philo);
	}
	return (NULL);
}
