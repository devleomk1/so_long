/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:33:16 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/01 02:18:12 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;

	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1024, 768, "mlx load img");
	img = mlx_xpm_file_to_image(mlx, "./bg_4x.xpm", &img_width, &img_height);
	//img = mlx_png_file_to_image(mlx, "./bg.png", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 65);
	mlx_loop(mlx);
}
