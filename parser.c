/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enilhan <enilhan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:38:34 by enilhan           #+#    #+#             */
/*   Updated: 2026/10/13 13:39:27 by enilhan          ###   ########.fr       */
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
