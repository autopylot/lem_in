/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:58:17 by wlin              #+#    #+#             */
/*   Updated: 2017/08/24 15:06:51 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


def DFS(graph, start, end, path, shortest):
	"""Assumes graph is Digraph; start and end are nodes; path and shortest are lists of nodes"""
	path = path + [start]
	if start == end:
		return path
	for node in graph.childrenOf(start):
		if node in not path: # avoid cycles
			if shortest == None or len(path) < len(shortest):
				newPath = DFS(graph, node, end, path, shortest)
				if newPath != None:
					shortest = newPath
	return shortest

def search(graph, start, end):
	return DFS(graph, start, end, [], None) # call DFS with path == [], shortest == None and root node as start"


int dfs_check(t_room *start, char *end)
{


	if (!ft_strcmp(start->name, end))
		return (1);
	while (start->adj_list)
}
