#include "include.hpp"

int main(int ac, char **av)
{

	int socketfd = creation_socket();
	close(socketfd);
	 return 0;
}
