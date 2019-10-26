# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 20:58:18 by lsaidi            #+#    #+#              #
#    Updated: 2019/07/17 18:50:28 by sbahaddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem-in

VISU=visu

CFLAGS= -Werror -Wextra -Wall 

SRC=src/calc_inst.c src/file_save.c src/fill_adlist.c src/free_alloc.c src/free_alloc2.c \
	src/fun_struct.c src/get_groups.c src/get_paths.c src/group_struct.c src/main.c src/print_solution.c \
	src/pars_file.c src/parse_room.c src/prt_error.c src/q_functs.c src/solution.c src/struct_path.c

SRC_VIS=visualizer/vis_src/drow_line.c visualizer/vis_src/drow_rooms.c visualizer/vis_src/drow_vis.c \
	visualizer/vis_src/events_manager.c visualizer/vis_src/fill_adlist.c \
	visualizer/vis_src/free_alloc.c visualizer/vis_src/fun_struct.c visualizer/vis_src/init.c \
	visualizer/vis_src/init_tool_vis.c visualizer/vis_src/instr_moves.c visualizer/vis_src/main.c \
	visualizer/vis_src/pars_file.c visualizer/vis_src/parse_room.c visualizer/vis_src/print_results.c \
	visualizer/vis_src/struct_path.c

HEAD=includes

HEAD_VIS=visualizer/includes

LIB=libft/libft.a

SDL_LIBS=-L ~/.brew/Cellar/sdl2_gfx/1.0.4/lib -L \
~/.brew/Cellar/sdl2_image/2.0.4/lib -L ~/.brew/Cellar/sdl2_ttf/2.0.15/lib \
-lSDL2_image -L ~/.brew/Cellar/sdl2/2.0.9_1/lib\
-L ~/.brew/Cellar/sdl2_ttf/2.0.15/lib/\
-lSDL2 -lSDL2_ttf -lSDL2main -lSDL2_test \
-lSDL2_gfx -D_THREAD_SAFE

SDL_INC= -I ~/.brew/include/SDL2 -I ~/.brew/Cellar/sdl_gfx/2.0.26/include/SDL\
-I ~/.brew/Cellar/sdl2_image/2.0.4/include/SDL2\
-I ~/.brew/Cellar/sdl2_gfx/1.0.4/include -I ~/.brew/include/SDL2\
-I ~/.brew/Cellar/sdl2_ttf/2.0.15/include

_END= \x1b[0m
_RED= \x1b[31m
_GREEN= \x1b[32m

OBJ_SRC= $(SRC:.c=.o)

OBJ_VIS= $(SRC_VIS:.c=.o)

all : $(NAME) $(VISU)

$(NAME): $(OBJ_SRC)
	@cat ant.sh
	@echo "\n$(_RED)bilding lem-in....$(_END)"
	@sleep 0.2
	@make -C libft
	@gcc -I$(HEAD) $(LIB) $(OBJ_SRC) $(CFLAGS) -o $(NAME)
	@echo "     make $(_GREEN)[done].$(_END)"

$(VISU): $(OBJ_VIS) 
	@echo "$(_RED)bilding Visu....$(_END)"
	@sleep 0.2
	@make -C libft
	@gcc -I$(HEAD_VIS) $(LIB) $(OBJ_VIS) $(CFLAGS) $(SDL_INC) $(SDL_LIBS) -o $(VISU)
	@echo "     make $(_GREEN)[done].$(_END)"

$(OBJ_SRC): %.o : %.c
	@gcc -o $@ -c $< $(CFLAGS) -I $(HEAD)

$(OBJ_VIS): %.o : %.c
	@gcc -o $@ -c $< $(CFLAGS) -I $(HEAD_VIS) $(SDL_INC)

clean :
	@echo "$(_RED)clean src$(_END)"
	@/bin/rm -rf $(OBJ_SRC) $(OBJ_VIS)
	@sleep 0.2
	@echo "$(_RED)clean libft$(_END)"
	@make -C libft clean
	@sleep 1
	@echo "    make clean $(_GREEN)[done].$(_END)"

fclean : clean
	@echo "$(_RED)fclean $(NAME) $(VISU) $(_END)"
	@/bin/rm -rf $(NAME) $(VISU)
	@sleep 0.2
	@echo "$(_RED)fclean libft$(_END)"
	@make -C libft fclean
	@echo "    make fclean $(_GREEN)[done].$(_END)"

re : fclean all