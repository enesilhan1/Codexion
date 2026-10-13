/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enilhan <enilhan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:21:22 by enilhan           #+#    #+#             */
/*   Updated: 2026/10/13 11:21:22 by enilhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEX_H
# define CODEX_H

#include <stdio.h>
#include <string.h>


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


int str_to_int(char *str, int *out);
int	parser(char **av, t_params *params);

int	raise_error(char *s);


#endif