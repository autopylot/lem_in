/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:18:32 by wlin              #+#    #+#             */
/*   Updated: 2017/08/23 12:29:52 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void init_queue(t_room **queue, int n_rms)
{
	int i;

	i = -1;
	while (++i < n_rms)
		queue[i] = NULL;
}


void adj_queue(t_room **queue, t_link *adj_list)
{
	int i;

	i = 0;
	while ((queue)[i])
		++i;
	while (adj_list)
	{
		if (adj_list->adj_rm->dist == -1)
		{
			(queue)[i] = adj_list->adj_rm;
			++i;
		}
		adj_list = adj_list->next;
	}
}

void adj_dist(t_link *adj_list, int dist)
{
	while (adj_list)
	{
		if (adj_list->adj_rm->dist == -1)
			adj_list->adj_rm->dist = dist + 1;
		adj_list = adj_list->next;
	}
}


void set_dist(t_antfarm *farm)
{
	int i;
	t_room **rm_queue;

	i = 0;
	rm_queue = (t_room**)malloc(sizeof(t_room*) * farm->n_ants);
	init_queue(rm_queue, farm->n_rms);
	while (i < farm->n_rms)
	{
		if (i == 0)
		{
			 rm_queue[i] = get_room(farm->end, farm->rms);
			 rm_queue[i]->dist = 0;
		}
		adj_queue(rm_queue, rm_queue[i]->adj_list);
		adj_dist(rm_queue[i]->adj_list, rm_queue[i]->dist);
		++i;
	}
}
