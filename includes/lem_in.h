/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:27:35 by scollet           #+#    #+#             */
/*   Updated: 2017/12/11 21:27:37 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_link {
  int key;
  struct s_link *next;
  struct s_link *prev;
}              t_link;

typedef struct s_map {
  int start;
  int alive;
  int end;
  int occ;
  int score;
  int x;
  int y;
  int key;
  char *name;
  struct s_link *link;
  struct s_map *next;
  struct s_map *prev;
}              t_map;

typedef struct s_colony {
  int num_ants;
  t_map **map;
}              t_colony;

void ants_go(t_colony *colony);
void	expletive(char *loc);
int hash(char *str);
void  init_map(t_colony *colony);
t_colony *new_colony(void);
t_link *new_link(void);
int parse(t_colony *colony, int fd);

#endif
