/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:42:24 by scollet           #+#    #+#             */
/*   Updated: 2017/12/11 21:42:25 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** TODO : recursively score each paths for the decision-making algorithm
*/

int traverse(t_colony *colony, int key)
{
  t_link *tmp;
  int score;
  int k;

  tmp = colony->map[key]->link;
  score = 0;
  printf("key -> %d\n", key);
  k = tmp->key;
  // printf("what the actual fuck\n");
  if (colony->num_ants)
  {
    // printf("whhat the fuck\n");
    while (tmp)
    {
      if (score <= colony->map[tmp->key]->score)
        k = tmp->key;
      tmp = tmp->next;
    }
    if (colony->map[k]->occ)
    {
      colony->map[k]->occ =
      traverse(colony, k);
    }
    else
    {
      colony->map[k]->occ = 1;
      printf("ant from %s -> %s\n", colony->map[key]->name, colony->map[k]->name);
      colony->num_ants -= 1;
    }
  }
  return (0);
}

int score_paths(t_colony *colony, int key, int d)
{
  t_link *tmp;

  tmp = colony->map[key]->link;
  if (!key)
    return (1);
  if (colony->map[key]->visited)
    return (1);
  colony->map[key]->distance = d;
  printf("key dist -> %s, %d\n", colony->map[key]->name, colony->map[key]->distance);
  // printf("key -> %d\n", key);
  while (tmp)
  {
    printf("score for some stuff -> %s -> %d\n",
    colony->map[key]->name, colony->map[key]->score);

    colony->map[key]->visited = 1;
    colony->map[key]->score += score_paths(colony, tmp->key, d + 1);
    tmp = tmp->next;
  }
  // while (colony->map[key]->link->prev)
    // colony->map[key]->link = colony->map[key]->link->prev;
  return (1);
}

int ants_go(t_colony *colony)
{
  // t_queue *q;

  // q = (t_queue*)malloc(sizeof(t_queue));
  if (colony->end < 0 || colony->start < 0)
    return (-1);
  // printf("ants ready to explore\n");
  // while (!colony->map[colony->start]->start)
    // colony->map[colony->start] =
    // colony->map[colony->start]->next;
  // printf("colony starting at -> %d\n", colony->start);
  // while (colony->map[colony->start]->link->prev)
    // colony->map[colony->start]->link = colony->map[colony->start]->link->prev;
  printf("scoring with -> %d\n", colony->start);
  printf("shiiiiit -> %s\n", colony->map[colony->start]->link->name);
  // while (colony->map[colony->start]->link)
  // {
    // printf("kys -> %s\n", colony->map[colony->start]->link->name);
    // colony->map[colony->start]->link = colony->map[colony->start]->link->next;
  // }
  if (score_paths(colony, colony->start, 0) < 0)
    return (-1);
  printf("shiiiiit -> %s\n", colony->map[colony->start]->link->name);
  // printf("colony first link  -> %d\n", colony->map[colony->start]->link->key);
  // while (colony->map[colony->start]->link->prev)
    // colony->map[colony->start]->link = colony->map[colony->start]->link->prev;
  // if (colony->map[colony->start]->link)
    // printf("fuck u\n");
  // colony->map[colony->start]->link = colony->map[colony->start]->link->prev;
  // printf("%s\n", colony->map[colony->start]->link->name);
  printf("paths scored\n");

  traverse(colony, colony->start);
  printf("paths explored\n");
  return (0);
}
