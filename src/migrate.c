/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   migrate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:44:22 by wlin              #+#    #+#             */
/*   Updated: 2017/08/22 14:34:31 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//set end as 0 always and start as 1
int move_ant(t_ant *ant)
{

	t_link *adj_list;
	t_room *curr;

	curr = ant->curr_rm;
	adj_list = curr->adj_list;
	// see if shortest route is open
	while (adj_list)
	{
		if (adj_list->adj_rm->dist < curr->dist && adj_list->adj_rm->full == 0)
		{
			ant->curr_rm->full = 0;
			ant->curr_rm = adj_list->adj_rm;
			ant->curr_rm->full = 1;
		}
		adj_list = adj_list->next;
	}
	adj_list = curr->adj_list;
	while (adj_list)
	{
		if (adj_list->adj_rm->dist = curr->dist && adj_list->adj_rm->full == 0)
		{
			ant->curr_rm->full = 0;
			ant->curr_rm = adj_list->adj_rm;
			ant->curr_rm->full = 1;
		}
		adj_list = adj_list->next;
	}
	//otherwise move another equal route if possible
	//return 1 if ant moved else 0
}




void migrate(t_antfarm *farm)
{


	while ()// while all ants arent at the end
			// try and move ant towards the end


	//print ants pos at end of turn

}
