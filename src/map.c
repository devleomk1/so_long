/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:37:55 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/26 05:20:45 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ext(char *str, char *ext)
{
	int	i;
	int	j;

	i = 0;
	if (ext[0] != '.')
		exit_err("Invalid function parameter. ext[0] must be dot charter\n");
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (!str[i])
		exit_err("Wrong extension or file path.\n");
	j = 0;
	while (str[i + j] != '\0' && ext[j] != '\0')
	{
		if (str[i + j] == ext[j])
			j++;
		else
			break ;
	}
	if (!(str[i + j] == '\0' && ext[j] == '\0'))
		exit_err("Wrong extension or file path.\n");
	return (TRUE);
}

/**
 * check map file components
 * 0 : an empty space.
 * 1 : a wall.
 * C : a collectible.
 * E : map exit.
 * P : the player’s starting position.
 */
int	check_map_compo(char c)
{
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == ' ' /*|| c == '\n'*/)
		return (TRUE);
	return (FALSE);
}

int	is_map_rectangle(t_game *game, int len2)
{
	int len1;

	len1 = game->maps.cols;
	if (len1 != len2)
	{
		printf("len1 : %d\n", game->maps.cols);
		printf("len2 : %d\n", len2);
		return (FALSE);
	}
	return (TRUE);
}

/**
 * 			col 0	col 1
 * row 0	[  ]	[  ]
 * row 1	[  ]	[  ]
 */
void	count_max_rows_cols(t_game *game, int fd)
{
	int		read_size;
	int		tmp_cols;
	char	c;

	game->maps.rows = 0;
	game->maps.cols = 0;
	read_size = 1;
	tmp_cols = 0;
	while (read_size > 0)
	{
		read_size = read(fd, &c, 1);
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

int	open_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit_err("File open fail\n");
	return (fd);
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
				break ;
			j++;
		}
		i++;
		free(line);
	}
	free(line);
	close(fd);
}

void	get_compo_coord(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			if (game->maps.coord[i][j] == 'P')
			{
				game->player.x = i;
				game->player.y = j;
			}
			else if (game->maps.coord[i][j] == 'C')
			{

			}
			j++;
		}
		i++;
	}
}

void	file_read(t_game *game, char *filename)
{
	int		fd;
	int		gnl;

	check_ext(filename, MAP_EXT);
	fd = open_file(filename);
	map_malloc(game, fd);
	close(fd);
	map_load(game, filename);
	get_compo_coord(game);
}
