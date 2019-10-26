/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 21:47:50 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/20 17:30:32 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"

typedef struct	s_room
{
	int				id;
	int				way;
	int				in;
	int				is_ant;
	int				id_ant;
	struct s_room	*parent;
	struct s_room	*next;
	struct s_room	*prev;
}				t_room;

typedef struct	s_v
{
	char			*name;
	int				id;
	int				x;
	int				y;
	int				lvl;
	int				visited;
	int				parent;
	int				in;
	int				nb_rooms;
	struct s_room	*rooms;
	struct s_v		*next;
}				t_v;

typedef struct	s_file
{
	char			*line;
	struct s_file	*next;
}				t_file;

typedef struct	s_q
{
	int			id;
	int			in;
	int			parent;
	t_room		*room;
	struct s_q	*next;
}				t_q;

typedef struct	s_path
{
	int				v_nb;
	int				nb_ant;
	int				capacity;
	struct s_room	*rooms;
	struct s_path	*next;
}				t_path;

typedef struct	s_groupe
{
	t_path			*paths;
	int				ninst;
	struct s_groupe	*next;
}				t_groupe;

typedef struct	s_lem
{
	t_v			*v;
	t_v			**hp;
	t_groupe	*groupes;
	t_groupe	*fnlgrps;
	t_groupe	*best_gp;
	t_room		*endroom;
	t_file		*file;
	char		**split;
	int			nb_ants_pass;
	int			vstd_cmp;
	int			nbant;
	int			routes;
	int			ks;
	char		*line;
	char		*start;
	int			xs;
	int			ys;
	char		*end;
	int			xe;
	int			ye;
	int			se;
	int			v_ln;
	int			i1;
	int			i2;
	int			nb_paths;
	int			is_visu;
}				t_lem;

int				read_file(t_lem **lem);
t_v				*new_v(char *name, int x, int y, int id);
void			add_v(t_v **v, t_v *new);
void			free_mx(char ***tab);
int				read_rooms(t_lem **lem, int i);
void			free_v(t_v **lst);
void			free_lem(t_lem **lem);
int				index_room(t_lem **lem);
t_q				*new_q(int id, int in);
void			add_q(t_q **q, t_q *new);
void			free_q(t_q **lst);
void			dlt_q(t_q **q);
void			get_paths(t_lem **lem);
void			add_vpath(t_path **path, int id);
t_path			*new_path(int nb);
t_room			*new_room(int id);
int				start_adlist(t_lem **lem);
void			add_groupe(t_groupe **grp, t_groupe *new);
t_groupe		*new_groupe(void);
void			free_link(t_lem **lem);
void			free_rooms(t_room **rms);
void			free_grps(t_lem **lem);
void			get_groups(t_lem **lem);
void			add_path(t_path **pth, t_path *new);
void			add_pathroom(t_path **pth, t_room *rm);
int				get_groups2(t_lem **lem);
void			start_bfs(t_lem **lem, t_path **pth);
void			free_paths(t_path **pth);
void			make_paths(t_lem **lem);
void			make_paths2(t_lem **lem);
int				get_way(t_lem **lem, int id1, int id2);
void			add_qrm(t_q **q, t_q *new, t_room *room);
t_path			*get_shrtpathroom(t_lem **lem, t_room *endroom);
void			nb_ants_path(t_lem **lem);
void			add_line(t_lem **lem, char *line);
void			free_file(t_lem **lem);
void			print_file(t_lem **lem);
void			malloc_error(void);
void			select_solution(t_lem **lem, t_groupe *group);
int				check_loop(t_lem **lem);
void			print_error(void);
void			start_solution(t_lem **lem);
#endif
