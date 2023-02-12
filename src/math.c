/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:52:28 by mechane           #+#    #+#             */
/*   Updated: 2023/02/07 12:40:59 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_power(double x)
{
	return (x * x);
}

double	ft_opert(double x, double y, int indx)
{
	if (indx == 1)
		return (ft_power(x) - ft_power(y));
	else
		return (2 * x * y);
}
