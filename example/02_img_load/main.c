/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:33:16 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/03 17:18:11 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../mlx/mlx.h"

typedef struct	s_var
{
	void		*mlx;
	void		*win;
}				t_var;


typedef struct	s_img
{
	void		*ptr;
	int			w;
	int			h;
	int			x;
	int			y;
}				t_img;

void	*ft_xpm_to_img(void *mlx, char *str, t_img img)
{
	return(mlx_xpm_file_to_image(mlx, str, &img.w, &img.h));
}

void	ft_put_img_to_win(void *mlx, void *win, t_img img)
{
	mlx_put_image_to_window(mlx, win, img.ptr, img.x, img.y);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	t_img img00;
	//t_img img01;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1024, 768, "mlx load img");
	img00.ptr = ft_xpm_to_img(mlx, "./zelda_logo.xpm", img00);
	img00.x = 0;
	img00.y = 0;
	ft_put_img_to_win(mlx, win, img00);
	//img0 = mlx_xpm_file_to_image(mlx, "./bg_4x.xpm", &img0_width, &img0_height);
	//img1 = mlx_xpm_file_to_image(mlx, "./hero.xpm", &img1_width, &img1_height);
	//img = mlx_png_file_to_image(mlx, "./bg.png", &img_width, &img_height);
	//mlx_put_image_to_window(mlx, win, img0, 0, 65);
	//mlx_put_image_to_window(mlx, win, img1, 0, 65);
	//mlx_string_put(mlx, win, 100, 100, 0, "HELLO WORLD!");
	mlx_loop(mlx);
}
