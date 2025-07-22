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

#### Which protocol does the http server use at the transport layer?

- Generally for http server its TCP

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

#### What is a file descriptor?

- File descriptors are non negative integers(usually small) that are used to refer to all types of open files including pipes,FIFOs,sockets,terminals,devices,and regular files[2]

#### What is the relationship between file descriptors and open files?

- The relationship between file descriptor and open file is not one to one. It is possible to have multiple file descriptors refering to the same open file.[2]
- This is possible because the kernel maintains file descriptor table(per process), open file table(system wide), and I-node table(system wide) [2]
- Each entry in the file descriptor table holds file descriptor flags and a pointer to the open file table[2]
- Each entry in the open file table contains file offset,status flags, and pointer to I-node table [2]
- Each entry in the I-node table contains file type, file locks and pointer to data block on disk[2]

<img width="705" height="508" alt="Screen Shot 2025-07-21 at 7 39 15 PM" src="https://github.com/user-attachments/assets/2130b6d7-8d9d-491a-8740-0c7cb4e87b03" />

<h2>Explain the functions used in Server.c code </h2>

#### [socket(AF_INET, SOCK_STREAM, 0)](https://man7.org/linux/man-pages/man2/socket.2.html)

- The socket functions creates an endpoint for communication and returns a file descriptor that refers to that endpoint.
- On success a non negative integer is returned
- On error -1 is returned
- The first argument refers to the domain.The domain argument specifies a communication domain; this selects the protocol family which will be used for communication. AF_INET refers to IPv4 Internet protocols.
- The second argument is the type.  The socket has the indicated type, which specifies the communication semantics. SOCK_STREAM provides sequenced, reliable, two-way, connection-basedbyte streams.  An out-of-band data transmission mechanism may be supported.
- The third argument is the protocol to be used with the socket. 0 gives the default protocol

#### [bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))](https://man7.org/linux/man-pages/man2/bind.2.html)

- The bind function assigns the address specified by server_addr to the socket referred to by the file descriptor server_fd.
- On success 0 is returned.
- On error -1 is returned.
- The first argument specifies the file descriptor of the server socket
- The second argument refers to a pointer of type sockaddr struct that holds the ip address and port of server in the sa_data member.
  <img width="404" height="113" alt="Screen Shot 2025-07-21 at 8 31 13 PM" src="https://github.com/user-attachments/assets/3b54556b-6098-45b2-8b57-bce8cbdccdc0" />
- The second argument is passed an argument of type pointer to sockaddr_in and casted to pointer of type sockaddr. This is the case because sockaddr_in makes it easier to assign a port(sin_port) and ip address (sin_addr) as they are two members instead of one.
  <img width="463" height="173" alt="Screen Shot 2025-07-21 at 8 34 28 PM" src="https://github.com/user-attachments/assets/f0e7cb80-e31e-4456-8754-d816ecfc00ef" />
- The third argument passes size of sockaddr struct.

#### [listen(server_fd, SERVER_PENDING_CONNECTION)](https://man7.org/linux/man-pages/man2/listen.2.html)

- The listen function  marks the socket referred to by sockfd as a passive socket, that is, as a socket that will be used to accept incoming connection requests using accept(2).
- On success 0 is returned.
- On error -1 is returned.
- The first argument refers to the server file descriptor
- The second argument is the backlog that defines the maximum length to which the queue of pending connections for server_fd may grow.

#### [accept(server_fd, (struct sockaddr *)&client_addr, &addrlen))](https://man7.org/linux/man-pages/man2/accept.2.html)

- The accept function extracts the first connection request on the queue of pending connections for the listening socket, server_fd, creates a new connected socket, and returns a new file descriptor referring to that socket
- On success a non negative integer is returned
- On error -1 is returned
- The first argument is file descriptor for server
- The second argument is a pointer of type strut sockaddr refering to client
- The third argument is a pointer to the size of a the client sockaddr

#### [read(new_socket, buffer, SERVER_BUFFER)](https://man7.org/linux/man-pages/man2/read.2.html)

- The read function attempts to read from a client file descriptor.
- On success the number of bytes read is returned
- On error -1 is returned
- The first argument refers to a client file descriptor
- The second argument refers to the buffer that stores in bytes what being read
- The third argument is the maximum number of bytes to be read from file descriptor

#### [write(new_socket, hello, strlen(hello))](https://man7.org/linux/man-pages/man2/write.2.html)

- The write function writes to a client file descriptor.
- On success, the number of bytes written is returned.
- On error -1 is returned
- The first argument refers to a client file descriptor
- The second argument is a pointer to the buffer that holds the data you want to write.
- The third argument is the maximum number of bytes to write from the buffer.

<h2>Explain the functions used in Client.c code (only unique as repeated are explained above) </h2>

#### [connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))](https://man7.org/linux/man-pages/man2/connect.2.html)

- The connect function initiates a connection on a socket.
- On success 0 is returned.
- On error -1 is returned.
- The first argument refers to the client file descriptor.
- The second argument is a pointer of type strut sockaddr refering to server
- The third argument is the size of sockaddr refering to server

####  [send(client_fd, hello, strlen(hello), 0)](https://man7.org/linux/man-pages/man2/send.2.html)

- The send function sends a message on a socket.
- Basically the send function is equivalent to write but used only for sockets that are in a connected state.
- On success the number of bytes sent is returned.
- On error -1 is returned.
- The first argument refers to client file descriptor.
- The second argument is a pointer to the buffer that holds the data you want to send
- The third argument is the maximum number of bytes to send from the buffer.
- The fourth argument is a flags argument when set to 0 makes send equivalent to write


<h2>References</h2>

[1] W. R. Stevens, B. Fenner, and A. M. Rudoff, *UNIX® Network Programming, Volume 1: The Sockets Networking API*, 3rd ed. Boston, MA: Addison‑Wesley Professional, 2003.

[2] M. Kerrisk, *The Linux Programming Interface: A Linux and UNIX System Programming Handbook*, 1st ed. San Francisco, CA, USA: No Starch Press, 2010.

[3] J. F. Kurose and K. W. Ross, *Computer Networking: A Top-Down Approach*, 6th ed. Boston, MA, USA: Pearson, 2013.
