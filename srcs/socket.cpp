
#include "include.hpp"

int creation_socket( void )
{
	int opt = 1;
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);  //AFINET == IPV4, SOCKSTREAM == TCP, 0 == internet protocl
	 if (socketfd < 0) {
		 cerr << "error creation socket";
		 exit(1);
	 }
	 if (setsockopt(socketfd, , SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	 {
		 perror("setsockopt");
		 exit(EXIT_FAILURE);
	 }
}
