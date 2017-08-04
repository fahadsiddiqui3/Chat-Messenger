#include"headers.h"

struct msgbuf{
		long mtype;
		char mtext[20];
		
		};

main()
{
	struct msgbuf v;
	int id;
//	char cl1[20];
//	char cl2[20];	


	id=msgget(3,IPC_CREAT|0600);

	if(id==-1)
		{
			perror("msgget");
			return;
		
		}
	while(1)
	{

	
		if(msgrcv(id,&v,20,1,IPC_NOWAIT)>0)
		{
			printf("msgrcv1 %s",v.mtext);
		//	strcpy(v.mtext,cl1);
			v.mtype=4;

			if(msgsnd(id,&v,strlen(v.mtext)+1,0)==-1)
				perror("msgsnd");
			printf("sent\n");
		}
		

		if(msgrcv(id,&v,20,3,IPC_NOWAIT)>0)
		{
			printf("msgrcv2 %s",v.mtext);
			//strcpy(v.mtext,cl2);
			v.mtype=2;
			msgsnd(id,&v,strlen(v.mtext)+1,0);
			printf("sent\n");
			}
		

	}


}
