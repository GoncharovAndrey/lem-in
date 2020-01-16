NAME_LEM_IN = lem_in
LIBFT_A = lib/libft/libft.a
LIBFTPRINTF_A = lib/libftprintf.a
FLAGS =
COMP =		gcc -c -o
PUSH_SWAP_H = -I includes/

OBJ_DIR =	./obj/

SRC_DIR =	./src/

C_FILE =	avl_rotation.c \
			avl_tree.c \
			bfs.c \
			ft_all_malloc.c \
			ft_check_map.c \
			ft_choose_way.c \
			ft_find_ways.c \
			ft_for_find_ways.c \
			ft_free_all.c \
			ft_init_structure.c \
			ft_other.c \
			ft_print_res.c \
			list.c \
			main.c \
			pave_the_way.c \
			read_map.c

C_FIND =		$(addprefix $(SRC_P_DIR), $(C_FILE))

O_FILE =		$(C_FILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(O_FILE))

all: $(NAME_LEM_IN)

$(NAME_LEM_IN): $(OBJ_DIR) $(OBJ)
	@make -C lib/
	@gcc $(LIBFTPRINTF_A) $(OBJ) -o lem_in
	@echo lem_in create

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@echo Create: $(@:obj/%=%)
			@gcc $(FLAGS) -c $< -o $@

clean:
		@rm -rf obj
		@make -C lib/ clean

fclean: clean
		@rm -rf ./lem_in
		@make -C lib/ fclean

re: fclean all

.PHONY: all clean flcean re