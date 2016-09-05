/*1.TCP/IP协议栈整体
2.linux内存分配机制
3.项目相关*/



#include<iostream>
#include<cmath>
using namespace std;
int s[100];
int main()
{
	int t,m,i,j,c,f,d;
	cin>>t;
	while(t--)
	{
		int sum=0;
		cin>>m;
		for(i=1;sum<m; i++)
		{
			f=(int)pow((double)2,(double)i);
			sum+=f;
			d=sum-f;
			c=m-d;
			if(c%f<=f/2&&c%f!=0)
				s[i]=4;
			else
				s[i]=7;	
		}
		for(j=i-1;j>=1;j--)
			cout<<s[j];
		cout<<endl;
	}
	return 0;
}
