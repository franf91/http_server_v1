# http_server_v1

### Acknowledgments

To build a simple http server in the C programming language, I followed the tutorial [HTTP Server: Everything you need to know to Build a simple HTTP server from scratch](https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa) by Skrew Everything.

### Purpose
To better appreciate the work the browser does in the background when loading a web page.

### Overview

This is a very simple http server. The client.c file sets up a client socket that connects to the server socket at the specific port.The server.c file sets up a server socket at a specific port and listens for connections. Once a connection is made, the client sends a hello message, the server responds with a hello world message in a form of a basic html file called hello.html. This http server is considered basic because it handles clients sequentially (not concurrently), no file permission checks, the data exchanged is not encrypted, etc...

### Demo



