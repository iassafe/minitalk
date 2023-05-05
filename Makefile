# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 09:55:21 by iassafe           #+#    #+#              #
#    Updated: 2023/03/13 11:22:37 by iassafe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCCLIENT = ft_client.c ft_minitalk_utils.c
SRCSERVER = ft_server.c ft_minitalk_utils.c
INCLUDES = minitalk.h

OBJECTS = $(SRCCLIENT:.c=.o)
OBJECTS1 = $(SRCSERVER:.c=.o)

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
SRCCLIENT_BONUS = ft_client_bonus.c ft_minitalk_utils_bonus.c
SRCSERVER_BONUS = ft_server_bonus.c ft_minitalk_utils_bonus.c
INCLUDES_BONUS = minitalk_bonus.h

OBJECTS_bonus_client = $(SRCCLIENT_BONUS:.c=.o)
OBJECTS_bonus_server = $(SRCSERVER_BONUS:.c=.o)

all : $(CLIENT) $(SERVER)

bonus : $(CLIENT_BONUS) $(SERVER_BONUS)

client : $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(CLIENT)

server : $(OBJECTS1) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS1) -o $(SERVER)
	
client_bonus : $(OBJECTS_bonus_client) $(INCLUDES_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_bonus_client) -o $(CLIENT_BONUS)

server_bonus : $(OBJECTS_bonus_server) $(INCLUDES_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_bonus_server) -o $(SERVER_BONUS)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJECTS) $(OBJECTS1) $(OBJECTS_bonus_client) $(OBJECTS_bonus_server)

fclean : clean
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re : fclean all