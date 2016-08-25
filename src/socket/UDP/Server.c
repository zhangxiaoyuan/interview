#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>

#define IP "192.168.1.222"
#define PORT 6666

int main(void)
{
	int cnt = -1;
	int sfd = -1;
	int len = -1;
	struct sockaddr_in ser_addr;
	struct sockaddr_in from_addr;
	char buf[128] = {0};
	char ser_buf[128] = {0};

	//socket
	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(0 > sfd)
	{
		perror("socket error:");
		goto _out;
	}
	
	//bind
	{
		//init
		ser_addr.sin_family = AF_INET;
		ser_addr.sin_port = htons(PORT);
		ser_addr.sin_addr.s_addr = INADDR_ANY;//inet_addr(IP);
	}
	cnt = bind(sfd, (struct sockaddr *)&ser_addr, sizeof(struct sockaddr));
	if(0 > cnt)
	{
		perror("bind error:");
		goto _out;
	}

	while(1)
	{
		//recvfrom
		len = sizeof(struct sockaddr);
		memset(&from_addr, 0, sizeof(struct sockaddr));
		memset(buf, 0, sizeof(buf));
		cnt = recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&from_addr, &len);
		if(0 > cnt)
		{
			perror("received error:");
			goto _out;
		}
		printf("buf = %s\n",buf);

		//sendto
		{
			//ser_buf
			fgets(ser_buf, sizeof(ser_buf), stdin);
		}
		cnt = sendto(sfd, ser_buf, sizeof(ser_buf), 0, (struct sockaddr *)&from_addr, len);
		if(0 > cnt)
		{
			perror("sendto error:");
			goto _out;
		}
	}
	
	//close
	close(sfd);
	return 0;
_out:
	return -1;
}
