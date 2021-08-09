/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:37:55 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/08 13:01:23 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * 			col 0	col 1
 * row 0	[  ]	[  ]
 * row 1	[  ]	[  ]
 */

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit_err("File open fail\n");
	return (fd);
}

void	count_max_rows_cols(t_game *game, int fd)
{
	int		tmp_cols;
	char	c;

	game->maps.rows = 0;
	game->maps.cols = 0;
	tmp_cols = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (game->maps.cols < tmp_cols)
			game->maps.cols = tmp_cols;
		if (c == '\n')
		{
			game->maps.rows++;
			tmp_cols = 0;
		}
		else
			tmp_cols++;
	}
}

void	map_malloc(t_game *game, int fd)
{
	int	i;

	count_max_rows_cols(game, fd);
	game->maps.coord = (char **)malloc(sizeof(char *) * (game->maps.rows));
	i = 0;
	while (i < game->maps.rows)
	{
		game->maps.coord[i] = (char *)malloc(sizeof(char) * (game->maps.cols));
		i++;
	}
	ft_memset(&(game->maps.coord[0][0]), ' ',
		(game->maps.cols * game->maps.rows));
}

void	map_load(t_game *game, char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open_file(filename);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_map_rectangle(game, ft_strlen(line)) == FALSE)
			exit_err("Map file is not rectangular.\n");
		j = 0;
		while (j < game->maps.cols)
		{
			if (check_map_compo(line[j]) == TRUE)
				game->maps.coord[i][j] = line[j];
			else
				exit_err("Invalid components found in map file.");
			j++;
		}
		i++;
		free(line);
	}
	free(line);
	close(fd);
}

void	file_read(t_game *game, char *filename)
{
	int		fd;

	check_ext(filename, MAP_EXT);
	fd = open_file(filename);
	map_malloc(game, fd);
	close(fd);
	map_load(game, filename);
	if (is_map_walled(game->maps) == FALSE)
		exit_err("Map is not walled.\n");
	get_compo_coord(game);
}
