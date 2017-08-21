/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:54:29 by wlin              #+#    #+#             */
/*   Updated: 2017/08/21 14:17:14 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


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
		printf("Room is full: %d\n", curr->full);
		printf("Room cords: %d %d\n", curr->cord[0], curr->cord[1]);
		print_adj(curr->adj_list);
		printf("~~~~~~~~~~~~\n");
		curr = curr->next;
	}
}

void print_antfarm(t_antfarm *farm)
{
	printf("Farm has: %d ants\n", farm->n_ants);
	printf("Farm has: %d rooms\n", farm->n_rms);
	printf("Start room: %s\n", farm->start);
	printf("End room: %s\n", farm->end);
	printf("~~~~~~~~~~~~\n");
	//print position of ants
	print_room(farm->rms);
}

int main(int argc, char **argv)
{
	int fd;
	t_antfarm antFarm;

	if (argc != 2)
	{
		puts("Error");
		// return (1);
	}
	init_farm(&antFarm);
	fd = open(argv[1], O_RDONLY);
	parse_map(fd, &antFarm);
	return (0);
}
