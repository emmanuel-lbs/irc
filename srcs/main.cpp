#include "include.hpp"

int main(int ac, char **av)
{
	Server server;
	socklen_t clientAddressLength;


	if (ac < 2 || ac > 3)
	{
		perror("number of argument");
		return (0);
	}

	if (creation_socket(server, av[1]) == false)
		return -1;
	int new_socket;
	while (1)
	{

		/*********************************************************************/
		/*****poll attend un evenement dans un fd, ici le servera*************/
		/************* poll vas remplir fds.revents **************************/
		/*********************************************************************/
//		if ((poll(&server.get_fds()[0], server.get_fds().size() , 10000)) <= 0)
//		{
//			perror("poll");
//			break;
//		}
		/*je sais aps quoi faire ensuite */
//		if ((new_socket = accept(&server.get_fds()[0].fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
//			perror("accept");
//			return false;
//		}
//		std::string test;
//		read (new_socket, &test, 10000);
//		send (new_socket, "Hello from server", 18, 0);

	}
	return 0;
}
