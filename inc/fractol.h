/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:49:03 by dchen             #+#    #+#             */
/*   Updated: 2019/10/19 19:55:12 by dchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

# define WIN_X 800
# define WIN_Y 600
# define WIN_TITLE "FRACTOL"
# define MAX_ITERATION 100

typedef struct			s_mouse
{
	float				x;
	float				y;
}						t_mouse;

typedef struct			s_img
{
	void				*img_ptr;
	char				*img_data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef	struct			s_controller
{
	void				*mlx;
	void				*win;
	float				pan_x;
	float				pan_y;
	float				zoom;
	float				(*f_type[4])(float, float, struct s_controller);
	int					type;
	t_mouse				mouse;
	t_img				*img;
}						t_controller;

void					set_values(t_controller *controller);
float					mandelbrot(float x, float y,
											struct s_controller controller);
void					draw(t_controller	*controller);
void					add_color(int x, int y, float value, t_img	*img);
float					julia(float x, float y,
										struct	s_controller controller);
int						mouse_cb(int x, int y, t_controller	*controller);
int						key_pressed(int keycode, t_controller	*controller);
int						scroll_cb(int key, int x, int y,
												t_controller	*controller);
float					extra_fractal(float x, float y,
												struct s_controller controller);
float					burning_ship(float x, float y,
												struct s_controller controller);
void					print_controls(t_controller	*controller);

#endif
