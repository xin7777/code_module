#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>

using namespace std;

int main()
{
    int socket_fd = socket(AF_INET, SOCK_STREAM,0);
    if(socket_fd == -1)
    {
        cout<<"socket 创建失败："<<endl;
        exit(-1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int res = connect(socket_fd,(struct sockaddr*)&addr,sizeof(addr));
    if(res == -1)
    {
        cout<<"bind 链接失败："<<endl;
        exit(-1);
    }
    cout<<"bind 链接成功："<<endl;

    char recvbuf[1024];
    char sendbuf[1024] ;
    while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL){  //read the text in the terminal
    	write(socket_fd,sendbuf,strlen(sendbuf));  //attention strlen not sizeof
    	recv(socket_fd, recvbuf, sizeof(recvbuf), 0);
    	cout << "recvbuf:" <<recvbuf << endl;
    	memset(recvbuf, 0, sizeof(recvbuf));
    	memset(sendbuf, 0, sizeof(sendbuf));

/*	 write(socket_fd,"hello2",sizeof("hello2"));
        recv(socket_fd, recvbuf, sizeof(recvbuf), 0);
        cout << "recvbuf:2" <<recvbuf << endl;
        memset(recvbuf, 0, sizeof(recvbuf));
        memset(sendbuf, 0, sizeof(sendbuf));
 */   }
    close(socket_fd);

    return 0;
}
