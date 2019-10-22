/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:32:23 by dchen             #+#    #+#             */
/*   Updated: 2019/10/19 20:32:26 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_pressed(int keycode, t_controller *controller)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124)
		controller->pan_x += (keycode == 124) ? .04 : -.04;
	if (keycode == 126 || keycode == 125)
		controller->pan_y += (keycode == 125) ? .04 : -.04;
	if (keycode == 38)
		controller->type = 1;
	if (keycode == 46)
		controller->type = 0;
	if (keycode == 11)
		controller->type = 2;
	if (keycode == 14)
		controller->type = 3;
	if (keycode == 2)
		controller->zoom = 200;
	draw(controller);
	return (0);
}

int		mouse_cb(int x, int y, t_controller *controller)
{
	if (controller->type == 1)
	{
		controller->mouse.x = x * 4.0 / WIN_X - 2;
		controller->mouse.y = y * 4.0 / WIN_Y - 2;
		draw(controller);
	}
	return (0);
}

int		scroll_cb(int key, int x, int y, t_controller *controller)
{
	if (x <= WIN_X && x >= 0 && y >= 0 && y < WIN_Y)
	{
		if (key == 4)
		{
			controller->zoom += 100;
		}
		else if (key == 5 && controller->zoom > 100)
		{
			controller->zoom -= 100;
		}
		draw(controller);
	}
	return (0);
}
