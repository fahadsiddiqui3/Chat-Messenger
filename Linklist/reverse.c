#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void reverse(DLL **ptr)
{
	DLL *temp;

	
		do{
			temp=(*ptr)->next;
			(*ptr)->next=(*ptr)->back;
			(*ptr)->back=temp;

			if((*ptr)->back)
				(*ptr)=(*ptr)->back;

		}while((*ptr)->back);
	



}
