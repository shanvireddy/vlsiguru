#include<stdio.h>
#define size 5
int queue[size];
int head=-1;
int tail=-1;
int addqueue(int element)
{
		
	if((tail==size) && head==0)
	{
			return 0;
	}
	else if(head==-1)
	{
			tail=0;
			queue[tail]=element;
			tail++;
			head=0;
		return 1;
			
	}
	else if((tail==size) && (head!=0))
	{	
		tail=0;
		queue[tail]=element;
		tail++;
		return 1;			
	}	
	else
	{
		queue[tail]=element;
		tail++;
		return 1;
	}
	

}

int deletequeue()
{
	int delete; // holds the deleted element from the queue
	if(head==-1)
	{
		return 0;
	}
	else if(head==tail)
	{
		head=-1;
		tail=-1;
		return 0;
	}
	else
	{
		delete=queue[head];
		head++;
		return 1;
	}
}
void printqueue()
{
	int idx;
/* print the queue from head to tail till it reaches its maximum size*/
	if(tail>=head)
	{
		for(idx=head;idx<tail;idx++)
		{
			printf("%d\n",queue[idx]);	
		}
	}
/* print the queue when it reaches maximum size and then tail starts from 0*/
	else
	{
		for(idx=head;idx<size;idx++)
		{
			printf("%d\n",queue[idx]);	
		}
		for(idx=0;idx<=tail;idx++)
		{
			printf("%d\n",queue[idx]);
			printf("tail %d\n",tail);
		}
	}
}
int main()
{
	int choice; // holds choice of selection
	int flag;
	int q;		//holds the element read from keyboard
	
	flag=1;
	
	while(flag)
	{	
	/*........... printing menu..............*/
	
		printf("enter your choice:\n" );
		printf("1.addition\n"); 
		printf("2.deletion\n");
		printf("3.exit\n");
		scanf("%d",&choice);
		printf("\n");
		
		switch(choice)
			{
				case 1:
					{	
						printf("add the elements into the queue :\t");
						scanf("%d",&q);
						
						if(addqueue(q)==0)
							printf("the queue is full\n");
						else
							printqueue();
							printf("..........................\n");	
					}
					break;
				case 2:
					{	
						if(deletequeue()==0)
							printf("the queue is empty:\n");
						else
							printqueue();
							printf("..........................\n");
					break;
					}
				case 3:
					{
						flag=0;
						break;
					}
					
				default:
					{
						flag=0;
						break;
					}
		
			}	
	}
}
