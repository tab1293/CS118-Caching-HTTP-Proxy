/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include <iostream>
#include <netinet/in.h>

// Constant Variables
#define MAX_CONNECTIONS = 20;
#define SERVER_PORT = 14886;

using namespace std;

int main (int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in serverAddr;

	// Create a socket
	if(sockfd = socket(AF_INET, SOCK_STREAM, 0) < 0) {
		error("Error opening socket!");
	}

	// Build server socket address
	memset(&serverAddr, '0', sizeof(sockaddr_in));

	serverAddr.sin_famiy = AF_INET;
	serverAddr.sin_port = htons(SERVER_PORT);
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	// Bind socket
	if(bind(sockfd, (struct sockaddr_in*) serverAddr, sizeof(serverAddr)) < 0) {
		perror("Error binding to socket!");
	}

	// Listen 
	if(listen(sockfd, MAX_CONNECTIONS) < 0) {
		perror("Error listening on socket!");
	}

	int connfd;
	struct sockaddr_storage clientAddr;
	socklen_t clientAddrSize = sizeo(clientAddr);

	// Poll for connections 
	while(connfd = accept(sockfd, (struct sock_addr*) &clientAddr, &clientAddrSize) >= 0) {

		// Fork a new process to handle this connection
		pid_t pid = fork();
		if(pid == 0) {
			// Child process
			ConnectionHandler* connHandler = new ConnectionHandler(connfd); 
			connHandler->processRequests();

			// TODO: At this point we close the connection and exit() the process

		} else if(pid < 0) {
			perror("There was an error forking!");
		}
	}

	return 0;
}
