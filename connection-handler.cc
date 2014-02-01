/**
 * @file Header for HttpResponse class
 *
 * UCLA CS118 Winter'14 class
 */

#include "connection-handler.h"

using namespace std;

ConnectionHandler::ConnectionHandler(int connectionFD) {
	setConnectionFD(connectionFD);
}

void ConnectionHandler::processRequests() {

	// Create a buffer

	// Read from the connection

		// Once we've read a full request, parse it using the request lib

		// Serve the request

	// We've received a 0 from reading and the requests have all been handled

}

void ConnectionHandler::serveRequest(HttpRequest req) {

	// Check cache

	// Handle both cases

}



int ConnectionHandler::getConnectionFD() {
	return this.connectionFD;
}

void ConnectionHandler::setConnectionFD(int connectionFD) {
	this.connectionFD = connectionFD;
}