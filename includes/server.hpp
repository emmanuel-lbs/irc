#ifndef SERVER_HPP
#define SERVER_HPP

#include "include.hpp"

class Chanels;
class Clients;

class Server {
	public:
		Server();
		Server(Server const &);
		~Server();
		Server & operator=(Server const &);

		void add_fd(struct pollfd fd);
		std::vector<struct pollfd> get_fds();

	private :
		std::vector<struct pollfd>	_fds;
		std::vector<Chanels>		_chanels;
		std::vector<Clients>		_clients;
};

#endif
