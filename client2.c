#include"headers.h"

struct msgbuf{
		long mtype;
		char mtext[100];
		};


main()
{
	int id;
	struct msgbuf v;


		id=msgget(3,IPC_CREAT|0600);
		if(id==-1)
		{
			perror("msgget");
			return;

		}

	if(fork()==0) //receiver
	{
		
		while(1)
		{
			
		v.mtype=4;
		    if(msgrcv(id,&v,100,v.mtype,0)==-1)
			perror("msgrcv");
		
		    else
		printf("%d<<<%s\n",getpid(),v.mtext);


		}


	}


	else 
	{
		
		while(1)//sender
		{

			printf(">>>");
			//fgets(v.mtext,19,stdin);
			gets(v.mtext);
			v.mtype=3;
		if(msgsnd(id,&v,strlen(v.mtext)+1,0)==-1)
			perror("msgsnd");
		else
		puts("Sent.........>");	

		}
		


	}


}
