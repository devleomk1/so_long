/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 20:37:55 by jisokang          #+#    #+#             */
/*   Updated: 2021/07/25 23:48:24 by jisokang         ###   ########.fr       */
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
 * check map components
 * 0 : an empty space.
 * 1 : a wall.
 * C : a collectible.
 * E : map exit.
 * P : the player’s starting position.
 */
int	check_map_compo(char c)
{
	//add ' ' for cub3d
	if (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P' || c == ' ' /*|| c == '\n'*/)
		return (TRUE);
	return (FALSE);
}

int	check_map_rectangle(void)
{
	return (0);
}

int	check_map(char **argv)
{
	return (0);
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
	tmp_cols = 0;
	while((read_size = read(fd, &c, 1)) > 0)
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
	ft_memset(&(game->maps.coord[0][0]), ' ', (game->maps.cols * game->maps.rows));
}

int		open_file(char *filename)
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

void	file_read(t_game *game, char *filename)
{
	int		fd;
	int		gnl;

	check_ext(filename, MAP_EXT);
	fd = open_file(filename);
	map_malloc(game, fd);
	close(fd);
	map_load(game, filename);
	int i = 0;
	int j = 0;
	while (i < game->maps.rows)
	{
		printf("\n");
		while (j < game->maps.cols)
		{
			printf("[%c]", game->maps.coord[i][j]);
			if (game->maps.coord[i][j] == 'P')
			{
				game->player.x = i;
				game->player.y = j;
				printf("Read player coord OK\n");
				printf("(%d, %d)\n", game->player.x, game->player.y);
			}
			//if (game->maps.coord[i][j] == 'C')
			j++;
		}
		j = 0;
		i++;
	}
}

//int	main(int argc, char **argv)
//{
//	if (check_ext(argv[1], ".ber"))
//	{
//		printf("Ext Check" GREEN" OK\n"RESET);
//	}
//	return (0);
//}
