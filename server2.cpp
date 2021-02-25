#include<iostream>
#include<time.h>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
using namespace std;
int main()
{
	int server,start,end;
	bool isexit=false;
	char sbuffer[256]="Hello how are You";
	server=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serv_addr;
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(6300);
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	bind(server,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	listen(server,3);
	int client;
	client=accept(server,NULL,NULL);
	while(client>0)
	{
		//strcpy(sbuffer,"Connected");
		//send(client,sbuffer,sizeof(sbuffer),0);
		cout<<"Enter end to terminate"<<endl;
		cout<<"Client: "<<endl;
		start=time(NULL);
		recv(client,sbuffer,sizeof(sbuffer),0);
		end=time(NULL);
		if((end-start)>15)
		{
			char ffer[256]="end";
			send(client,ffer,sizeof(ffer),0);
			exit(1);
		}
		if(strcmp(sbuffer,"end")==0)
		{
			exit(1);
		}
		cout<<sbuffer<<endl;
		memset(sbuffer,' ',sizeof(sbuffer));
		cout<<"Server: "<<endl;
		cin>>sbuffer;
		send(client,sbuffer,sizeof(sbuffer),0);
		if(strcmp(sbuffer,"end")==0)
		{
			exit(1);
		}
	}
	return 0;
}
