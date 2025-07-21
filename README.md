<h1> http_server_v1 </h1> 

<h2>Acknowledgments </h2> 

To build a simple http server in the C programming language, I followed the tutorial [HTTP Server: Everything you need to know to Build a simple HTTP server from scratch](https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa) by Skrew Everything.

<h2>Purpose </h2>
To better appreciate the work the browser does in the background when loading a web page.

<h2> Overview </h2> 

This is a very simple http server. The client.c file sets up a client socket that connects to the server socket at the specific port.The server.c file sets up a server socket at a specific port and listens for connections. Once a connection is made, the client sends a hello message, the server responds with a hello world message in a form of a basic html file called hello.html. This http server is considered basic because it handles clients sequentially (not concurrently), no file permission checks, the data exchanged is not encrypted, etc...

<h2> Demo </h2>

- clone respository
- compile server.c : gcc server.c -o server
- compile client.c : gcc client.c -o client
- run server: ./server
- run client: ./client (in separate terminal)

#### The result for server in terminal:
<img width="256" height="85" alt="Screen Shot 2025-07-20 at 9 47 23 PM" src="https://github.com/user-attachments/assets/9942c94d-b496-4674-958b-160acb271a87" /> 

#### The result for client in terminal:

<img width="293" height="244" alt="Screen Shot 2025-07-20 at 9 48 03 PM" src="https://github.com/user-attachments/assets/2ec85ed1-d513-4f96-893d-5e996b8484ff" />

#### The web browser can be used as a client by pasting the following url (http://localhost:8080/hello.html). The result will display the h1 tag containing hello world:

<img width="451" height="98" alt="Screen Shot 2025-07-20 at 9 51 30 PM" src="https://github.com/user-attachments/assets/d0a4a605-7229-464c-9a1c-d0da5fe2979e" />

#### The server terminal will display the HTTP GET request headers sent by the browser (partial output shown)::

<img width="569" height="77" alt="Screen Shot 2025-07-20 at 9 59 42 PM" src="https://github.com/user-attachments/assets/bd278e3d-287f-4b43-9b52-2522c9025354" />

<h2> Background </h2>



