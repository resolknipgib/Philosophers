/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:11:17 by ltalia            #+#    #+#             */
/*   Updated: 2022/07/01 14:11:20 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	print_state(t_philo *philo, t_state state, uint64_t timestamp)
{
	const char	*states[6] = {STR_THINKING, STR_EATING, STR_SLEEPING,
		STR_TOOK_FORK, STR_DEAD, NULL};

	sem_wait(philo->env->sem_write);
	printf("%llu %d %s\n", timestamp, philo->id, states[state]);
	sem_post(philo->env->sem_write);
}
