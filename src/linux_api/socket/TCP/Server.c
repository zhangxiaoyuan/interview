

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>	
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

#define PORT 6676
#define BACKLOG 30

 /****** 线程：用于接收客户端信息 ********************************************************************************/
void *fun_recvfrom(void *agrv)
{
	int sfd = -1;
	int cnt = -1;
	int len = -1;
	char buf[128] = {0};
	time_t my_time;
	struct sockaddr_in ser_addr;

	len = sizeof(struct sockaddr);
	sfd = *(int *)agrv;
	while(1)
	{
		memset(&ser_addr, 0, len);
		memset(buf, 0, sizeof(buf));
		cnt = recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&ser_addr, &len); 
		if(0 > cnt)
		{
			perror("recvfrom err:");
			return;
		}
		my_time = time(&my_time);
		printf("%s", ctime(&my_time));
		printf("server : %s", buf);
	}
	return;
}

int main(void)
{
	int cnt =  -1;
	int sfd =  -1;
	int afd =  -1;
	int len =  -1;
	pthread_t pid;
	void *retval = NULL;
	char buf[128] = {0};
	struct sockaddr_in ser_addr;
	struct sockaddr_in from;

	//socket
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(0 > sfd)
	{
		perror("socket err:");
		goto _out;
	}

	//init
	memset(&ser_addr, 0, sizeof(struct sockaddr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(PORT);
	ser_addr.sin_addr.s_addr = INADDR_ANY;
	
	//bind
	cnt = bind(sfd, (struct sockaddr *)&ser_addr, sizeof(struct sockaddr));
	if(0 > cnt)
	{
		perror("bind err:");
		goto _out;
	}

	//listen
	cnt = listen(sfd, BACKLOG);
	if(0 > cnt)
	{
		perror("listen err:");
		goto _out;
	}
	
	len = sizeof(struct sockaddr);
	memset(&from, 0, sizeof(struct sockaddr));
	//accept
	afd = accept(sfd, (struct sockaddr *)&from, &len);
	if(0 > afd)
	{
		perror("accept err:");
		goto _out;
	}	

	//create pthread
	cnt = pthread_create(&pid, NULL, fun_recvfrom, &afd);
	if(0 > cnt)
	{
		perror("pthread create err:");
		goto _out;
	}	
	
	//发送信息给客户端
	while(1)
	{
		len = sizeof(struct sockaddr);
		//键盘输入
		fgets(buf, sizeof(buf), stdin);
		//sendto
		cnt = sendto(afd, buf, sizeof(buf), 0, (struct sockaddr *)&from, len);
		if(0 > cnt)
		{
			perror("send to err:");
			goto _out;
		}
	}
	
	//wait：阻塞等待
	pthread_join(pid, (void *)&retval);	

	//close
	close(sfd);
	return 0;
_out:
	close(sfd);
	return -1;
}

