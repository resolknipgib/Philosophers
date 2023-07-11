/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:07:59 by ltalia            #+#    #+#             */
/*   Updated: 2022/07/01 14:08:02 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_threads(t_env *env)
{
	int	index;

	index = -1;
	while (++index < env->n_philo)
		pthread_detach(env->philos[index].thread_id);
}

void	destroy(t_env *env)
{
	int	index;

	destroy_threads(env);
	index = -1;
	while (++index < env->n_philo)
		pthread_mutex_destroy(&env->forks[index]);
	pthread_mutex_destroy(&env->write);
	free(env->philos);
	free(env->forks);
}
