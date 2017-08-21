/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:14:36 by wlin              #+#    #+#             */
/*   Updated: 2017/08/21 13:00:23 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void init_colony(t_antfarm *farm, int n_ants)
{
	farm->n_ants = n_ants;
	farm->colony = (t_ant*)malloc(sizeof(t_ant) * n_ants);
}

t_room  *init_room(char **room_def)
{
	t_room *new_rm;

	new_rm = (t_room*)malloc(sizeof(t_room));
	new_rm->name = ft_strdup(room_def[0]);
	new_rm->full = 0;
	new_rm->cord[0] = ft_atoi(room_def[1]);
	new_rm->cord[1] = ft_atoi(room_def[2]);
	new_rm->adj_list = NULL;
	new_rm->next = NULL;
	return (new_rm);
}

t_link *init_link(t_room *adj_rm)
{
	t_link *new_link;

	new_link = (t_link*)malloc(sizeof(t_link));
	new_link->adj_rm = adj_rm;
	new_link->next = NULL;
	return (new_link);
}

void init_farm(t_antfarm *farm)
{
	farm->n_rms = 0;
	farm->n_ants = 0;
	farm->start = NULL;
	farm->end = NULL;
	farm->colony = NULL;
	farm->rms = NULL;
}
