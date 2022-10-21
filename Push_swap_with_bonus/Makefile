# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 11:36:24 by cpollito          #+#    #+#              #
#    Updated: 2022/03/28 15:21:14 by cpollito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 	:= push_swap

NAME_BONUS 		:= checker

INCLUDES_DIR 	:= includes
SOURCES_DIR 	:= sources
COMMANDS_DIR 	:= commands
UTILS_DIR 		:= utils
OBJECTS_DIR 	:= objects

HEADER			:= push_swap.h
HEADER			:= $(addprefix $(INCLUDES_DIR)/, $(HEADER))
HEADER_BONUS	:= get_next_line.h
HEADER_BONUS	:= $(addprefix $(INCLUDES_DIR)/, $(HEADER_BONUS))
HEADER_BONUS	:= $(HEADER) $(HEADER_BONUS)

SRCS_CMDS			:= ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss_pa_pb.c
SRCS_CMDS 			:= $(addprefix $(COMMANDS_DIR)/, $(SRCS_CMDS))
SRCS_UTILS 			:= ft_atoi_long.c ft_split.c get_index.c lists.c utils.c
SRCS_UTILS			:= $(addprefix $(UTILS_DIR)/, $(SRCS_UTILS))
SRCS				:= push_swap.c parser.c general_sort.c minisort.c $(SRCS_CMDS) $(SRCS_UTILS)
SRCS_CMDS_BONUS		:= ra_rb_rr_bonus.c rra_rrb_rrr_bonus.c sa_sb_ss_pa_pb_bonus.c
SRCS_CMDS_BONUS		:= $(addprefix $(COMMANDS_DIR)/,  $(SRCS_CMDS_BONUS)) 
SRCS_UTILS_BONUS 	:= ft_strcmp.c get_next_line_utils.c
SRCS_UTILS_BONUS	:= $(addprefix $(UTILS_DIR)/, $(SRCS_UTILS_BONUS)) $(SRCS_UTILS)
SRCS_BONUS			:=  checker.c parser.c get_next_line.c $(SRCS_CMDS_BONUS) $(SRCS_UTILS_BONUS)

OBJ 				:= $(addprefix $(OBJECTS_DIR)/, $(SRCS:.c=.o))
OBJ_BONUS			:= $(addprefix $(OBJECTS_DIR)/, $(SRCS_BONUS:.c=.o))
					
CC 					:= 	cc
CFLAGS 				:= -Wall -Wextra -Werror
RM 					:= rm -rf

.PHONY: 	all clean fclean re bonus

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		
bonus:	 $(NAME_BONUS) 

$(NAME_BONUS):	$(OBJ_BONUS) $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(OBJECTS_DIR)/%.o : $(SOURCES_DIR)/%.c $(HEADER) $(HEADER_BONUS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean :
	$(RM) $(OBJECTS_DIR)

fclean: 	clean
			@$(RM) $(NAME)
			@$(RM) $(NAME_BONUS)

re: 		fclean all
