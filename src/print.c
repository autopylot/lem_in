/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:36:43 by wlin              #+#    #+#             */
/*   Updated: 2017/08/23 13:57:06 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void print_move(t_ant *ant)
{
	printf("%s-%s ", ant->name, ant->curr_rm->name);
}

void print_colony(t_ant *colony, int n_ants)
{
	int i;

	i = 0;
	printf("Ants in colony: ");
	while (i < n_ants)
	{
		printf("%s[%s] ", colony[i].name, colony[i].curr_rm->name);
		i++;
	}
	printf("\n");
}
void print_adj(t_link *adj_list)
{
	t_link *curr = adj_list;

	printf("Adjacent rooms: ");
	while (curr)
	{
		printf("[%s] ", curr->adj_rm->name);
		curr = curr->next;
	}
	printf("\n");
}

void print_room(t_room *head)
{
	t_room *curr = head;

	while (curr)
	{
		printf("Room: [%s]\n", curr->name);
		printf("Occupied: %d\n", curr->full);
		printf("Distance: %d\n", curr->dist);
		printf("Coordinates: %d %d\n", curr->cord[0], curr->cord[1]);
		print_adj(curr->adj_list);
		printf("~~~~~~~~~~~~~~~\n");
		curr = curr->next;
	}
}

void print_antfarm(t_antfarm *farm)
{
	printf("Ants: %d\n", farm->n_ants);
	printf("Rooms: %d\n", farm->n_rms);
	printf("Start room: %s\n", farm->start);
	printf("End room: %s\n", farm->end);
	printf("~~~~~~~~~~~~~~~~\n");
	print_room(farm->rms);
	print_colony(farm->colony, farm->n_ants);
}
