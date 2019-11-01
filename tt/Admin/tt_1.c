#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 500
#define colors 3
#define value 100
#define size 50
#define room 11
#define lab_room 7
#define lab_slot 8
#define time_slt 15
#define row 5
struct node
{
	char course[size];
	int no_student;
	int color[colors];
	char lab;
	int priority;
	char *temp_slot[size];
	char *temp_room[size];
};

struct node1{
	char course[size];
	int no_student;
	int color[colors];
	char lab;
};

struct node2{
    char *room_no[size];
	int capacity;
};

struct node3{
	char *slot[size];
	//string slot;
	//int clr;
};
struct node4
{
	struct node2 cl;
	struct node3 slt;
};

struct node5
{
	char tslot[size];
	int tcolor[colors];
} temp1[max];

struct node6{
	int first_vertex;
	int second_vertex;
};
struct node7
{
	char time_slot[size];
	char  day[colors][value];
	char time[colors][value];
};

// check weather slot is taken by same semester 
int find(struct node c[], struct node4 H[], int i ,int j,int ch)
{
	int t,k;
	for(t=0; t<ch; t++)
	{
		if(!strcmp(H[j].slt.slot, temp1[t].tslot))
		{
			for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp1[t].tcolor[k])
				{
				 return 1;
				}
			}
			//printf("color=%d\tslot =%s\n",temp1[t].tcolor, temp1[t].tslot);
			
		}
	}
	return 0;
}

/* Sorting Function */
 void sort(int n,struct node x[]) 
 {   int i,j;
    struct node temp;
 	for (i = 0; i < n; ++i) 
        { if(x[i].priority == 0)
        {
            for (j = i + 1; j < n; ++j) 
            {
                if (x[i].no_student < x[j].no_student) 
                {
                    temp = x[i];
                    x[i] = x[j];
                    x[j] = temp;
                }
            }
        }
  }
}
  
  void sort_priority(int n,struct node x[]) 
 {   int i,j;
    struct node temp;
 	for (i = 0; i < n; ++i) 
        {
            for (j = i + 1; j < n; ++j) 
            {
                if (x[i].priority < x[j].priority) 
                {
                    temp = x[i];
                    x[i] = x[j];
                    x[j] = temp;
                }
            }
        }
  } 
  

