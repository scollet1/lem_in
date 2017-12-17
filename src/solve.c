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

t_link *optimal(t_colony *colony, t_link *link)
{
  t_link *l;
  int score;

  l = link;
  score = 0;
  while (link)
  {
    if (score < colony->map[link->key]->score)
    {
      l = link;
      score = colony->map[link->key]->score;
    }
    if (link->key == colony->end)
      l = link;
    link = link->next;
  }
  return (l);
}

int traverse(t_colony *colony, int key, int ants)
{
  t_link *tmp;
  int score;
  int dist;
  int k;

  tmp = colony->map[key]->link;
  // score = 0;
  dist = colony->map[tmp->key]->distance;
  // printf("key -> %d\n", key);
  while (ants)
  {
    printf("\n------------ number ants -> %d ------------\n\n", ants);
    score = 0;
    k = optimal(colony, tmp)->key;
    printf("%s\n", colony->map[k]->name);
    if (colony->map[k]->occ)
    {
      if (k == colony->end)
      {
        printf("ant from %s -> out\n", colony->map[k]->name);
        colony->map[k]->occ = 0;
        ants -= 1;
        tmp = colony->map[key = colony->start]->link;
      }
      else
      {
        if (colony->map[optimal(colony, colony->map[k]->link)->key]->occ)
        {
          tmp = optimal(colony, colony->map[k]->link);
          key = tmp->key;
        }
        else
        {
          printf("ant from %s -> %s\n", colony->map[k]->name,
          colony->map[optimal(colony, colony->map[k]->link)->key]->name);

          // ants -= 1;
          colony->map[k]->occ = 0;
          tmp = colony->map[key = colony->start]->link;
          colony->map[optimal(colony, colony->map[k]->link)->key]->occ = 1;
        }
        // printf("ant collision at -> %s\n", colony->map[k]->name);
        // if ((colony->map[k]->occ = traverse(colony, k, ants)))
          // return (traverse(colony, k, ants));
        // else
          // return (traverse(colony, k, ants - 1));
      }
      // return (1);
      // return (colony->map[k]->occ);
    }
    else
    {
      printf("ant from %s -> %s\n", colony->map[key]->name, colony->map[k]->name);
      colony->map[k]->occ = 1;
      colony->map[key]->occ = 0;
      // ants -= 1;
      tmp = colony->map[key = colony->start]->link;
      // traverse(colony, colony->start, ants - 1);
      // return (0);
    }
    // return (1);
  }
  return (0);
}

/*
** recursively score each path for the decision-making algorithm
*/

int score_paths(t_colony *colony, int key, int d)
{
  t_link *tmp;

  tmp = colony->map[key]->link;
  // if (!key)
    // return (1);
  if (d > colony->depth)
    colony->depth = d;
  if (colony->map[key]->visited)
    return (1);
  colony->map[key]->visited = 1;
  colony->map[key]->distance = d;

  while (tmp)
  {
    printf("score for some stuff -> %s -> %d\n",
    colony->map[key]->name, colony->map[key]->score);

    colony->map[key]->score += score_paths(colony, tmp->key, d + 1);
    tmp = tmp->next;
  }
  // while (colony->map[key]->link->prev)
    // colony->map[key]->link = colony->map[key]->link->prev;
  if (key == colony->end)
    return (10);
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
  // printf("scoring with -> %d\n", colony->start);
  // printf("shiiiiit -> %s\n", colony->map[colony->start]->link->name);
  // while (colony->map[colony->start]->link)
  // {
    // printf("kys -> %s\n", colony->map[colony->start]->link->name);
    // colony->map[colony->start]->link = colony->map[colony->start]->link->next;
  // }
  if (score_paths(colony, colony->start, 0) < 0)
    return (-1);
  // printf("shiiiiit -> %s\n", colony->map[colony->start]->link->name);
  // printf("colony first link  -> %d\n", colony->map[colony->start]->link->key);
  // while (colony->map[colony->start]->link->prev)
    // colony->map[colony->start]->link = colony->map[colony->start]->link->prev;
  // if (colony->map[colony->start]->link)
    // printf("fuck u\n");
  // colony->map[colony->start]->link = colony->map[colony->start]->link->prev;
  // printf("%s\n", colony->map[colony->start]->link->name);
  // printf("paths scored\n");

  traverse(colony, colony->start, colony->num_ants);
  // printf("paths explored\n");
  return (0);
}
