/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:10:41 by ltalia            #+#    #+#             */
/*   Updated: 2022/07/01 14:10:45 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_semaphores(void)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_DIED);
}

static void	destroy_zombies(t_env *env)
{
	int	index;

	index = -1;
	while (++index < env->n_philo)
		kill(env->pids[index], SIGKILL);
}

void	destroy(t_env *env)
{
	destroy_zombies(env);
	destroy_semaphores();
	free(env->pids);
	free(env->philos);
}
