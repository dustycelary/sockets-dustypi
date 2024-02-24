#include <stdio.h> 
#include <iostream> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

int main()
{
    int sockfd, tempsockfd, portno; 
    socklen_t addr_size; 
    struct sockaddr_in serv_addr, cli_addr; 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 

    if (sockfd < 0)
    {
        perror("The currnet error : ");
        return 0;
    }

    serv_addr.sin_family = SOCK_STREAM; 
    serv_addr.sin_addr.s_addr = inet_addr("100.78.224.37"); 
    serv_addr.sin_port = htons(7272); 

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Current Errr : "); 
        return 0;
    }

    listen(sockfd, 5); 

    addr_size = sizeof(cli_addr);
    while (1)
    {
        tempsockfd = accept(sockfd, (sockaddr *)&cli_addr, &addr_size);
        if (tempsockfd < 0)
        {
            std::cout << "Error accepting connection" << std::endl;
            return 0;
        }

        std::cout << "Connection success" << std::endl;
        
        close(); 

    }
    

    return 0;
}

