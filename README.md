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

<h2> Some simple Q/A related to http servers </h2>

#### What is a protocol?

- An agreement on how programs will communicate accross a computer network [1]

#### Which protocol stack does an http server and client use to communicate

- The Transmission Control Protocol (TCP) and the Internet Protocol (IP). They are collectively known as TCP/IP[3]

#### How is the TCP/IP stack organized?

- Its organized in a layered architecture which include the following layers: application,transport,network,link, and physical[3]

<img width="293" height="346" alt="Screen Shot 2025-07-21 at 4 30 25 PM" src="https://github.com/user-attachments/assets/8091d1dd-593e-422e-8d32-e2215d5151c4" />

#### What is the application layer?

- The application layer hosts network programs and defines the protocols they use to exchange messages across the network[3]

#### What is the transport layer?

- The transport layer is responsible for transporting application layer messages between programs[3]
- Transport layer uses either TCP  or User Datagram protocol(UDP) [3]
- TCP is connection oriented,is reliable, has flow control, has congestion control, and segmentation [3]
- UDP is connectionless, is unreliable, has no flow control, has no congestion control, and is lightweight [3]

#### What is the network layer?

- The network layer is responsible for moving network-layer packets known as datagrams from one program to the another.[3]
- The packets are application messages broken into smaller chunks[3]

#### What is the link layer?

- The link layer is responsible for receiving the datagram from network layer and it delivering to the next node[3]
- A node can refer to another host(computer), router,switch,and access point[3]
- The link layer packets are also called frames[3]

#### What is the physical layer?

- The physical layer is responsible to move the individual bits within the frame from one node to the next[3]

#### What is an http server?

- A long running program (daemon) that generally communicates over the network only when a request is received. [1]

#### What is a client?

- A typically short-lived program that always initiates communication with the HTTP server. [1]

#### Why does client always initiate communication?

- It simplifies the protocol suite and the programs that use them.

#### What is a socket?

- Sockets are an interprocess communication (IPC) mechanism that enable programs to exchange data, whether they are running on the same machine or on separate machines connected via a network [2]

#### How are sockets identified?

- They are identified by and ip address and a port

#### What type of ip addresses are used in http server?

- They can use internet protocol version 4 (ipv4) or version 6 (ipv6) addresses [2]
- ipv4 is 32 bits in size [2]
- ipv6 is 128 bits in size [2]
- port size is 16 bit whether ipv4 or ipv6 is used [2]

#### What are the steps involved in setting up an http server?

- (1) Create the socket
- (2) Bind the socket to an ip address and port
- (3) listen for client connections
- (4) accept a client connection
- (5) loop through (3) and (4) until some server error or server closes

#### What are the steps involved in setting up a client socket to connect to http server?

- (1) Create socket
- (2) Connects to server
- (3) Closes

#### Can show a diagram describing the set up process of http server and client? [2]

<img width="614" height="491" alt="Screen Shot 2025-07-21 at 3 07 58 PM" src="https://github.com/user-attachments/assets/f6b186d8-cfd6-40ee-89be-4d81a2b98cb3" />


<h2>References</h2>

[1] W. R. Stevens, B. Fenner, and A. M. Rudoff, *UNIX® Network Programming, Volume 1: The Sockets Networking API*, 3rd ed. Boston, MA: Addison‑Wesley Professional, 2003.

[2] M. Kerrisk, *The Linux Programming Interface: A Linux and UNIX System Programming Handbook*, 1st ed. San Francisco, CA, USA: No Starch Press, 2010.

[3] J. F. Kurose and K. W. Ross, *Computer Networking: A Top-Down Approach*, 6th ed. Boston, MA, USA: Pearson, 2013.



  

