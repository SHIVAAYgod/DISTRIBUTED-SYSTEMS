// server

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<strings.h>
#include<stdio.h>
 
void func(char arr[])
 
{
 
 
 
 int mp[26];
 
 for(int i=0;i<26;i++) mp[i]=0;
 
 
 
 for(int i=0;i<10;i++)
 
 {
 
 if(mp[arr[i]-'a']==0)
 
 {
 
 mp[arr[i]-'a']=1;
 
 
 
 }
 
 else
 
 arr[i]='#';
 
 }
 
 
 
}
 
int main()
 
{
 
int serid,sessid;
 
char c[10];
 
struct sockaddr_in server_address,client_address;
 
int server_addlen,client_addlen;
 
server_address.sin_family=AF_INET;
 
server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
 
server_address.sin_port=5080;
 
server_addlen=sizeof(server_address);
 
client_addlen=sizeof(client_addlen);
 
serid=socket(AF_INET,SOCK_STREAM,0);
 
bind(serid,(struct sockaddr*)&server_address,server_addlen);
 
listen(serid,10);
 
 
while(1)
 
{
 
printf("Server is ready to accept ......\n");sessid=accept(serid,(struct sockaddr *)&client_address,&client_addlen);
 
read(sessid,c,sizeof(c));
 
func(c);
 
 
write(sessid,c,sizeof(c));
 
close(sessid);
 
}
 
return(0);
 
}





//client

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<strings.h>
#include<stdio.h>
 
int main()
 
{ int sid;
 
char c[10];
 
for(int i=0;i<10;i++)
 
scanf("%c",&c[i]);
 
struct sockaddr_in server_address;
 
int server_addlen;
 
server_address.sin_family=AF_INET;
 
server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
 
server_address.sin_port=5080;
 
server_addlen=sizeof(server_address);
 
sid=socket(AF_INET,SOCK_STREAM,0);
 
connect(sid,(struct sockaddr *)&server_address,server_addlen);
 
write(sid,c,sizeof(c));
 
read(sid,c,sizeof(c));
 
printf("message from server : ");
 
for(int i=0;i<10;i++)
 
{
 
 if(c[i]!='#')
 
 printf("%c",c[i]);
 
}
 
printf("\n");
 
close(sid);
 
return(0);
 
}
