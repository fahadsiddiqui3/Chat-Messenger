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

			v.mtype=2;
			msgrcv(id,&v,100,v.mtype,0);
			//perror("msgrcv");

			// else
			printf("<<<%s\n",v.mtext);


		}


	}


	else 
	{
		while(1)//sender
		{

			printf(">>>\n");
			//fgets(v.mtext,19,stdin);
			gets(v.mtext);
			v.mtype=1;
			if(msgsnd(id,&v,strlen(v.mtext)+1,0)==-1)
				perror("msgsnd");	

		}



	}


}
