NAME = cub3d
LIBFT = includes/libft/libft.a
PARSE = parsing/
UTILS = utils/
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
							$(UTILS)free.c \
							)
OBJS	=	${SRCS:%.c=${OBJDIR}/%.o}
CFLAGS = -Werror -Wextra -Wall -g -Iincludes
CC = gcc
OBJDIR = objets

# Colors and style
END		:= \033[0m
WHITE	:= \033[1;37m
NC		:= \033[0m
PINK	:= \033[1;35m
GREEN	:= \033[32m
BOLD	:= \033[1m
L_PURPLE:= \033[38;5;55m
YELLOW	:= \033[33m
BLUE	:= \033[34m

# Counter or compiled
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE = 0

all:	${NAME} display_ascii

${NAME}:	${OBJS}  ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}
	@echo "${BOLD}${GREEN}📦 Link complete: ${NAME}${END}"

${LIBFT}:
	@echo "${BOLD}${BLUE}🔨 Building LIBFT...${END}"
	@${MAKE} -C ./includes/libft/ bonus
	@echo "${BOLD}${GREEN}✓ LIBFT ready${END}"

${OBJDIR}/%.o: %.c | ${OBJDIR}
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@mkdir -p $(dir $@)
	@printf "${BOLD}${L_PURPLE}⚡ [%2d/%2d] Compiling: %-20s ${END}" $(CURRENT_FILE) $(TOTAL_FILES) "$<"
	@${CC} ${CFLAGS} -c -o $@ $<
	@echo "${BOLD}${GREEN}✓${END}"

${OBJDIR}:
	@echo "${BOLD}${BLUE}📁 Created objects directory${END}"

leaks: ${NAME}
	valgrind --leak-check=full --log-file="leakslog.txt" --track-fds=yes ./${NAME} ./assets/maps/novalid.cub

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
	@for color in 31 32 33 34 35 36 37 38 39 40; do \
		clear; \
		tput setaf $$color; \
		cat poop.txt; \
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
