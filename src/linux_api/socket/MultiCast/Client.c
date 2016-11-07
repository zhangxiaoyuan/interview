
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define MULCAST_PORT  6000				//端口号
#define MULCAST_IP  "224.0.0.1"			//局部连接多播地址，路由器不转发

/***** 主函数 *************************************************************************************************/
int main(void)
{
	int sock = -1;
	int cnt = -1;
	int len = -1;
	int loop = 1;
	char buf[128] = {0};
	struct sockaddr_in local_addr;
	struct ip_mreq mreq;

	//socket
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(0 > sock)
	{
		perror("socket err:");
		return -1;
	}
	
	//reuseraddr：地址重用（设置后多个客户端可以同时运行）
	{
		int val = 1;
		cnt = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&val, sizeof(val));
		if(0 > cnt)
		{
			perror("set reuser addr err:");
			goto _out;
		}
	}	
	
	//init
	memset(&local_addr, 0, sizeof(struct sockaddr_in));	
	local_addr.sin_family = AF_INET;
	local_addr.sin_addr.s_addr = htonl(INADDR_ANY);	
	local_addr.sin_port = htons(MULCAST_PORT);

	//bind
	cnt = bind(sock, (struct sockaddr *)&local_addr, sizeof(struct sockaddr));
	if(0 > cnt)
	{
		perror("bind err:");
		goto _out;
	}

	//设置回环许可
	cnt = setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop));
	if(0 > cnt)
	{
		perror("multicast loop");
		goto _out;
	}
	
	mreq.imr_multiaddr.s_addr = inet_addr(MULCAST_IP);	//广播地址
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);		//网络接口为默认
	//将本机加入多播组
	cnt = setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
	if(0 > cnt)
	{
		perror("ip add membership");
		goto _out;
	}
		
	while(1)
	{
		len = sizeof(struct sockaddr_in);
		memset(buf, 0, sizeof(buf));
		cnt = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&local_addr, &len);
		if(0 > cnt)
		{
			perror("recv failed:");
			goto _out;
		}
		printf("buf : %s", buf);
		
		//客户端退出
		if( !strncmp(buf, "quit", 4) )
		{
			printf("client quit!\n");
			break;
		}
	}
		
	//close
	close(sock);
	return 0;
_out:
	close(sock);
	return -1;
}
