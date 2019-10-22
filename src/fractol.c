/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:30:42 by dchen             #+#    #+#             */
/*   Updated: 2019/10/19 20:30:44 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	mandelbrot(float x, float y, struct s_controller controller)
{
	float i;
	float temp_rc;
	float temp_ic;
	float real_comp;
	float imaginary_comp;

	(void)&controller;
	real_comp = x;
	imaginary_comp = y;
	i = 0;
	while (i < MAX_ITERATION)
	{
		temp_rc = ((real_comp * real_comp) -
								(imaginary_comp * imaginary_comp)) + x;
		temp_ic = (2 * real_comp * imaginary_comp) + y;
		real_comp = temp_rc;
		imaginary_comp = temp_ic;
		if (((real_comp * real_comp) + (imaginary_comp * imaginary_comp)) > 4)
			return (i / MAX_ITERATION);
		i++;
	}
	return (0);
}

float	julia(float x, float y, struct s_controller controller)
{
	float i;
	float temp_rc;
	float temp_ic;
	float real_comp;
	float imaginary_comp;

	real_comp = x;
	imaginary_comp = y;
	i = 0;
	while (i < MAX_ITERATION)
	{
		temp_rc = ((real_comp * real_comp) -
			(imaginary_comp * imaginary_comp)) + controller.mouse.x;
		temp_ic = (2 * real_comp * imaginary_comp) + controller.mouse.y;
		real_comp = temp_rc;
		imaginary_comp = temp_ic;
		if (((real_comp * real_comp) + (imaginary_comp * imaginary_comp)) > 4)
			return (i / MAX_ITERATION);
		i++;
	}
	return (0);
}

float	extra_fractal(float x, float y, struct s_controller controller)
{
	float i;
	float temp_rc;
	float temp_ic;
	float real_comp;
	float imaginary_comp;

	(void)&controller;
	real_comp = x;
	imaginary_comp = y;
	i = 0;
	while (i < MAX_ITERATION)
	{
		temp_rc = pow(real_comp, 3) - (3 * real_comp *
									pow(imaginary_comp, 3)) + x;
		temp_ic = (3 * pow(real_comp, 2) * imaginary_comp) -
										pow(imaginary_comp, 3) + y;
		real_comp = temp_rc;
		imaginary_comp = temp_ic;
		if (((real_comp * real_comp) + (imaginary_comp * imaginary_comp)) > 4)
			return (i / MAX_ITERATION);
		i++;
	}
	return (0);
}

float	burning_ship(float x, float y, struct s_controller controller)
{
	float i;
	float temp_rc;
	float temp_ic;
	float real_comp;
	float imaginary_comp;

	(void)&controller;
	real_comp = x;
	imaginary_comp = y;
	i = 0;
	while (i < MAX_ITERATION)
	{
		temp_rc = ((real_comp * real_comp) -
							(imaginary_comp * imaginary_comp)) + x;
		temp_ic = 2 * fabs(real_comp * imaginary_comp) + y;
		real_comp = temp_rc;
		imaginary_comp = temp_ic;
		if (((real_comp * real_comp) + (imaginary_comp * imaginary_comp)) > 4)
			return (i / MAX_ITERATION);
		i++;
	}
	return (0);
}
