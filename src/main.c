/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:55:42 by dchen             #+#    #+#             */
/*   Updated: 2019/10/21 01:06:12 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_controller	controller;
	t_img			img;

	if (ac < 2 || ac > 2 || av[1][0] > '3' || av[1][0] < '0' ||
													ft_strlen(av[1]) > 1)
	{
		write(1, "usage: ./fractol: 0(Mandlebrot), 1(Julia),", 42);
		write(1, "2(burnging_ship),3(extra_fractal)\n", 34);
	}
	else
	{
		controller.type = ft_atoi(av[1]);
		set_values(&controller);
		controller.img = &img;
		img.img_ptr = mlx_new_image(controller.mlx, WIN_X, WIN_Y);
		img.img_data = mlx_get_data_addr(img.img_ptr, &(img.bpp),
								&(img.size_line), &(img.endian));
		img.size_line /= 4;
		draw(&controller);
		mlx_hook(controller.win, 6, 0, mouse_cb, &controller);
		mlx_hook(controller.win, 2, 0, key_pressed, &controller);
		mlx_hook(controller.win, 4, 0, scroll_cb, &controller);
		mlx_loop(controller.mlx);
		print_controls(&controller);
	}
}

void	set_values(t_controller *controller)
{
	controller->f_type[0] = &mandelbrot;
	controller->f_type[1] = &julia;
	controller->f_type[2] = &burning_ship;
	controller->f_type[3] = &extra_fractal;
	controller->zoom = 200;
	controller->pan_x = 2;
	controller->pan_y = 1.5;
	controller->mlx = mlx_init();
	controller->win = mlx_new_window(controller->mlx, WIN_X,
			WIN_Y, "fractol");
}

void	print_controls(t_controller *controller)
{
	int y;

	y = 0;
	mlx_string_put(controller->mlx, controller->win, 50, y += 20, 0xFFFFFF,
													"User Instructions");
	mlx_string_put(controller->mlx, controller->win, 15, y += 20, 0xFFFFFF,
													"Zoom: Scroll Wheel");
	mlx_string_put(controller->mlx, controller->win, 15, y += 20, 0xFFFFFF,
											"Move: Arrows Keys");
	mlx_string_put(controller->mlx, controller->win, 15, y += 20, 0xFFFFFF,
											"Default Zoom: D");
	mlx_string_put(controller->mlx, controller->win, 15, y += 20, 0xFFFFFF,
											"Mandelbrot: M , Julia: J");
	mlx_string_put(controller->mlx, controller->win, 15, y += 20, 0xFFFFFF,
											"BurningShip: B, Extra: E");
}

void	add_color(int x, int y, float value, t_img *img)
{
	unsigned int	*stepper;
	unsigned int	color;
	int				i;

	color = 0xFFFFFF00 * pow(value, 6);
	i = ((int)x) + ((int)y * img->size_line);
	stepper = (unsigned int*)img->img_data;
	stepper[i] = color;
}

void	draw(t_controller *controller)
{
	float x;
	float y;
	float value;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			value = controller->f_type[controller->type](x / controller->zoom -
	controller->pan_x, y / controller->zoom - controller->pan_y, *controller);
			add_color(x, y, value, controller->img);
			x++;
		}
		y++;
	}
	mlx_clear_window(controller->mlx, controller->win);
	mlx_put_image_to_window(controller->mlx, controller->win,
								controller->img->img_ptr, 0, 0);
	print_controls(controller);
}
