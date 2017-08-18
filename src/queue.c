/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 12:42:35 by wlin              #+#    #+#             */
/*   Updated: 2017/08/17 12:53:41 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void queue(t_path **start, t_path *path)
{
	t_path *curr;

	curr = *start;
	while (curr->next)
		curr = curr->next;
	curr->next = path;
}

t_path  *dequeue(t_path **start)
{
	t_path *temp;

	if (*start)
	{
		temp = *start;
		start = (*start)->next;
		return (temp);
	}
	return (NULL);
}
