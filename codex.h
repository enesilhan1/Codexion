/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enilhan <enilhan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:21:22 by enilhan           #+#    #+#             */
/*   Updated: 2026/10/13 21:05:56 by enilhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEX_H
# define CODEX_H

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>


typedef enum e_scheduler
{
	FIFO,
	EDF
}	t_scheduler;


typedef struct s_parameter
{
	int     number_of_coders;
	int     time_to_burnout;
	int     time_to_compile;
	int     time_to_debug;
	int     time_to_refactor;
	int     number_of_compiles_required;
	int     dongle_cooldown;
	t_scheduler	scheduler;
}   t_params;

typedef struct s_dongle	
{
	pthread_mutex_t		lock;
	int					is_busy;
	long				last_release;
}	t_dongle;

typedef struct s_coder
{
	int				id;
	long			last_compile_start;
	int				compile_count;
	t_dongle		*left;
	t_dongle		*right;
	pthread_t		thread;
	pthread_mutex_t	lock;
	struct s_sim	*sim;
}	t_coder;

typedef struct s_sim
{
	t_params		params;
	long			start_time;
	t_coder			*coders;
	t_dongle		*dongles;
	pthread_mutex_t	log_lock;
	int				stopped;
	pthread_mutex_t	stop_lock;
	pthread_t		monitor;
}	t_sim;


int str_to_int(char *str, int *out);
int	parser(char **av, t_params *params);

int	raise_error(char *s);


#endif