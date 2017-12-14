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

void traverse(t_colony *colony, int key)
{
  int score;
  int k;

  score = 0;
  printf("setting key\n");
  k = colony->map[key]->link->key;
  printf("key set at -> %d\n", k);
  while (colony->map[key]->link)
  {
    printf("score for link -> %d\n", colony->map[colony->map[key]->link->key]->score);
    if (score < colony->map[colony->map[key]->link->key]->score)
    {
      k = colony->map[key]->link->key;
      printf("key -> %d\ninfo -> %s\n", k, colony->map[k]->name);
    }
    colony->map[key]->link = colony->map[key]->link->next;
  }
  printf("occupying map street\n");
  if (k > 0)
    colony->map[k]->occ = 1;
  printf("occupado\n");
  if (k > 0)
  {
    if (colony->map[k]->occ)
    {
      printf("occupied -> %s\n", colony->map[k]->name);
      traverse(colony, k);
    }
  }
}

int score_paths(t_colony *colony, int key, char *name)
{
  if (!colony->map[key])
    return (0);
  printf("shit -> %s\nand stuff -> %s\n", colony->map[key]->name, name);
  while (colony->map[key]->prev)
    colony->map[key] = colony->map[key]->prev;
  if (name)
    while (ft_strcmp(colony->map[key]->name, name))
      if (colony->map[key]->next)
        colony->map[key] = colony->map[key]->next;
  printf("scoring path -> %s\n", colony->map[key]->name);
  // if (colony->map[key]->score > 0)
  printf("scoring key -> %s with score -> %d\n", colony->map[key]->name, colony->map[key]->score);
  // printf("score -> %d\n", colony->map[key]->score);
  if (key == colony->end)
  {
    printf("end found at -> %s\n", colony->map[key]->name);
    return (1);
  }
  if (colony->map[key]->visited)
    return (1);
  colony->map[key]->visited = 1;
  while (colony->map[key]->link)
  {
    printf("loopin -> %d\n", key);
    // while (colony->map[key]->link->name != colony->map[k])
    // printf("links -> %s\n", colony->map[key]->link->name);
    colony->map[key]->score +=
    score_paths(colony, colony->map[key]->link->key,
      colony->map[colony->map[key]->link->key]->name);
    colony->map[key]->link =
    colony->map[key]->link->next;
  }
  return (0);
}

int ants_go(t_colony *colony)
{
  if (colony->end < 0 || colony->start < 0)
    return (-1);
  printf("ants ready to explore\n");
  // if (!colony->map[start]->start)
  while (!colony->map[colony->start]->start)
    colony->map[colony->start] =
    colony->map[colony->start]->next;
  if (score_paths(colony, colony->start, colony->map[colony->start]->name) < 0)
    return (-1);
  // while (colony->map[colony->start]->link->prev)
    // colony->map[colony->start]->link =
    // colony->map[colony->start]->link->prev;
  printf("%s\n", colony->map[colony->start]->link->name);
  printf("paths scored\n");
  traverse(colony, colony->start);
  printf("paths explored\n");
  return (0);
}
