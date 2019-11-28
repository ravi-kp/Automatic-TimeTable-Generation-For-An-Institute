#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 500
#define colors 6
#define value 100
#define size 50
#define room 11
#define lab_room 16
#define lab_slot 7
#define time_slt 22
struct Input_Course
{
	char course[size];
	int no_student;
	int color[colors];
	char lab;
	int priority;
	char *temp_slot[size];
	char *temp_room[size];
	char *division[size];
	char selected_lab[room][size];
};

struct Input_room{
    char *room_no[size];
	int capacity;
};

struct Slot_Name{
	char *slot[size];
};
struct Slot_Room_Combination
{
	struct Input_room cl;
	struct Slot_Name slt;
};

struct Color_Checking
{
	char tslot[size];
	int tcolor[colors];
	char *tdivision[size];
	char *tcoursename[size];
	char troom[max][size];
} temp_color_slot_checking[max];

struct Graph_Vertext{
	int first_vertex;
	int second_vertex;
};
struct Slot_From_Database
{
	char time_slot[size];
	char  day[colors][value];
	char time[colors][value];
};

// check weather slot is taken by same semester 
int find(struct Input_Course c[], struct Slot_Room_Combination H[], int i ,int j,int ch)
{
	int t,k,temp;
	for(t=0; t<ch; t++)
	{
     if(!strcmp(H[j].slt.slot,"S8") || !strcmp(H[j].slt.slot,"S9"))
	{
	 if(!strcmp(H[j].slt.slot, temp_color_slot_checking[t].tslot))
		{
			for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 temp=1;
				}
			}
			
		}
		if(!strcmp(temp_color_slot_checking[t].tslot,"L1"))
		{
			temp=0;
			for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 temp= 1;
				}
			}
		}
		if(!strcmp(temp_color_slot_checking[t].tslot,"L3"))
		{  temp=0;
		   for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 temp= 1;
				}
			}	
		}
		return temp;	
	}	
		
	if(!strcmp(H[j].slt.slot,"S10") || !strcmp(H[j].slt.slot,"S11"))
	{
	 if(!strcmp(H[j].slt.slot, temp_color_slot_checking[t].tslot))
		{
			for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 temp= 1;
				}
			}
			
		}
		if(!strcmp(temp_color_slot_checking[t].tslot,"L2"))
		{ temp=0;
			for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 temp= 1;
				}
			}
		}
		if(!strcmp(temp_color_slot_checking[t].tslot,"L4"))
		{
			temp=0;
		   for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 temp= 1;
				}
			}	
		}
		return temp;
			
	}
		
	if(!strcmp(H[j].slt.slot,"S5") || !strcmp(H[j].slt.slot,"S6"))
	{
	 if(!strcmp(H[j].slt.slot, temp_color_slot_checking[t].tslot))
		{
			for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 temp= 1;
				}
			}
			
		}
		if(!strcmp(temp_color_slot_checking[t].tslot,"L5"))
		{ temp=0;
			for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 temp= 1;
				}
			}
		}
		if(!strcmp(temp_color_slot_checking[t].tslot,"L6"))
		{
			temp=0;
		   for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 temp= 1;
				}
			}	
		}
		return temp;
			
	}
	
		
	else
	{
		if(!strcmp(H[j].slt.slot, temp_color_slot_checking[t].tslot))
		{
			for(k=0;k<colors;k++)
			{
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 return 1;
				}
			}
			//printf("color=%d\tslot =%s\n",temp_color_slot_checking[t].tcolor, temp_color_slot_checking[t].tslot);
			
		}
	}
}
	return 0;
}
/****************************find function for lab**************************************************/
int find_lab(struct Input_Course c[], struct Slot_Room_Combination H[], int i ,int j,int ch)
{
	int t,k,local,temp,loop;
	for(t=0; t<ch; t++)
	{
		if(!strcmp(H[j].slt.slot, temp_color_slot_checking[t].tslot))
		{
			for(k=0;k<colors;k++)
			{    
				if(c[i].color[k] !=0 && c[i].color[k] == temp_color_slot_checking[t].tcolor[k])
				{
				 if(!(strcmp(c[i].division,temp_color_slot_checking[t].tdivision)) || (c[i].course !="NULL" && !(strcmp(temp_color_slot_checking[t].tcoursename,c[i].course))))
				 return 1;
				}
				
				if(c[i].color[k] !=0 && c[i].color[k] != temp_color_slot_checking[t].tcolor[k])
				{
				 for(loop=0;loop<(room+lab_room);loop++)
				 {
				 if(temp_color_slot_checking[t].troom[loop]!="NULL" && (!strcmp(H[j].cl.room_no,temp_color_slot_checking[t].troom[loop])))
				 {
				 //if(!(strcmp(c[i].division,temp_color_slot_checking[t].tdivision)) || (c[i].course !="NULL" && !(strcmp(temp_color_slot_checking[t].tcoursename,c[i].course))))
				 return 1;
		      	}
				}
			}
			}
			
		}
	  }
	return 0;
}





