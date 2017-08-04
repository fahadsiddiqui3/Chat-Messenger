#include<stdio.h>
#include"header.h"
#include<stdlib.h>
void delete(DLL **ptr)
{
	DLL *temp=(*ptr);
	int data2del;
	printf("Enter the data to delete\n");
	scanf("%d",&data2del);
	
	while(temp &&(temp->data!=data2del))
	{
		temp=temp->next;
	}

	if(temp==NULL)
	{
		printf("NODE NOT FOUND\n");
		return;
	}

	if(temp==(*ptr)) //if its a first node
	{
		if(temp->next)///only one node //checking next node validation
		{
			(*ptr)=temp->next;								(*ptr)->back=0;
		}
		else (*ptr)=0;
		free(temp);	

	}

	else if(temp->next==NULL) //if last node
		{
		temp->back->next=0;
		free(temp);	

		}

	else {  ///else node
		temp->back->next=temp->next;
		temp->next->back=temp->back;
		free(temp);

		}


}
