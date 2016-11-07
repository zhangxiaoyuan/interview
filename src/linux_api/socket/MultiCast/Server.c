
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
	char buf[128] = {0};
	struct sockaddr_in mulcast_addr;

	//socket
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(0 > sock)
	{
		perror("socket err:");
		return -1;
	}

	//reuseraddr：地址重用（设置后主机多个服务器可以同时运行）
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
	memset(&mulcast_addr, 0, sizeof(struct sockaddr_in));
	mulcast_addr.sin_family = AF_INET;
	mulcast_addr.sin_port = htons(MULCAST_PORT);
	mulcast_addr.sin_addr.s_addr = inet_addr(MULCAST_IP);

	//向多播地址发送数据
	while(1)
	{
		len = sizeof(struct sockaddr);
		//init buf
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		
		//sendto
		cnt = sendto(sock, buf, sizeof(buf), 0, (struct sockaddr *)&mulcast_addr, len);
		if(0 > cnt)
		{
			perror("send to err:");
			goto _out;
		}
		
		//服务器退出
		if( !strncmp(buf, "quit", 4) )
		{
			printf("server quit!\n");
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
