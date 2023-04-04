# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:26:28 by cscelfo           #+#    #+#              #
#    Updated: 2023/03/15 10:26:50 by cscelfo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = projects

LIB = first_layer.a

DIR = first_layer

LIB_DIR = lib

RM = rm -f

RMDIR = rm -rf

all: $(NAME)

$(NAME): dir check_mandatory
	$(MAKE) -C $(DIR)
	mv -u $(DIR)/$(LIB) $(LIB_DIR)
	clear

dir:
	if [ -d "$(DIR)" ]; then \
		echo "PERFECT! $(DIR) exists!"; \
	else \
		echo "ERROR! $(DIR) doesn't exist"; \
	fi
	mkdir -p $(LIB_DIR)

check_mandatory:
	if [ "$(LIB)" ]; then \
		echo "$(LIB) was created correctly!"; \
	else \
		echo "Something went wrong in creating $(LIB)!"; \
	fi 

clean: check_clean
	$(MAKE) -C $(DIR) clean
	clear

check_clean:
	if ls $(DIR)/*.o > /dev/null 2>&1;  then \
		echo "Everything was cleaned correctly!"; \
	else \
		echo "Something went wrong in clean!"; \
	fi 

fclean: check_fclean
	$(MAKE) -C $(DIR) fclean
	$(RMDIR) $(LIB_DIR)
	clear

check_fclean: 
	if ls $(LIB_DIR)/$(LIB) > /dev/null 2>&1;  then \
		echo "$(LIB) and $(LIB_DIR) were removed correctly!"; \
	else \
		echo "Something went wrong in fclean!"; \
	fi 

re: fclean all
	$($(MAKE)) -C $(DIR) re
	clear

.PHONY: all clean fclean re
.SILENT:
