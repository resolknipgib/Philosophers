/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:07:28 by ltalia            #+#    #+#             */
/*   Updated: 2022/07/01 14:07:31 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <inttypes.h>
# include <sys/time.h>

# define FAILURE -1

# define STR_THINKING	"is thinking"
# define STR_EATING		"is eating"
# define STR_SLEEPING	"is sleeping"
# define STR_TOOK_FORK	"has taken a fork"
# define STR_DEAD		"died"

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	TOOK_FORK,
	DEAD
}	t_state;

typedef struct s_env	t_env;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				eat_count;
	bool			done;
	uint64_t		last_eat;
	pthread_t		thread_id;
	t_env			*env;
}	t_philo;

typedef struct s_env
{
	int				n_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				must_eat;
	int				count_done;
	bool			is_running;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}	t_env;

void		init_arguments(int argc, char **argv, t_env *env);
void		init_mutexes(t_env *env);
void		init_philos(t_env *env);
void		init_threads(t_env *env);
void		destroy(t_env *env);
void		*life_cycle(void *arg);
void		*life_cycle_checker(void *arg);
void		print_state(t_philo *philo, t_state state, uint64_t timestamp);
uint64_t	get_time_ms(void);
void		take_forks(t_philo *philo, uint64_t timestamp);
void		leave_forks(t_philo *philo);
void		philo_eat(t_philo *philo, uint64_t timestamp);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

#endif
