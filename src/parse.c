/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:39:40 by scollet           #+#    #+#             */
/*   Updated: 2017/12/11 21:39:42 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Collision-less hashmap beeeeyitch
*/

void parse_links(t_colony *colony, char *this)
{
  char *s;
  int key1;
  int key2;

  key1 = hash(this);
  // printf("returned hash 1 to parse_links() -> %d\n", key1);
  lock(key1, colony, this);
  s = ft_strchr(this, '-');
  this = ++s;
  key2 = hash(this);
  // printf("returned hash 2 to parse_links() -> %d\n", key2);
  // lock(key1, colony);
  lock(key2, colony, this);

  // printf("after checking links\n");
  colony->map[key1]->link->key = key2;
  colony->map[key2]->link->key = key1;
  while (colony->map[key1]->link->prev)
    colony->map[key1]->link = colony->map[key1]->link->prev;
  while (colony->map[key2]->link->prev)
    colony->map[key2]->link = colony->map[key2]->link->prev;
  // printf("left parse_links()\n");
}

void parse_coords(t_colony *colony, char *this, int place)
{
  int key;
  char *s;

  key = hash(this);
  // printf("returned hash to parse_coords() -> %d\n", key);
  if (colony->map[key]->alive)
  {
    printf("collision detected\n");
    while (colony->map[key]->next)
      colony->map[key] = colony->map[key]->next;
  }
  colony->map[key]->alive = 1;
  if (place == 1)
  {
    colony->start = key;
    colony->map[key]->start = 1;
  }
  if (place == 2)
  {
    colony->end = key;
    colony->map[key]->end = 1;
  }
  colony->map[key]->key = key;
  colony->map[key]->name = (char*)ft_memalloc(sizeof(char) *
  ft_strlen(this));
  ft_memccpy(colony->map[key]->name, this, ' ',
  ft_strlen(this) - ft_strlen(ft_strchr(this, ' ')));
  s = ft_strchr(this, ' ');
  colony->map[key]->x = ft_atoi(s++);
  // printf("key x coord -> %d\n", colony->map[key]->x);
  while (ft_isdigit(*s++))
    ;
  colony->map[key]->y = ft_atoi(s);
  // printf("key y coord -> %d\n", colony->map[key]->y);
  if (this)
    free(this);
}

int parse(t_colony *colony, int fd)
{
  char *this;
  int lt;

  init_map(colony);
  if (get_next_line(fd, &this) < 0)
    return (-1);
  colony->num_ants = ft_atoi(this);
  while ((lt = get_next_line(fd, &this)) > 0)
  {
    // printf("parse : line read -> %s\n", this);
    if (ft_strstr(this, "##start"))
    {
      if (get_next_line(fd, &this) < 0)
        return (-1);
      printf("start %s\n", this);
      parse_coords(colony, this, 1);
    }
    else if (ft_strstr(this, "##end"))
    {
      if (get_next_line(fd, &this) < 0)
        return (-1);
      printf("end %s\n", this);
      parse_coords(colony, this, 2);
    }
    else if (ft_strstr(this, "-"))
      parse_links(colony, this);
    else if (ft_strstr(this, "#"))
      continue ;
    else
      parse_coords(colony, this, 0);
  }
  if (this)
    free(this);
  return (lt);
}
