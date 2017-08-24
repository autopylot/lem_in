// #include <stdio.h>
// #include <stdlib.h>
//
// typedef struct s_room
// {
//   int id;
//   struct s_room *next;
//   struct s_link *adjlist;
// } t_room;
//
// typedef struct s_link
// {
//   t_room *adjrm;
//   struct s_link *next;
// } t_link;
//
// t_room *init_rm(int id)
// {
//   t_room *tmp = malloc(sizeof(t_room));
//   tmp->id = id;
//   tmp->next = NULL;
//   tmp->adjlist = NULL;
//   return (tmp);
// }
//
// t_link *init_link(t_room *adjrm)
// {
//   t_link *tmp = malloc(sizeof(t_link));
//   tmp->adjrm = adjrm;
//   tmp->next = NULL;
//   return (tmp);
// }
//
// void addrm(t_room *newrm, t_room **head)
// {
//   newrm->next = *head;
//   *head = newrm;
// }
//
// t_room *find_rm(int id, t_room *head)
// {
//   while (head)
//   {
//     if (id == head->id)
//       return (head);
//     else
//       head = head->next;
//   }
//   return (NULL);
// }
//
//
// void setup_link(int *arr, t_room *head)
// {
//   t_room *curr = head;
//   while (curr)
//   {
//     if (curr->id == arr[0])
//     {
//       t_room *tmp = find_rm(arr[1], head);
//       curr->adjlist = init_link(tmp);
//       return ;
//     }
//     else
//       curr = curr->next;
//   }
// }
//
// int main()
// {
//   t_room *head;
//
//   head = init_rm(1);
//   head->next = init_rm(2);
//   head->next->next = init_rm(3);
//   printf("First: %d, Second: %d, Third: %d\n", head->id, head->next->id, head->next->next->id);
//   int arr[2] = {1, 3};
//   setup_link(arr, head);
//   printf("Room ID: %d, AdjRms: %d\n", head->id, head->adjlist->adjrm->id);
// }
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// int main()
// {
// 	printf("processing... |");
// 	fflush(stdout);
// 	sleep(1);
// 	printf("\b/");
// 	fflush(stdout);
// 	sleep(1);
// 	printf("\b-");
// 	fflush(stdout);
// 	if (1 - 4)
// 		printf("negative");
// 	printf("%d\n", atoi("sd8989"));
// 	printf("%d\n", atoi("8989"));
// }

// typedef struct s_room
// {
// 	int id;
// 	struct s_room *next;
// }	t_room;
//
// typedef struct s_farm
// {
// 	t_room *rms;
// } t_farm;
//
//
// t_room *init(int i)
// {
// 	t_room *new;
//
// 	new = (t_room*)malloc(sizeof(t_room));
// 	new->id = i;
// 	new->next = NULL;
// 	return (new);
// }
//
// void print(t_room *rm)
// {
// 	while (rm)
// 	{
// 		printf("%d ->", rm->id);
// 		rm = rm->next;
// 	}
// 	printf("\n");
// }
//
// void add(t_farm farm, t_room *new)
// {
// 	if (farm.rms)
// 	{
// 		new->next = farm.rms;
// 		farm.rms = new;
// 	}
// 	else
// 		farm.rms = new;
// 	print(farm.rms);
// }
//
//
//
//
// int main()
// {
// 	t_farm farm;
//
// 	farm.rms = NULL;
// 	t_room *rm1 = init(1);
// 	t_room *rm2 = init(2);
// 	t_room *rm3 = init(3);
// 	add(farm, rm1);
// 	add(farm, rm2);
// 	add(farm, rm3);
// 	print(farm.rms);
//
//
//
// }
#include <string.h>

int main()
{
	char *str;

	str = (char*)malloc(sizeof(char) * 6);
	strcpy(str,"happy");
	printf("%s\n", str);
	int i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
		{
			free(str);
			str = NULL;
		}
		++i;
	}
	if (i == 5)
		printf("ended normals");
}
