/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:10:06 by ltalia            #+#    #+#             */
/*   Updated: 2022/07/01 14:10:09 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->env->sem_forks);
	print_state(philo, TOOK_FORK, get_time_ms());
	sem_wait(philo->env->sem_forks);
	print_state(philo, TOOK_FORK, get_time_ms());
}

void	leave_fork(t_philo *philo)
{
	sem_post(philo->env->sem_forks);
	sem_post(philo->env->sem_forks);
}

void	philo_eat(t_philo *philo, uint64_t timestamp)
{
	print_state(philo, EATING, timestamp);
	philo->eat_count++;
	philo->last_eat = timestamp;
	usleep(philo->env->tt_eat * 1000);
}

void	philo_sleep(t_philo *philo)
{
	print_state(philo, SLEEPING, get_time_ms());
	usleep(philo->env->tt_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	print_state(philo, THINKING, get_time_ms());
}
