#ifndef IRC
#define IRC

#include <iostream>
#include <string>
#include <vector>

#include <poll.h>
#include <sys/socket.h>
#include <netdb.h>


#include "server.hpp"
#include "chanels.hpp"
#include "clients.hpp"

class Server;
class Chanels;
class Clients;

int creation_socket(Server &server, const char *port);

#endif
