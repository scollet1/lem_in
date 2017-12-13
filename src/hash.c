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

int hash(char *str)
{
  size_t h;
  int len;
  int i;

  h = 0;
  len = ft_strlen(str);
  i = 0;
  while (str[i] != ' ' && str[i] != '-' && i < len)
  {
    // printf("hashing : char -> %c\n", str[i]);
    h += str[i++];
  }
  // printf("leaving hashing func()\n");
  return ((int)((h * 17) % 1024));
}
