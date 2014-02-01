/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include <iostream>
#include <netinet/in.h>

using namespace std;

int main (int argc, char *argv[])
{
  // command line parsing
	int sockfd;
	struct sock_addrin serv_addr;

	if(sockfd = socket(AF_INET, SOCK_STREAM, 0) < 0) {
		error("Error opening socket!");
	}

	memset(&serv_addr, '0', sizeof(sockaddr_in));

	s.sin_famiy = AF_INET;
	s.sin_port = htons(14886);
	s.sin_addr.s_addr = htonl(INADDR_ANY);


	if(bind(sockfd, (struct sockaddr_in*) serv_addr, sizeof(serv_addr)) < 0) {
		perror("Error binding to socket!");
	}

	if(listen(sockfd, 20) < 0) {
		perror("Error listening on socket!");
	}

	int connfd;
	struct sockaddr_storage client_addr;
	socklen_t client_addr_size = sizeo(client_addr);

	while(connfd = accept(sockfd, (struct sock_addr*) &client_addr, &client_addr_size) >= 0) {
		pid_t pid = fork();
		if(pid == 0) {
			ConnectionHandler* connHandler = new ConnectionHandler(connfd); 
		} else if(pid < 0) {
			perror("There was an error forking!");
		}
	}

	return 0;
}
