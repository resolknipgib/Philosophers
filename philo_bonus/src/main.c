/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:10:55 by ltalia            #+#    #+#             */
/*   Updated: 2022/07/01 14:10:57 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	env;

	init_arguments(argc, argv, &env);
	init_semaphore(&env);
	init_philos(&env);
	init_philo_process(&env);
	pthread_create(&env.checker, NULL, checker_function, &env);
	pthread_detach(env.checker);
	sem_wait(env.sem_done);
	destroy(&env);
}
