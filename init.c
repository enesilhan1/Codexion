/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enilhan <enilhan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:03:02 by enilhan           #+#    #+#             */
/*   Updated: 2026/10/13 21:57:39 by enilhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codex.h"

void	destroy_dongles(t_sim *sim, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		pthread_mutex_destroy(&sim->dongles[i].lock);
		i++;
	}
}

static int	init_dongles(t_sim *sim, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		sim->dongles[i].is_busy = 0;
		sim->dongles[i].last_release = 0;
		if (pthread_mutex_init(&sim->dongles[i].lock, NULL) != 0)
		{
			destroy_dongles(sim, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_sim(t_sim *sim)
{
	int	n;

	n = sim->params.number_of_coders;
	sim->coders = malloc(sizeof(t_coder) * n);
	if (!sim->coders)
		return (1);
	sim->dongles = malloc(sizeof(t_dongle) * n);
	if (!sim->dongles)
	{
		free(sim->coders);
		sim->coders = NULL;
		return (1);
	}
	if (init_dongles(sim, n) != 0)
	{
		free(sim->coders);
		free(sim->dongles);
		sim->coders = NULL;
		sim->dongles = NULL;
		return (1);
	}
	return (0);
}
