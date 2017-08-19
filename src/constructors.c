/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:14:36 by wlin              #+#    #+#             */
/*   Updated: 2017/08/18 12:45:43 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void add_room(char **room_def, int mod, t_room **head)
{
	t_room *new_rm;
	static int roomID;

	roomID = 1;
	new_rm = init_room(room_def);
	if (mod == 1)
		new_rm->roomID == 0;
	else if (mod = -1)
		new_rm->roomID = -1;
	else
		new_rm->roomID = roomID++;
	if (*head)
	{
		new_rm->next = *head;
		*head = new_rm;
	}
}

t_room  *init_room(char **room_def)
{
	t_room *temp;

	temp = (t_room*)malloc(sizeof(t_room));
	temp->name = ft_strdup(room_def[0]);
	temp->full = 0;
	temp->cord[0] = ft_atoi(room_def[1]);
	temp->cord[1] = ft_atoi(room_def[2]);
	temp->adj_list = NULL;
	return (temp);
}
