#include"header.h"
#include<stdio.h>
void print (DLL *ptr)
{
	

	DLL *temp=ptr;
	while(temp)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}

}
