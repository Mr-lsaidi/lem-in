/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 21:47:50 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/16 21:38:50 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_H
# define VIS_H
# include "../../libft/includes/libft.h"
# include <SDL.h>
# include <stdlib.h>
# include <SDL_ttf.h>
# include <SDL_keycode.h>
# include <SDL_image.h>
# include <SDL_video.h>
# include <stdlib.h>
# include <SDL_ttf.h>
# include <SDL2_gfxPrimitives.h>
# define IMG_PATH "visualizer/img/icon1.png"
# define IMG_PATH_S "visualizer/img/start_icon.png"
# define IMG_PATH_E "visualizer/img/icon2.png"
# define IMG_PATH_ANT "visualizer/img/ant.png"
# define IMG_PATH_SCORE "visualizer/img/score.png"
# define N_COLORS 2

typedef struct	s_room
{
	int				id;
	int				w;
	int				way;
	int				id_ant;
	int				is_ant;
	struct s_room	*parent;
	struct s_room	*next;
}				t_room;

typedef struct	s_v
{
	char			*name;
	int				id;
	double			x;
	double			y;
	int				lvl;
	int				visited;
	int				visited2;
	int				parent;
	int				in;
	int				lvl_vis;
	int				nb_rooms;
	int				ant;
	int				id_ant;
	struct s_room	*rooms;
	struct s_v		*next;
}				t_v;

typedef struct	s_q
{
	int			id;
	int			in;
	t_room		*room;
	struct s_q	*next;
}				t_q;

typedef struct	s_lem
{
	char		**mat;
	t_v			*v;
	t_v			**hp;
	int			nbant;
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
	char		*visited;
	int			xoffset;
	int			yoffset;
	int			xrel;
	int			yrel;
	float		scale;
	int			loop;
	int			id_gp;
	int			cmp;
	int			nb_ants_pass;
	int			nb_ants_ended;
	int			frame_ants;
	int			num;
}				t_lem;

typedef struct	s_spliter
{
	int					id;
	struct s_spliter	*next;
}				t_spliter;

typedef struct	s_ants
{
	double			addx;
	double			addy;
	double			length;
	double			x;
	double			y;
	int				rooms_id;
	int				nextrooms_id;
	int				id_ant;
	struct s_ants	*next;
}				t_ants;

typedef struct	s_inst
{
	struct s_ants	*ants;
	struct s_inst	*next;
}				t_inst;

typedef struct	s_vis
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*img_room;
	SDL_Texture		*img_start;
	SDL_Texture		*img_end;
	SDL_Texture		*img_ant;
	SDL_Surface		*rooms_text;
	SDL_Texture		*texture2;
	TTF_Font		*police;
	SDL_Event		movement;
	SDL_Rect		rect;
	SDL_Rect		ants;
	SDL_Color		color;
	SDL_Rect		rooms_name;
	int				h;
	int				w;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				moyenn_x;
	int				moyenn_y;
	int				height_correct;
	int				class;
	int				get_id;
	int				height;
	int				width;
	int				max_lvl;
	int				rooms_size_x;
	int				rooms_size_y;
	int				ant_size_x;
	int				ant_size_y;
	int				line_radian;
	int				text_w;
	int				text_h;
	double			addx;
	double			addy;
	double			length;
}				t_vis;

void			init_vars(t_vis	*vis, t_lem **lem);
void			init_tool(t_vis *vis);
int				close_sdl(t_vis *vis, t_lem *lem);
int				manager_event(t_vis *vis, t_lem *lem);
void			start_vis(t_spliter **vis_splite, t_vis	*vis, t_lem **lem);
void			drow_rooms(t_lem **lem, t_vis *vis, int x, int y);
void			drow_lines(t_lem *lem, t_vis *vis);
int				get_max_lvl(t_lem *lem);
int				drow_ants(t_inst *inst, t_vis *vis, t_lem *lem);
void			print_roomnames(t_lem **lem, t_vis *vis, int x, int y);
void			index_lvl(t_lem **lem);
void			drow_line_all(t_lem *lem, t_vis *vis);
void			drow_rooms_all(t_lem *lem, t_vis *vis);
void			print_rooms_lines(t_vis *vis, t_lem *lem);
void			and_inst(t_inst **ins);
void			ant_inst(t_inst **ins, t_inst *new);
t_inst			*create_node(void);
void			read_rest(t_lem *lem, t_inst **inst);
int				read_file(t_lem **lem, t_spliter *vis_split, t_vis *vis);
t_v				*new_v(char *name, int x, int y, int id);
void			add_v(t_v **v, t_v *new);
void			free_mx(char **tab);
int				read_rooms(t_lem **lem, int i);
void			free_v(t_v **lst);
void			free_lem(t_lem **lem);
t_q				*new_q(int id);
void			add_q(t_q **q, t_q *new);
void			free_q(t_q **lst);
void			dlt_q(t_q **q);
t_room			*new_room(int id);
int				start_adlist(t_lem **lem);
void			drow_select_lines(t_ants *ants, t_lem *lem, t_vis *vis);
void			ants_move(t_ants *ants, t_lem *lem, t_vis *vis, int *i);
void			deletelist(t_ants **ants);
void			small_big_init(t_vis *vis, t_lem **lem);
void			read_rest(t_lem *lem, t_inst **inst);
void			last_format2(t_ants **ants, int s_r, int f_r, t_lem **lm);
void			update_wieght(t_lem **lem);
int				size(t_ants *ants);
void			spesial_one(t_ants *ants, t_lem *lem, t_vis *vis, int *i);
#endif
