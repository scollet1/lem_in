/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:32:47 by scollet           #+#    #+#             */
/*   Updated: 2017/12/11 21:32:49 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void copy(char *str, t_link *link)
{
  int i;
  int len;

  i = 0;
  len = ft_strlen(str);
  link->name = (char*)ft_memalloc(sizeof(char) * len + 2);
  while (str[i] != ' ' && str[i] != '-' && i < len)
  {
    link->name[i] = str[i];
    i++;
  }
}

t_link *new_link(char *this)
{
  t_link *link;

  link = (t_link*)ft_memalloc(sizeof(t_link));
  copy(this, link);
  link->next = NULL;
  // link->prev = NULL;
  return (link);
}

void  init_map(t_colony *colony)
{
  int i;

  i = -1;
  colony->map = (t_map**)ft_memalloc(sizeof(t_map*) * 1024);
  while (++i < 1024)
    colony->map[i] = (t_map*)ft_memalloc(sizeof(t_map));
}

t_colony *new_colony(void)
{
  t_colony *new;

  new = (t_colony*)ft_memalloc(sizeof(t_colony));
  new->start = -1;
  new->end = -1;
  return (new);
}
