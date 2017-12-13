/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:27:44 by scollet           #+#    #+#             */
/*   Updated: 2017/12/11 21:27:45 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(void)
{
  t_colony *colony;

  colony = new_colony();
  if (parse(colony, 0) < 0)
    expletive("Bad file\n");
  ants_go(colony);
  return (0);
}
