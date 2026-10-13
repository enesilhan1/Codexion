/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enilhan <enilhan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:38:34 by enilhan           #+#    #+#             */
/*   Updated: 2026/10/13 14:42:34 by enilhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codex.h"
#include <limits.h>

int	str_to_int(char *str, int *out)
{
	int	res;
	int	i;

	if (!str || !out)
        return (1);
    i = 0;
    res = 0;
    if(str[i] == '-')
        return (1);
    if (str[i] == '+')
        i++;
    if (str[i] == '\0')
        return (1);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        if (res > (INT_MAX - (str[i] - '0')) / 10)
            return (1);
        res = res * 10 + (str[i] - '0');
        i++;
    }
    *out = res;
    return (0);
}

static int check_scheduler(char *str, t_params *params)
{
    if (strcmp(str, "fifo") == 0)
		params->scheduler = FIFO;
    else if (strcmp(str, "edf") == 0)
		params->scheduler = EDF;
	else
		return (1);

    return (0);
}

int	parser(char **av, t_params *params)
{
	int	*parameter[7];
	int	i;
    int checker;

	parameter[0] = &params->number_of_coders;
	parameter[1] = &params->time_to_burnout;
	parameter[2] = &params->time_to_compile;
	parameter[3] = &params->time_to_debug;
	parameter[4] = &params->time_to_refactor;
	parameter[5] = &params->number_of_compiles_required;
	parameter[6] = &params->dongle_cooldown;
	i = 1;
	while (i < 8)
	{
		if (str_to_int(av[i], parameter[i - 1]) == 1)
			return (1);
		i++;
	}
	checker = check_scheduler(av[8], params);
    if (checker)
        return(1);
	if (params->number_of_coders == 0)
		return (1);
	return (0);
}