/* Sorting Function */
 void sort(int n,struct Input_Course x[]) 
 {   int i,j;
    struct Input_Course temp;
 	for (i = 0; i < n; ++i) 
        { if(x[i].priority == 0 && x[i].lab=='n')
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
 
  void sort_lab(int n,struct Input_Course x[]) 
 {   int i,j;
     char y,z;
    struct Input_Course temp;
 	for (i = 0; i < n; ++i) 
        { if(x[i].priority == 0 && x[i].lab == 'y')
        {
            for (j = i + 1; j < n; ++j) 
            {
               y=x[i].lab;
               z=x[j].lab;
			    if (y < z) 
                {
                    temp = x[i];
                    x[i] = x[j];
                    x[j] = temp;
                }
            }
        }
  }
}
  
 
  
  void sort_priority(int n,struct Input_Course x[]) 
 {   int i,j;
    struct Input_Course temp;
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
 struct Input_Course c[max];
 struct Input_room r[max];
 struct Slot_Name s[max];
 struct Slot_Room_Combination H[max];
 int graph[value][max];
 struct Graph_Vertext M[max];
 struct Slot_From_Database ts[time_slt];
 int slot_room,slot_lab,number_of_slot=15;
 char tslot[size];
 char temp_room[(room+lab_room)][size];
 slot_room=number_of_slot*room;
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
        for(i=0;i<(number_of_slot+lab_slot);i++)
        {
        	fscanf(slot_file,"%s ",&ts[i].time_slot);
        	if(i<4)
        	{
			
        	for(j=0;j<3;j++)
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


for(i=0;i<(number_of_slot+lab_slot);i++)
{
printf("%s ",&ts[i].time_slot);	
}
printf("\n");
/**************courses as input******************************/	
   course_file = fopen("course_file1.txt", "r");

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
			fscanf(course_file,"%c ",&c[i].lab);
			fscanf(course_file,"%d ",&c[i].priority);
			if(c[i].priority == 1)
			{
			fscanf(course_file,"%s ",&c[i].temp_slot);
			fscanf(course_file,"%s ",&c[i].temp_room);	
			}
			if(c[i].lab == 'y')
			{
				fscanf(course_file,"%s ",&c[i].division);
				for(local=0;local<3;local++)
				{ 
					fscanf(course_file,"%s ",&c[i].selected_lab[local]);
				}   
			}
		 fscanf(course_file,"\n");
		}
        fclose(course_file);
    }
    
    
  /* for(i=0;i<m;i++)
   {
   	 j=1;
   	printf("%s %d ",c[i].course,c[i].no_student);
        	for(j=0;j<colors;j++)
        	{
        	printf("%d ",c[i].color[j]);	
			}
			printf("%c ",c[i].lab);
				
			printf("%d ",c[i].priority);
			if(c[i].priority == 1)
			{
			printf("%s",c[i].temp_slot);
			printf("%s ",c[i].temp_room);	
			}
		
			if(c[i].lab=='y')
			{
				printf("%s ",c[i].division);
				for(local=0;local<2;local++)
				{
					printf("%s ",c[i].selected_lab[local]);
				}  
			}
			
			printf("\n");
	} */
    
    
/*************************all inputs has been taken from files *************************************/

/********************Sorting the course according to no of student enrolled  **************************/
   sort_priority((m),c);
  // sort_lab((m),c);
   sort((m),c); 
   
  /*  for(i=0;i<m;i++)
   {
   	 j=1;
   	printf("%s %d ",c[i].course,c[i].no_student);
        	for(j=0;j<colors;j++)
        	{
        	printf("%d ",c[i].color[j]);	
			}
			printf("%c ",c[i].lab);
				
			printf("%d ",c[i].priority);
			if(c[i].priority == 1)
			{
			printf("%s",c[i].temp_slot);
			printf("%s ",c[i].temp_room);	
			}
		
			if(c[i].lab=='y')
			{
				printf("%s ",c[i].division);
				for(local=0;local<3;local++)
				{
					printf("%s ",c[i].selected_lab[local]);
				}  
			}
			
			printf("\n");
	} 
   
/******************** course has been sorted ***************************************/  
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

for(i=0;i<(room+lab_room);i++)
{
	printf("%s %d",r[i].room_no,r[i].capacity);
	printf("\n");
}
   
k=0;
for(i=0;i<number_of_slot;i++){
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

/*for(i=0;i<slot_room;i++)
{
	printf("%s %s",H[i].slt.slot,H[i].cl.room_no);
	printf("\n");
} */

for(i=number_of_slot;i<(number_of_slot+lab_slot);i++){
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
/*for(i=slot_room;i<(slot_room+slot_lab);i++)
{
	printf("%s %s",H[i].slt.slot,H[i].cl.room_no);
	printf("\n");
} */

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
   	temp_color_slot_checking[ch].tcolor[k] = c[i].color[k];
   }
	
	strcpy(temp_color_slot_checking[ch].tslot, tslot);
	//printf("temp_color_slot_checking %d %s %s\n",temp_color_slot_checking[ch].tcolor, temp_color_slot_checking[ch].tslot, H[j].slt.slot);
	ch++;
   } 
}
   
/*****************************low priority ******************************************/ 
for(i=0;i<m;i++)
{  
local=0;
if(c[i].priority==0 && c[i].lab=='y')
{
	tslot[0]='\0'; 
for(loop=0;loop<(room+lab_room);loop++)
	{
	  temp_room[loop][size]="NULL";
	}
   for(j=slot_room;j<(slot_room+slot_lab);j++)
   { 
   	if(c[i].no_student<=H[j].cl.capacity)
   	{
		if(find_lab(c,H,i,j,ch))
			continue;

		// filling all the same slot
		if(tslot[0] == '\0')
		{
		if(!(strcmp(c[i].selected_lab[local],H[j].cl.room_no)))	
		{  
   			graph[i][j] =1;
			strcpy(tslot,H[j].slt.slot);
			strcpy(temp_room[flag],H[j].cl.room_no);
			flag++;
			local++;
		}
     	}
     	
		else if(!strcmp(tslot, H[j].slt.slot) &&!(strcmp(c[i].selected_lab[local],H[j].cl.room_no)))
		{
			graph[i][j] = 1;
			strcpy(temp_room[flag],H[j].cl.room_no);
			flag++;
		} 	
	}
   }
   for(k=0;k<colors;k++)
   {
   	temp_color_slot_checking[ch].tcolor[k] = c[i].color[k];
   }
	strcpy(temp_color_slot_checking[ch].tslot, tslot);
	 strcpy(temp_color_slot_checking[ch].tdivision,c[i].division);
	 strcpy(temp_color_slot_checking[ch].tcoursename,c[i].course);
	 for(k=0;k<(room+lab_room);k++)
	 {
	 strcpy(temp_color_slot_checking[ch].troom[k],temp_room[k]);
	 //printf("%s",temp_color_slot_checking[ch].troom[k]);
    }
	//printf("temp_color_slot_checking  %s %s\n",temp_color_slot_checking[ch].tslot, H[j].slt.slot);
	ch++;
  } 
 } 

for(i=0;i<m;i++)
{
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
   	temp_color_slot_checking[ch].tcolor[k] = c[i].color[k];
   }
	
	strcpy(temp_color_slot_checking[ch].tslot, tslot);
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
 
  for(i=0;i<(m);i++)
 {  if(c[i].lab=='y')
  {
 	printf("%s%s-->",c[i].course,c[i].division);
 	for(j=0;j<(slot_room+slot_lab);j++)
 	{
 		if(graph[i][j]==1)
 		{
 			printf("(%s,%s)",H[j].slt.slot,H[j].cl.room_no);
		 }
	 }
	 printf("\n");
  }

  else
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
} 
printf("input for matching is generated(till nown single course has many slot_room combination)"); 
return 0;
}
