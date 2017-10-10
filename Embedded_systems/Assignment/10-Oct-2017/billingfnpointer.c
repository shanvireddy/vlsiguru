/* program to read mobile user data from the csv file and calculate monthly charges for each user depends on their lanID*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define maxpercentcount 10

typedef struct node
{
	char name[10];
	int age;
	int usage;
	int planID;
	float monthlyCharges ;
	struct node *next;
}NODE;

struct classified
{
	int bracket;
	int no_Ofusers;
}classify[100];
/* Global variable declaration*/

struct node *head=NULL;
float percentvalue[100];
/* this function will read input from the csv file and create the linkedlist*/

void CreateList() 
{
	FILE *csvFilePtr ;
   	int flag ;
   	char buffer[200];
  	char *record ;
  	struct node *temp;
  	struct node *currentnode=NULL;
  	int NoOfnodes;
  	NoOfnodes=0;
  	flag=1;
  	csvFilePtr=fopen("info.csv","r");
  		if(csvFilePtr==NULL)
  		{
  			printf("Unable to open the file\n");
  			exit(1);
  		}
  	/* Skip the header */
  	
  	fgets(buffer,200, csvFilePtr);
  	while(flag)
  	{
		if (fgets(buffer,200,csvFilePtr) == NULL)
     	{
       		flag = 0 ;
       		continue ;
     	}
     	record=strtok(buffer,",");
     	
     	temp=(NODE*)malloc(sizeof(NODE));
     	strcpy(temp->name,record);
     	
     	record=strtok(NULL,",");
     	temp->age=atoi(record);
     	record=strtok(NULL,",");
     	temp->usage=atoi(record);
     	record=strtok(NULL,",");
     	temp->planID=atoi(record);
     	temp->next=NULL;
     	NoOfnodes++;
     	
     	if(head==NULL)
     	{
     		head=temp;
			currentnode=temp;	
		}
		else
		{
			currentnode->next=temp;
			currentnode=temp;
		}
     	printf("node %d elements:\n",NoOfnodes);
		printf("%s ",currentnode->name);
     	printf("%d ",currentnode->age);
     	printf("%d ",currentnode->usage);
     	printf("%d ",currentnode->planID);
     	printf("\n");
     	printf("............\n"); 	  	
   }
}
int FindMaxUsage()
{
	struct node *temp;
	int max;
	
	temp=head;
	max=temp->usage;
	
	while(temp!=NULL)
	{
		if(max<=temp->usage)
		{
			max=temp->usage;
			temp=temp->next;
		}
			temp=temp->next;
	}
	return max;
	printf("the max usage of all users is %d\n",max);
}
void FindMaxusagePercent(int max)
{
	int idx;
	int percent;
	float value;
	
	percent=100;
	idx=0;
	
	for(idx=0;idx<maxpercentcount;idx++)
	{
		value=(percent*max)/100;
		percentvalue[idx]=value;
		percent-=10;
	}
	for(idx=0;idx<maxpercentcount;idx++)
	{
		printf("bracket is  %f\n",percentvalue[idx]);
	}
}
void ClassifyData()
{
	int idx;
	struct node *temp;
	int percent;
	
	temp=head;
	percent=100;
	
	for(idx=0;idx<maxpercentcount;idx++)
	{
		classify[idx].bracket=percent;
		percent-=10;
	}
	while(temp!=NULL)
	{
		percent=100;
		for(idx=0;idx<maxpercentcount;idx++)
		{
			if(percentvalue[idx]>=temp->usage)
			{
				percent-=10;
			}
			else
			{
				classify[idx-1].no_Ofusers++;
				break;
			}
		}
		temp=temp->next;
	}
	for(idx=0;idx<maxpercentcount;idx++)
	{
		printf(" the no.of users for %d bracket is %d\n",classify[idx].bracket,classify[idx].no_Ofusers);

	}	
}
void WriteToCsvfile()
{
	FILE *CsvPtr;
	int idx;
	
	CsvPtr=fopen("outputcsv.csv","w");
	fprintf(CsvPtr,"bracket,no_Ofusrs\n");
	
		for(idx=0;idx<10;idx++)
		{
	    	fprintf(CsvPtr,"%d%%,",classify[idx].bracket);
	    	fprintf(CsvPtr,"%d\n",classify[idx].no_Ofusers);
		}
	fclose(CsvPtr);
}
float PlanOne(int no_ofHrs)
{
	float bill;
	int basecharge=100;
	
	if(no_ofHrs<=50)
	{
		bill=basecharge;		
	}
	else if(no_ofHrs>50 &&no_ofHrs<=150)
	{
		no_ofHrs=no_ofHrs-50;
		bill+=basecharge+no_ofHrs*0.5;
	}
	else if(no_ofHrs>150 && no_ofHrs<=250)
	{
		no_ofHrs=no_ofHrs-150;
		bill+=basecharge+100*0.5+no_ofHrs*0.55;;
	}
	else
	{
		no_ofHrs=no_ofHrs-250;
		bill=basecharge+50*0+(100*0.5)+(100*0.55)+(no_ofHrs*0.6);
	}
	return bill;
}
float PlanTwo(int no_ofHrs)
{
	float bill;
	int basecharge=300;
	
	if(no_ofHrs>0 && no_ofHrs<=75)
	{
		bill=basecharge;
	}
	else if(no_ofHrs>75 && no_ofHrs<=175)
	{
		no_ofHrs=no_ofHrs-75;
		bill+=basecharge+no_ofHrs*0.45;
	}
	else if(no_ofHrs>175 && no_ofHrs<=275)
	{
		no_ofHrs=no_ofHrs-175;
		bill+=basecharge+100*0.45+no_ofHrs*0.5;
	}
	else
	{
		no_ofHrs=no_ofHrs-250;
		bill=basecharge+75*0+(100*0.45)+(100*0.5)+(no_ofHrs*0.55);
	}
	return bill;
}
float PlanThree(int no_ofHrs)
{
	float bill;
	int basecharge=400;
	
	if(no_ofHrs>0 && no_ofHrs<=90)
	{
		bill=basecharge;
	}
	else if(no_ofHrs>90 && no_ofHrs<=190)
	{
		no_ofHrs=no_ofHrs-50;
		bill+=basecharge+no_ofHrs*0.45;
	}
	else if(no_ofHrs>190 && no_ofHrs<=290)
	{
		no_ofHrs=no_ofHrs-190;
		bill+=basecharge+100*0.45+no_ofHrs*0.5;
	}
	else
	{
		no_ofHrs=no_ofHrs-250;
		bill=basecharge+90*0+(100*0.45)+(100*0.5)+(no_ofHrs*0.55);
	}
	return bill;
}
float PlanFour(int no_ofHrs)
{
	float bill;
	int basecharge=500;
	
	if(no_ofHrs<=100)
	{
		bill=basecharge;
	}
	else if(no_ofHrs > 100 && no_ofHrs <= 200)
	{
		no_ofHrs=no_ofHrs-50;
		bill+=basecharge+no_ofHrs*0.4;
	}
	else if(no_ofHrs>200 && no_ofHrs<=300)
	{
		no_ofHrs=no_ofHrs-200;
		bill+=basecharge+100*0.4+no_ofHrs*0.5;
	}
	else
	{
		no_ofHrs=no_ofHrs-250;
		bill=basecharge+(100*0.4)+(100*0.5)+(no_ofHrs*0.3);
	}
	return bill;
}
void DoBilling()
{
	struct node *temp;
	int no_Ofnodes;
	char name[10];
	float bill;
	
	no_Ofnodes=0;
	temp=head;
	
	float (*arrayfxnpointer[4])(int);
	
// Assign address of the four functions to it
 	arrayfxnpointer[0] = &PlanOne ;
 	arrayfxnpointer[1] = &PlanTwo ;
 	arrayfxnpointer[2] = &PlanThree ;
 	arrayfxnpointer[3] = &PlanFour ;
 	
	while(temp!=NULL)
	{	
		if(temp->planID>0 && temp->planID<=4)
		{
			temp->monthlyCharges=(*arrayfxnpointer[temp->planID-1])(temp->usage);
			printf("the node %d element\n\n",no_Ofnodes+1);
			printf("user name is :%s\nusage is :%d Hrs\nthe planID :%d\nmonthly bill is :%f \n",temp->name,temp->usage,temp->planID,temp->monthlyCharges);
			printf("....................................\n");
		 	no_Ofnodes++;	 	
		}				
		temp=temp->next;
	}
}
main()
{
   	int maxusage;
   	CreateList();
	maxusage=FindMaxUsage();
	FindMaxusagePercent(maxusage);
	ClassifyData();
	WriteToCsvfile();
	DoBilling();
}

