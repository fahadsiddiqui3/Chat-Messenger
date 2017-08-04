#include"header.h"
#include<stdio.h>

main()
{
	DLL *head=0;
	char choice;

	while(1)
	{
		printf("\na:add a new node\n");
		printf("d:delete\n");
		printf("p:print all\n");
		printf("r:reverse\n");
		printf("q:quit\n");
		printf("Enter your choice\n");
		scanf("%c",&choice);

		switch(choice)
		{
			case 'a':add(&head);break;
			case 'd':delete(&head);break;
			case 'r':reverse(&head);break;
//			case 'z':deleteall(&head);break;
			case 'p':print(head);break;
			case 'q':return;

		}//switch
		while(getchar()!=10);

	}//while



}//main
