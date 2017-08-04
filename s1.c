#include"headers.h"

struct msgbuf{
	long mtype;
	char mtext[20];

};

main()
{
	struct msgbuf v,v1;
	int id1,id2;
	char cl1[20];
	char cl2[20];	


	id1=msgget(3,IPC_CREAT|0600);
	//	id2=msgget(2,IPC_CREAT|0600);
	if(id1==-1)
	{
		perror("msgget");
		return;

	}

	if(fork()==0)
	{
		while(1)
		{


			if(msgrcv(id1,&v,20,1,0)>0)
			{
				printf("msgrcv1 %s",v.mtext);
				//	strcpy(v.mtext,cl1);
				v.mtype=4;

				if(msgsnd(id1,&v,strlen(v.mtext)+1,0)==-1)
					perror("msgsnd");
				printf("sent\n");
			}
		}
	}
	else
	{		
		while(1)
		{

			if(msgrcv(id1,&v1,20,3,0)>0)
			{
				printf("msgrcv2 %s",v1.mtext);
				//strcpy(v.mtext,cl2);
				v1.mtype=2;
				msgsnd(id1,&v1,strlen(v1.mtext)+1,0);
				printf("sent\n");
			}


		}


	}
}
