
#include "include.hpp"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int creation_socket(Server &server, const char *port)
{
	int socket_fd;
	int opt = 1;
	struct sockaddr_in address;



	/**************************************************************/
	/***create a socket to receive connection *********************/
	/***AFINET == IPV4, SOCKSTREAM == TCP, 0 == internet protocl***/
	/**************************************************************/
	socket_fd = socket(AF_INET, SOCK_STREAM, 0); 
	if (socket_fd < 0) {
		perror("creation socket");
		return false;
	}

	/**************************************************************/
	/***setsockopt == rajouter des options au socket***************/
	/**ici 1 ==    ,2 = autoris socket lié a adresse déjà utilisée*/
	/**************************************************************/
	if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		return false;
	}


	/**************************************************************/
	/******on force le serv a etre au port demander ***************/
	/**************************************************************/
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(atoi(port));
	if (bind(socket_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		close(socket_fd);
		return false;
	}
	/**************************************************************/
	/****le server devient passif, il attend des connexion*********/
	/****3 == nombre de gens max en list d'attente != nombre gens max sur le serv si je me trome pas , a verfi */
	/**************************************************************/
	if (listen(socket_fd, 3) < 0)
	{
		perror("listen");
		close(socket_fd);
		return false;
	}

	/**************************************************************/
	/****on init la struct, on met event a POLLIN ce qui fait que**/
	/****qu prochain poll il vas faire cette event, donne en atten*/
	/**************************************************************/
	struct pollfd	fd;
	memset(&fd, 0 , sizeof(fd));
	fd.fd = socket_fd;
	fd.events = POLLIN;
	server.add_fd(fd);

	/**************************************************************/
	/****c'est ca qui fait la connexion entre serv et client ******/
	/**************************************************************/
//	if ((new_socket = accept(socket_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
//		perror("accept");
//		close(socket_fd);
//		return false;
//	}
	return true;
}
