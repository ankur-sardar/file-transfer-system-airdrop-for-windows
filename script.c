//  Made By Sagar Ghai and Ankur Sardar
//  IIT Mandi

#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include <netdb.h>
#define PORT 7213           // port for socket binding
#define BUF_SIZE 256

int client(const char* filename,const char* ip)      // client function that accepts files as messages from host and binds them into a single file
{
    /* Create file where data will be stored */
    FILE *fp = fopen(filename, "ab");
    if(NULL == fp)
    {
        printf("Error opening file");
        return 1;
    }

    /* Create a socket first */
    int sockfd = 0;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    /* Initialize sockaddr_in data structure */
    struct sockaddr_in serv_addr;   //serv_addr.sin_family = 2; serv_addr.sin_port = 34835;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT); // port
    serv_addr.sin_addr.s_addr = inet_addr("10.8.5.221");
//              serv_addr.sin_addr.s_addr = inet_addr("10.8.0.1");

    /* Attempt a connection */
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("\n Error : Connect Failed \n");
        return 1;
    }

    /* Receive data in chunks of BUF_SIZE bytes */
    int bytesReceived = 0;
    char buff[BUF_SIZE];
    memset(buff, '0', sizeof(buff));
    while((bytesReceived = read(sockfd, buff, BUF_SIZE)) > 0)
    {
        // printf("Bytes received %d\n",bytesReceived);
        fwrite(buff, 1,bytesReceived,fp);
    }

    if(bytesReceived < 0)
    {
        printf("\n Read Error \n");
    }

    return 0;
}

int server(const char * filename)
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);

    // printf("Socket retrieve success\n");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

    if(listen(listenfd, 10) == -1)
    {
        printf("Failed to listen\n");
        return -1;
    }
									//printf("%d \n %d \n %d \n %d \n" , AF_INET,htonl(INADDR_ANY), htons(PORT),SOCK_STREAM);

    for (;;)
    {
        int connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL);

        /* Open the file that we wish to transfer */
        FILE *fp = fopen(filename,"rb");
        if(fp==NULL)
        {
            printf("File opern error");
            return 1;
        }

        /* Read data from file and send it */
        for (;;)
        {
            /* First read file in chunks of BUF_SIZE bytes */
            unsigned char buff[BUF_SIZE]={0};
            int nread = fread(buff,1,BUF_SIZE,fp);
            // printf("Bytes read %d \n", nread);

            /* If read was success, send data. */
            if(nread > 0)
            {
                // printf("Sending \n");
                write(connfd, buff, nread);
            }

            /*
             * There is something tricky going on with read ..
             * Either there was error, or we reached end of file.
             */
             if (nread < BUF_SIZE)
             {
                // if (feof(fp))
                //     printf("End of file\n");
                if (ferror(fp))
                    printf("Error reading\n");
                break;
            }
        }
        close(connfd);
        sleep(1);
    }
    return 0;
}

int main(int argc, char** argv)
{
    if (argc == 4)
    {
        const char* mode = argv[1];
        const char* filename = argv[2];
        const char* ip = argv[3];
        
        if (strcmp(mode, "1") == 0)
            return server(filename);
        else if(strcmp(mode, "2") == 0)
            return client(filename,ip);
        else
            printf("Invalid mode %s - should be 'client' or 'server'\n",mode);
    }
    else
    {
        printf("%d%s%s",argc,argv[0],argv[1]);
        printf("Invalid number of argument, usage is %s [MODE] [FILENAME]\n",argv[0]);
    }
    printf("Here's the end");
    return 0; // Something went wrong
}