int main()
{
 int i,j,k,m,y,col,flag,temp,l,ch=0,edge=0,loop,local;
 struct node c[max];
 struct node2 r[max];
 struct node3 s[max];
 struct node4 H[max];
 int graph[value][max];
 struct node6 M[max];
 struct node7 ts[time_slt];
 int slot_room,slot_lab,x=15;
 char* mat[6][9];
 char tslot[size];
 slot_room=x*room;
 slot_lab=lab_room*lab_slot;
 FILE *room_file,*course_file,*slot_file,*input_graph,*output_graph;
  
 /**************************** taking inputs from file for courses and rooms*********************/
 slot_file = fopen("slot_fromdb.txt", "r");

    if (slot_file == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        for(i=0;i<15;i++)
        {
        	fscanf(slot_file,"%s ",&ts[i].time_slot);
        	if(i<4)
        	{
			
        	for(j=0;j<colors;j++)
        	{
        	fscanf(slot_file,"%s ",&ts[i].day[j]);	
			}
			for(j=0;j<3;j++)
        	{
        	fscanf(slot_file,"%s ",&ts[i].time[j]);	
			}
			fscanf(slot_file,"\n");
	     }
	     else
	     {
	     	for(j=0;j<2;j++)
        	{
        	fscanf(slot_file,"%s ",&ts[i].day[j]);	
			}
			for(j=0;j<2;j++)
        	{
        	fscanf(slot_file,"%s ",&ts[i].time[j]);	
			}
			fscanf(slot_file,"\n");
		 }
		}
        fclose(slot_file);
    }

 
/**************courses as input******************************/	
   course_file = fopen("course_file.txt", "r");

    if (course_file == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        fscanf(course_file, "%d", &m);
        for(i=0;i<m;i++)
        {
        	fscanf(course_file,"%s %d ",&c[i].course,&c[i].no_student);
        	for(j=0;j<colors;j++)
        	{
        	fscanf(course_file,"%d ",&c[i].color[j]);	
			}
			fscanf(course_file,"%c",&c[i].lab);
			fscanf(course_file,"%d",&c[i].priority);
			if(c[i].priority == 1)
			{
			fscanf(course_file,"%s",&c[i].temp_slot);
			fscanf(course_file,"%s",&c[i].temp_room);	
			}
		}
        fclose(course_file);
    }
    
/*************************all inputs has been taken from files *************************************/

/********************Sorting the course according to no of student enrolled  **************************/
   sort_priority((m),c);
   sort((m),c);
/******************** course has been sorted ***************************************/   
   
 for(i=0;i<(m);i++)
 {
 	printf("%s\t%d\t",c[i].course,c[i].no_student);
 	for(j=0;j<3;j++)
 	{
 		printf("%d\t",c[i].color[j]);
	 }
	 printf("%c\t",c[i].lab);
	 printf("%d\t",c[i].priority);
	 printf("%s\t%s",c[i].temp_slot,c[i].temp_room);
 	printf("\n");
 }  
 room_file = fopen("room_file.txt", "r");

    if (room_file == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        for(i=0;i<(room+lab_room);i++)
        {
        	fscanf(room_file,"%s%d",&r[i].room_no,&r[i].capacity);
		}
        fclose(room_file);
    } 
   
k=0;
for(i=0;i<x;i++){
	for(j=0;j<(room);j++)
	{
		//H[k].slt.slot=s[i].slot;
		strcpy(H[k].slt.slot,ts[i].time_slot);
		strcpy(H[k].cl.room_no,r[j].room_no);
		//H[k].cl.room_no=r[j].room_no;
		H[k].cl.capacity=r[j].capacity;
		k++;
	}
} 

for(i=lab_room;i<x;i++){
	for(j=room;j<(room+lab_room);j++)
	{
		//H[k].slt.slot=s[i].slot;
		strcpy(H[k].slt.slot,ts[i].time_slot);
		strcpy(H[k].cl.room_no,r[j].room_no);
		//H[k].cl.room_no=r[j].room_no;
		H[k].cl.capacity=r[j].capacity;
		k++;
	}
}


/****************** all slots combined with room no.************************/
  for(i=0;i<(m);i++)
 {
 	for(j=0;j<slot_room;j++)
 	{
 		graph[i][j]=0;
	 }
 }
  
/*************************high priority *************************************/  
  for(i=0;i<m;i++)
  {
  	if(c[i].priority==1)
  	{
  		tslot[0]='\0'; 
   for(j=0;j<slot_room;j++)
   { 
   	if(c[i].no_student<=H[j].cl.capacity)
   	{
		if(find(c,H,i,j,ch))
			continue;

		// filling all the same slot
		if(!(strcmp(c[i].temp_slot,H[j].slt.slot)))
		{
   			if(!(strcmp(c[i].temp_room,H[j].cl.room_no)))
   			{
			   if(tslot[0] == '\0')
			   {
			   graph[i][j] =1;
			strcpy(tslot ,H[j].slt.slot);
	       }
		}
	}
		else if(!strcmp(tslot, H[j].slt.slot))
		{
			graph[i][j] = 1;
		} 	
	}
   }
   for(k=0;k<colors;k++)
   {
   	temp1[ch].tcolor[k] = c[i].color[k];
   }
	
	strcpy(temp1[ch].tslot, tslot);
	//printf("temp1 %d %s %s\n",temp1[ch].tcolor, temp1[ch].tslot, H[j].slt.slot);
	ch++;
   } 
   
   
/*****************************low priority ******************************************/  
 if(c[i].priority==0)
 {   
  if(c[i].lab=='n')
 {  
    tslot[0]='\0'; 
   for(j=0;j<slot_room;j++)
   { 
   	if(c[i].no_student<=H[j].cl.capacity)
   	{
		if(find(c,H,i,j,ch))
			continue;

		// filling all the same slot
		if(tslot[0] == '\0')
		{
   		    graph[i][j] =1;
			strcpy(tslot ,H[j].slt.slot);
		}
		else if(!strcmp(tslot, H[j].slt.slot))
		{
			graph[i][j] = 1;
		} 	
	}
   }
   for(k=0;k<colors;k++)
   {
   	temp1[ch].tcolor[k] = c[i].color[k];
   }
	
	strcpy(temp1[ch].tslot, tslot);
	ch++; 
  } 
	 
else
{  
    tslot[0]='\0'; 
   for(j=slot_room;j<(slot_room+slot_lab);j++)
   { 
   	if(c[i].no_student<=H[j].cl.capacity)
   	{
		if(find(c,H,i,j,ch))
			continue;

		// filling all the same slot
		if(tslot[0] == '\0')
		{
   			graph[i][j] =1;
			strcpy(tslot ,H[j].slt.slot);
		}
		else if(!strcmp(tslot, H[j].slt.slot))
		{
			graph[i][j] = 1;
		} 	
	}
   }
   for(k=0;k<colors;k++)
   {
   	temp1[ch].tcolor[k] = c[i].color[k];
   }
	
	strcpy(temp1[ch].tslot, tslot);
	//printf("temp1 %d %s %s\n",temp1[ch].tcolor, temp1[ch].tslot, H[j].slt.slot);
	ch++;
  } 
 } 
}








for(i=0;i<(m);i++)
 {
 	for(j=0;j<(slot_room+slot_lab);j++)
 	{
 	 	if(graph[i][j]==1)
 		{
 			edge=edge+1;
		 } 
	 }
  } 



 for(i=0;i<(m);i++)
 {
 	printf("%s-->",c[i].course);
 	for(j=0;j<(slot_room+slot_lab);j++)
 	{
 		if(graph[i][j]==1)
 		{
 			printf("(%s,%s)",H[j].slt.slot,H[j].cl.room_no);
		 }
	 }
	 printf("\n");
  }  
  
  
    input_graph = fopen("input_graph.txt", "w");

    if (input_graph == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
    	fprintf(input_graph,"%d\n",edge);
		for(i=0;i<(m);i++)
    	{
    		for(j=0;j<(slot_room+slot_lab);j++)
 	        {
 		    	if(graph[i][j]==1)
 	              {
 		            fprintf(input_graph,"%d\t%d\t%d\n",(i+1),(j+value),0);
 		            }
	           }
		}
    fclose(input_graph); 
}
 
printf("input for matching is generated(till nown single course has many slot_room combination)"); 

return 0;
}
