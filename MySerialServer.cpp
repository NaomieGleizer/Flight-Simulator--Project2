#include "MySerialServer.h"

MySerialServer::MySerialServer() {
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
}

void waitForClientThread(int & sockfd, ClientHandler* c) {
    int clilen, newsockfd;
    char input[256];
    char output[256];

    struct sockaddr_in cli_addr;
    int n;

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */
    while (listen(sockfd, 5) == 0) {
        clilen = sizeof(cli_addr);

        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        /* If connection is established then start communicating */
        bzero(input,256);
        n = read( newsockfd,input,255 );

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        //printf("Here is the message: %s\n",buffer);

        c->handleClient(input, output);
        n = write(newsockfd,output,255);
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}

void MySerialServer::open(int port, ClientHandler* c) {
    int portno;
    struct sockaddr_in serv_addr;

    if (this->sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    thread t(waitForClientThread, ref(this->sockfd), c);


}

void MySerialServer::stop() {
    close(this->sockfd);
}