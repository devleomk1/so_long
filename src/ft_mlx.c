/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 05:47:08 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/09 20:30:35 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_xpm_to_img(t_game *game, char *str)
{
	char	*path;
	void	*img;

	path = ft_strjoin(ASSET_PATH, str);
	img = mlx_xpm_file_to_image(game->mlx, path,
			&(game->img64.w), &(game->img64.h));
	free(path);
	if (img == NULL)
		exit_err("XPM to image fail! "
			"please check ASSET_PATH or image file.\n");
	return (img);
}

void	ft_put_img64(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img_ptr, x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_put_img(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, x, y);
}
