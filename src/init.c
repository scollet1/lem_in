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

t_link *new_link(void)
{
  t_link *link;

  link = (t_link*)ft_memalloc(sizeof(t_link));
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
  // char *this;

  new = (t_colony*)ft_memalloc(sizeof(t_colony));
  // if (this)
    // free(this);
  return (new);
}
