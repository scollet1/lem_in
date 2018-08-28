/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:51:09 by scollet           #+#    #+#             */
/*   Updated: 2017/12/12 11:51:10 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void lock(int key, t_colony *colony, char *this)
{
  if (!colony->map[key]->link)
  {
    // printf("muhfuckaa -> %s\n", this);
    colony->map[key]->link = new_link(this);
    return ;
  }
  while (colony->map[key]->link->next)
  {
    colony->map[key]->link->next->prev = colony->map[key]->link;
    colony->map[key]->link = colony->map[key]->link->next;
  }
  if (!colony->map[key]->link->next)
  {
    // printf("two tho -> %s\n", this);
    colony->map[key]->link->next = new_link(this);
    colony->map[key]->link->next->prev =
    colony->map[key]->link;
  }
}

int hash(char *str)
{
  size_t h;
  int len;
  int ret;
  int i;

  h = 0;
  len = ft_strlen(str);
  i = 0;
  while (str[i] != ' ' && str[i] != '-' && i < len)
    h += str[i++];
  ret = (int)((h * 997) % 1024);
  return ((ret) ? ret : ret + 1);
}
