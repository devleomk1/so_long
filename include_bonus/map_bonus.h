/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:14:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/08/10 16:36:18 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

typedef struct s_compo
{
	int		p;
	int		e;
	int		c;
	int		r;
}			t_compo;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**coord;
	char	*file;
	t_compo	cnt;
}			t_map;

# define MAP_EXT		".ber"

# define TILE_SIZE		64

typedef struct s_game	t_game;

int		check_ext(char *str, char *ext);
int		check_map_compo(char c);
int		is_map_rectangle(t_game *game, int len2);
int		is_map_walled(t_map maps);
void	count_max_rows_cols(t_game *game, int fd);
void	map_malloc(t_game *game, int fd);
int		open_file(char *filename);
void	map_load(t_game *game, char *filename);
void	get_compo_coord(t_game *game);
void	file_read(t_game *game, char *filename);

#endif
