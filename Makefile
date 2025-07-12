NAME = cub3d
LIBFT = includes/libft/libft.a
PARSE = parsing/
UTILS = utils/
DDA = DDA_algorithm/
INIT = init/
RC = ray_casting/
CTRLS = controls/
SRCS = $(addprefix srcs/,	main.c \
							$(PARSE)parsing.c \
							$(PARSE)check_file.c \
							$(PARSE)check_file_utils.c \
							$(PARSE)init_struct.c \
							$(PARSE)check_elem.c \
							$(PARSE)check_elem_path.c \
							$(PARSE)check_map.c \
							$(PARSE)utils.c \
							$(PARSE)fill_struct.c \
							$(PARSE)fill_struct2.c \
							$(PARSE)for_testing.c \
							$(PARSE)check_doors.c \
							$(UTILS)free.c \
							$(UTILS)utils.c \
							$(DDA)dda.c \
							$(DDA)utils.c \
							$(DDA)handle_doors.c \
							$(CTRLS)doors.c \
							$(CTRLS)movement.c \
							$(CTRLS)rotation.c \
							$(INIT)window_init.c \
							$(INIT)player_init.c \
							$(INIT)controls_init.c \
							$(INIT)map_init.c \
							$(RC)ray_casting.c \
							$(RC)pre_casting.c \
							$(RC)texture.c \
							$(RC)free_tex.c \
							$(RC)anim.c \
							)
OBJS	=	${SRCS:%.c=${OBJDIR}/%.o}
CFLAGS = -Wextra -Wall -g -Iincludes
CC = gcc
OBJDIR = objets

# Colors and style
END		:= \033[0m
REPLACE := \033[1A\033[K\033[A
WHITE	:= \033[1;37m
PINK	:= \033[1;35m
GREEN	:= \033[32m
BOLD	:= \033[1m
L_PURPLE:= \033[38;5;55m
YELLOW	:= \033[33m
BLUE	:= \033[34m
RED		:= \033[0;31m
MAGENTA := \033[0;35m
CYAN 	:= \033[0;36m

# Counter or compiled
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE = 0

all:	${NAME} display_ascii

${NAME}:	${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} includes/minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -o ${NAME}
	@echo "${BOLD}${GREEN}📦 Link complete: ${NAME}${END}"

${LIBFT}:
	@echo "${BOLD}${BLUE}🔨 Building LIBFT...${END}"
	@${MAKE} -C ./includes/libft/ bonus
	@echo "${BOLD}${GREEN}✓ LIBFT ready${END}"

${OBJDIR}/%.o: %.c | ${OBJDIR}
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@mkdir -p $(dir $@)
	@printf "${BOLD}${L_PURPLE}⚡ [%2d/%2d] Compiling: %-20s ${END}" $(CURRENT_FILE) $(TOTAL_FILES) "$<"
	@${CC} ${CFLAGS} -I./includes/minilibx_linux -c -o $@ $<
	@echo "${BOLD}${GREEN}✓${END}"

${OBJDIR}:
	@echo "${BOLD}${BLUE}📁 Created objects directory${END}"

leaks: ${NAME}
	valgrind --leak-check=full --log-file="leakslog.txt" --track-fds=yes ./${NAME} ./assets/maps/test.cub

clean:
	@echo "${BOLD}${YELLOW}🧹 Cleaning objects...${END}"
	@rm -rf ${OBJDIR}
	@echo "${BOLD}${GREEN}✓ Clean complete${END}"

fclean: clean
	@echo "${BOLD}${YELLOW}🗑️  Deep cleaning...${END}"
	@rm -f ${NAME}
	@rm -f test
	@echo "${BOLD}${GREEN}✨ All clean ✨${END}"

re: fclean all

caca:
	@for color in 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40; do \
		clear; \
		tput setaf $$color; \
		echo $$color; \
		if [ $$(( $$color % 2)) -eq 0 ]; then \
			cat poop.txt; \
		else \
			cat poop2.txt; \
		fi; \
		tput sgr0; \
		sleep 0.3; \
	done

.PHONY: all clean fclean re display_ascii

display_ascii:
	@echo "$(BOLD)$(GREEN)"
	@if [ -f ascii_art.txt ]; then \
		cat ascii_art.txt; \
	fi
	@echo "$(END)"
	@echo "${BOLD}${L_PURPLE} ✨cub3d✨ ${GREEN}is ready 🎉 ${END}"
	@echo "${BOLD}${BLUE}➜ Use ./${NAME} to run the program${END}"

party:
	@echo "$(BOLD)Let's party!"
	@echo "$(RED)$(BOLD)  (^-^) $(END)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(CYAN)$(BOLD) \\(^-^\\) $(END)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(YELLOW)$(BOLD)  (^-^)  $(END)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(BLUE)$(BOLD) (/^-^)/ $(END)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(MAGENTA)$(BOLD)  (^-^)  $(END)"
	@sleep 0.5
	@echo "$(REPLACE)"
	@echo "$(GREEN)$(BOLD) \\(^-^)/ $(END)"
	@sleep 0.5
	@echo "$(REPLACE)\033[A"
	@echo "$(BOLD)Party time is over! Back to work! \n  (^-^)7$(END)"
