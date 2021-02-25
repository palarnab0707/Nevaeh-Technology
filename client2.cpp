#include<iostream>
#include<time.h>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
using namespace std;
int main()
{
	int client,start,end;
	bool isexit=false;
	client=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serv_addr;
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(6300);
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	int con=connect(client,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	if(con==-1)
	{
		cout<<"Connection failed"<<endl;
	}
	char buffer[256];
	while(1)
	{
		cout<<"Enter end to terminate"<<endl;
		cout<<"client: "<<endl;
		cin>>buffer;
		send(client,buffer,sizeof(buffer),0);
		cout<<"Servver: "<<endl;
		start=time(NULL);
		recv(client,&buffer,sizeof(buffer),0);
		end=time(NULL);
		if((end-start)>15)
		{
			char uffer[256]="end";
			send(client,uffer,sizeof(uffer),0);
			exit(1);
		}
		if(strcmp(buffer,"end")==0)
		{
			exit(1);
		}
		cout<<buffer<<endl;
		memset(buffer,' ',sizeof(buffer));
		cout<<"Client: "<<endl;
		cin>>buffer;
		send(client,&buffer,sizeof(buffer),0);
		if(strcmp(buffer,"end")==0)
		{
			exit(1);
		}
	}

	return 0;
}
