/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:54:29 by wlin              #+#    #+#             */
/*   Updated: 2017/08/19 14:33:28 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void print_adj(t_room *head)
{
	t_link *curr = head->adj_list;

	printf("%s is adjacent to: ", head->name);
	while (curr)
	{
		printf("[%s] ", curr->adj_rm->name);
		curr = curr->next;
	}
	printf("\n");
}

void print_rooms(t_room *head)
{
	t_room *curr = head;

	printf("Room: ");
	while (curr)
	{
		printf("%s ", curr->name);
		curr = curr->next;
	}
	printf("\n");
	//print_adj(head);
}

void print_antfarm(t_antfarm *farm)
{
	printf("Farm has: %d ants.\n", farm->n_ants);
	printf("Farm has: %d rooms.\n", farm->n_rms);
	printf("Start room: %s.\n", farm->start);
	printf("End room: %s.\n", farm->end);
	print_rooms(farm->rms);
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
