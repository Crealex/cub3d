NAME = cub3d
SRCS = $(shell find srcs -name "*.c")
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
	@${CC} ${CFLAGS} ${OBJS} includes/minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -o ${NAME}
	@echo "${BOLD}${GREEN}📦 Link complete: ${NAME}${END}"

${OBJDIR}/%.o: %.c | ${OBJDIR}
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@printf "${BOLD}${L_PURPLE}⚡ [%2d/%2d] Compiling: %-20s ${END}" $(CURRENT_FILE) $(TOTAL_FILES) "$<"
	@${CC} ${CFLAGS} -I./includes/minilibx_linux -c -o $@ $<
	@echo "${BOLD}${GREEN}✓${END}"

${OBJDIR}:
	@echo "${BOLD}${BLUE}📁 Created objects directory${END}"

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

.PHONY: all clean fclean re display_ascii

display_ascii:
	@echo "$(BOLD)$(GREEN)"
	@if [ -f ascii_art.txt ]; then \
		cat ascii_art.txt; \
	fi
	@echo "$(END)"
	@echo "${BOLD}${L_PURPLE} ✨CPP-Module04-ex01✨ ${GREEN}is ready 🎉 ${END}"
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
