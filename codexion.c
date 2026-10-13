/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enilhan <enilhan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:38:40 by enilhan           #+#    #+#             */
/*   Updated: 2026/10/13 15:38:40 by enilhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codex.h"

int main(int ac, char **av)
{
    t_params    params;

    if (ac != 9)
        return(raise_error("There is an error about the argument counts"));
    if (parser(av, &params) == 1)
        return (raise_error("There is an error about the arguments"));
    return (0);
}
