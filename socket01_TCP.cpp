#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
int main()
{
	//1-1创建绑定到服务器的Socket -->The socket function creates a socket that is bound to a specific 		transport service provider.
	int server = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
	
	//1-2将套接字绑定到服务器上 -->The bind function associates a local address with a socket.
	sockaddr_in serveraddr;//套接字地址类型变量
	serveraddr.sin_family = AF_INET;//地址镞 ipv4
	serveraddr.sin_port = htons(12345);//端口   htons把参数转换成TCP网络字节序
	serveraddr.sin_addr.s_addr = inet_addr("192.168.241.131");
	//将套接字地址和服务器绑定
	bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));

	//1-3监听客户机的连接 -->The listen function places a socket in a state in which it is listening 	for an incoming connection.
	listen(server, 5);//最大客户机5
	std::cout<<"listen..."<<std::endl;
	//1-4处理客户机连接请求 -->The accept function permits an incoming connection attempt on a socket.
	//返回的是客户机的套接字
	sockaddr_in clientaddr;//返回客户机套接字地址
	socklen_t len = sizeof(clientaddr);//返回客户机套接字长度
	int client = accept(server, (sockaddr*)&clientaddr, &len);//阻塞于此


	//接收客户机消息
	char recvdata[1024] = { 0 };
	recv(client, recvdata, 1023,0);
	std::cout<<recvdata<<std::endl;

	return 0;

	//測試Git代碼
	
	//測試GIT代碼託管  測試是否可行

	//測試代碼可行
	
}
