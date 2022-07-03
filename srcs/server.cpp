
#include "include.hpp"

Server::Server() {}

Server::Server(Server const & server) {
	*this = server;
}

Server::~Server() {}

Server& Server::operator=(const Server& rhs) {
	_chanels = rhs._chanels;
	_clients = rhs._clients;
	_fds = rhs._fds;
	return *this;
}

void	Server::add_fd(struct pollfd fd) {
	_fds.push_back(fd);
}

std::vector<struct pollfd> Server::get_fds() {
	return _fds;
}
