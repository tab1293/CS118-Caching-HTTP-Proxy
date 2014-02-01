/**
 * @file Header for HttpResponse class
 *
 * UCLA CS118 Winter'14 class
 */

#ifndef _CONNECTION_HANDLER_H_
#define _CONNECTION_HANDLER_H_

#include <netinet/in.h>
#include "http-request.h"
#include "http-response.h"

using namespace std;

/**
 * Class to process new HTTP Requests
 *
 */
class ConnectionHandler {
public:

	/**
	 * Constructor for new ConnectionHandler
	 *
	 * @param int file descriptor for new client connection
	 */
	ConnectionHandler(int connectionFD);

	/**
	 * Reads from connection and processes requests received
	 *
	 */
	void
	processRequests();

	/**
	 * Determines if resource a request wants is in cache or 
	 * if request to host must be made.
	 */
	void
	serveRequest(HttpRequest req);

	/**
	 * Gets the connectionFD for this handler
	 */
	int
	getConnectionFD();

	/**
	 * Sets connectionFD for this handler
	 */
	void
	setConnectionFD(int connFD);

private:
	int connectionFD;			// Stores the file descriptor for the 

};

#endif //_CONNECTION_HANDLER_H