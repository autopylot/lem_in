/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:14:36 by wlin              #+#    #+#             */
/*   Updated: 2017/08/22 14:08:55 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void init_start(t_antfarm *farm)
{
	int i;
	t_room *start;

	i = 0;
	start = get_room(farm->start, farm->rms);
	while (i < farm->n_ants)
	{
		farm->colony[i].curr_rm = start;
		++i;
	}
}

void init_colony(t_antfarm *farm, int n_ants)
{
	int i;

	i = 0;
	farm->n_ants = n_ants;
	farm->colony = (t_ant*)malloc(sizeof(t_ant) * n_ants);
	while (i < n_ants)
	{
		farm->colony[i].name = ft_strjoin("L", ft_itoa(i + 1));
		farm->colony[i].curr_rm = NULL;
		++i;
	}
}

t_room  *init_room(char **room_def)
{
	t_room *new_rm;

	new_rm = (t_room*)malloc(sizeof(t_room));
	new_rm->name = ft_strdup(room_def[0]);
	new_rm->full = 0;
	new_rm->dist = -1;
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
