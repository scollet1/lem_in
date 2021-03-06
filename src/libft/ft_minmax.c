/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:04:33 by scollet           #+#    #+#             */
/*   Updated: 2017/12/10 14:57:47 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	ft_minmax(unsigned m, unsigned a, unsigned b)
{
	if (m)
		return (a > b) ? a : b;
	return (a < b) ? a : b;
}
