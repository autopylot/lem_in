/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   migrate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:44:22 by wlin              #+#    #+#             */
/*   Updated: 2017/08/23 14:03:53 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//finds smaller dist adj rm open  to move, if no smaller returns open euqal otherwise return null
t_room *best_adj(t_link *adj_list, int dist)
{
	t_room *equal_rm;

	equal_rm = NULL;
	while (adj_list)
	{
		if (adj_list->adj_rm->dist < dist && adj_list->adj_rm->full == 0)
			return (adj_list->adj_rm);
		else if (adj_list->adj_rm->dist == dist && adj_list->adj_rm->full == 0)
			equal_rm = adj_list->adj_rm;
		adj_list = adj_list->next;
	}
	return (equal_rm);
}

void move_ant(t_ant *ant, char *end)
{
	t_room *next_rm;


	if ((next_rm = best_adj(ant->curr_rm->adj_list, ant->curr_rm->dist)))
	{
		ant->curr_rm->full = 0;
		ant->curr_rm = next_rm;
		if (ft_strcmp(ant->curr_rm->name, end))
			ant->curr_rm->full = 1;
		print_move(ant);
	}
}


void migrate_colony(t_antfarm *farm)
{
	// while all ants arent at the end
	// try and move ant towards the end
	int i;

	while (ft_strcmp(farm->colony[farm->n_ants - 1].curr_rm->name, farm->end))
	{
		i = 0;
		while (i < farm->n_ants)
		{
			move_ant(&(farm->colony[i]), farm->end);
			++i;
		}
		printf("\n");
	}
	//print ants pos at end of turn
}
