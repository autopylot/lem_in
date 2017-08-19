#include <stdio.h>
#include <stdlib.h>

typedef struct s_room
{
  int id;
  struct s_room *next;
  struct s_link *adjlist;
} t_room;

typedef struct s_link
{
  t_room *adjrm;
  struct s_link *next;
} t_link;

t_room *init_rm(int id)
{
  t_room *tmp = malloc(sizeof(t_room));
  tmp->id = id;
  tmp->next = NULL;
  tmp->adjlist = NULL;
  return (tmp);
}

t_link *init_link(t_room *adjrm)
{
  t_link *tmp = malloc(sizeof(t_link));
  tmp->adjrm = adjrm;
  tmp->next = NULL;
  return (tmp);
}

void addrm(t_room *newrm, t_room **head)
{
  newrm->next = *head;
  *head = newrm;
}

t_room *find_rm(int id, t_room *head)
{
  while (head)
  {
    if (id == head->id)
      return (head);
    else
      head = head->next;
  }
  return (NULL);
}


void setup_link(int *arr, t_room *head)
{
  t_room *curr = head;
  while (curr)
  {
    if (curr->id == arr[0])
    {
      t_room *tmp = find_rm(arr[1], head);
      curr->adjlist = init_link(tmp);
      return ;
    }
    else
      curr = curr->next;
  }
}

int main()
{
  t_room *head;

  head = init_rm(1);
  head->next = init_rm(2);
  head->next->next = init_rm(3);
  printf("First: %d, Second: %d, Third: %d\n", head->id, head->next->id, head->next->next->id);
  int arr[2] = {1, 3};
  setup_link(arr, head);
  printf("Room ID: %d, AdjRms: %d\n", head->id, head->adjlist->adjrm->id);
}
