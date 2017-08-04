#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void add(DLL **ptr2head)
{
	DLL *nu,*temp;

	nu=calloc(1,sizeof(DLL));
	printf("Enter the data\n");
	scanf("%d",&(nu->data));
	
	if((*ptr2head)==0)
	{
		(*ptr2head)=nu;
	}

	else if(nu->data < (*ptr2head)->data)
		{
			nu->next=(*ptr2head);
			(*ptr2head)->back=nu;
			(*ptr2head)=nu;
		}

	else {
		temp=(*ptr2head);

		while((temp) && (temp->next) && temp->next->data < nu->data ) 
			{
				temp=temp->next;	
			}//while

		nu->back=temp;
		nu->next=temp->next;

	if(temp->next) 
			temp->next->back=nu;
		
		temp->next=nu;


		}//else


}
