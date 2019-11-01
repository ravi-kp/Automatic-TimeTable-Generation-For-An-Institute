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
struct node8
{
	char temp_array[size];
};
  struct node9
 {
 	char time_slot[size];
	int  day[3];
	int time[3];
 };
 
 void sort(int n,struct node x[]) 
 {   int i,j;
    struct node temp;
 	for (i = 0; i < n; ++i) 
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
 struct node8 array[max];
struct node9 ts_new[max];
 int slot_room,slot_lab,x=15;
 char* mat[6][9];
 char tslot[size];
 slot_room=x*room;
 slot_lab=lab_room*lab_slot;
 FILE *room_file,*course_file,*slot_file,*input_graph,*output_graph;
 FILE *csIsem,*csIIIsem,*meIIIsem,*eeIIIsem,*csVsem,*meVsem,*eeVsem,*csVIIsem,*meVIIsem,*eeVIIsem;
 /****taking slot as input from database file************************/
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
    
for(i=0;i<15;i++)
{
	if(i<4)
	{
		strcpy(ts_new[i].time_slot,ts[i].time_slot);
		for(j=0;j<3;j++)
		{
		if(!(strcmp(&(ts[i].day[j]),"Monday")))
		{
			ts_new[i].day[j]=0;
		}
		if(!(strcmp(&(ts[i].day[j]),"Tuesday")))
		{
			ts_new[i].day[j]=1;
		}
		if(!(strcmp(&(ts[i].day[j]),"Wednesday")))
		{
			ts_new[i].day[j]=2;
		}
		if(!(strcmp(&(ts[i].day[j]),"Thursday")))
		{
			ts_new[i].day[j]=3;
		}
		if(!(strcmp(&(ts[i].day[j]),"Friday")))
		{
			ts_new[i].day[j]=4;
		}
		if(!(strcmp(&(ts[i].day[j]),"Saturday")))
		{
			ts_new[i].day[j]=5;
		}
	}
	for(j=0;j<3;j++)
	{
		if(!(strcmp(&(ts[i].time[j]),"8:30")) || !(strcmp(&(ts[i].time[j]),"9:00")))
		{
			ts_new[i].time[j]=0;
		}
		if(!(strcmp(&(ts[i].time[j]),"9:30")) || !(strcmp(&(ts[i].time[j]),"9:35")) || !(strcmp(&(ts[i].time[j]),"10:00")))
		{
			ts_new[i].time[j]=1;
		}
		if(!(strcmp(&(ts[i].time[j]),"10:30")) || !(strcmp(&(ts[i].time[j]),"10:35")) || !(strcmp(&(ts[i].time[j]),"11:00")))
		{
			ts_new[i].time[j]=2;
		}
		if(!(strcmp(&(ts[i].time[j]),"11:30")) || !(strcmp(&(ts[i].time[j]),"11:35")) || !(strcmp(&(ts[i].time[j]),"12:00")))
		{
			ts_new[i].time[j]=3;
		}
		if(!(strcmp(&(ts[i].time[j]),"2:00")) || !(strcmp(&(ts[i].time[j]),"2:30")))
		{
			ts_new[i].time[j]=4;
		}
		if(!(strcmp(&(ts[i].time[j]),"3:30")) || !(strcmp(&(ts[i].time[j]),"4:00")))
		{
			ts_new[i].time[j]=5;
		}
		if(!(strcmp(&(ts[i].time[j]),"5:00")) || !(strcmp(&(ts[i].time[j]),"5:30")))
		{
			ts_new[i].time[j]=6;
		}
		if(!(strcmp(&(ts[i].time[j]),"6:30")) || !(strcmp(&(ts[i].time[j]),"7:00")))
		{
			ts_new[i].time[j]=7;
		}
	}
	
  }
  else
  {
  	strcpy(ts_new[i].time_slot,ts[i].time_slot);
		for(j=0;j<2;j++)
		{
		if(!(strcmp(&(ts[i].day[j]),"Monday")))
		{
			ts_new[i].day[j]=0;
		}
		if(!(strcmp(&(ts[i].day[j]),"Tuesday")))
		{
			ts_new[i].day[j]=1;
		}
		if(!(strcmp(&(ts[i].day[j]),"Wednesday")))
		{
			ts_new[i].day[j]=2;
		}
		if(!(strcmp(&(ts[i].day[j]),"Thursday")))
		{
			ts_new[i].day[j]=3;
		}
		if(!(strcmp(&(ts[i].day[j]),"Friday")))
		{
			ts_new[i].day[j]=4;
		}
		if(!(strcmp(&(ts[i].day[j]),"Saturday")))
		{
			ts_new[i].day[j]=5;
		}
	}
	for(j=0;j<2;j++)
	{
		if(!(strcmp(&(ts[i].time[j]),"8:30")) || !(strcmp(&(ts[i].time[j]),"9:00")))
		{
			ts_new[i].time[j]=0;
		}
		if(!(strcmp(&(ts[i].time[j]),"9:30")) || !(strcmp(&(ts[i].time[j]),"9:35")) || !(strcmp(&(ts[i].time[j]),"10:00")))
		{
			ts_new[i].time[j]=1;
		}
		if(!(strcmp(&(ts[i].time[j]),"10:30")) || !(strcmp(&(ts[i].time[j]),"10:35")) || !(strcmp(&(ts[i].time[j]),"11:00")))
		{
			ts_new[i].time[j]=2;
		}
		if(!(strcmp(&(ts[i].time[j]),"11:30")) || !(strcmp(&(ts[i].time[j]),"11:35")) || !(strcmp(&(ts[i].time[j]),"12:00")))
		{
			ts_new[i].time[j]=3;
		}
		if(!(strcmp(&(ts[i].time[j]),"2:00")) || !(strcmp(&(ts[i].time[j]),"2:30")))
		{
			ts_new[i].time[j]=4;
		}
		if(!(strcmp(&(ts[i].time[j]),"3:30")) || !(strcmp(&(ts[i].time[j]),"4:00")))
		{
			ts_new[i].time[j]=5;
		}
		if(!(strcmp(&(ts[i].time[j]),"5:00")) || !(strcmp(&(ts[i].time[j]),"5:30")))
		{
			ts_new[i].time[j]=6;
		}
		if(!(strcmp(&(ts[i].time[j]),"6:30")) || !(strcmp(&(ts[i].time[j]),"7:00")))
		{
			ts_new[i].time[j]=7;
		}
	}
  }
}

/*****************taking input from course file********************************/	
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
     sort_priority((m),c);
	 sort((m),c);  
     
/**************taing input for room file********************/     
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
        	printf("%s %d \n",r[i].room_no,r[i].capacity);
		}
 
k=0;
for(i=0;i<x;i++){
	for(j=0;j<(room);j++)
	{
		//H[k].slt.slot=s[i].slot;
		strcpy(H[k].slt.slot,ts_new[i].time_slot);
		strcpy(H[k].cl.room_no,r[j].room_no);
		//H[k].cl.room_no=r[j].room_no;
		H[k].cl.capacity=r[j].capacity;
		k++;
	}
} 

for(i=lab_room;i<x;i++){
	for(j=room;j<(room+lab_room);j++)
	{
		strcpy(H[k].slt.slot,ts_new[i].time_slot);
		strcpy(H[k].cl.room_no,r[j].room_no);
		//H[k].cl.room_no=r[j].room_no;
		H[k].cl.capacity=r[j].capacity;
		k++;
	}
}


/****************** all slots combine with room no.************************/  
 
 for(i=0;i<(m);i++)
 {
 	for(j=0;j<slot_room;j++)
 	{
 		graph[i][j]=0;
	 }
 }
 
output_graph = fopen("output_graph.txt", "r");

    if (output_graph == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        for(i=0;i<max;i++)
        {
        	fscanf(output_graph,"%d \t %d",&M[i].first_vertex,&M[i].second_vertex);
		}
        fclose(output_graph);
    }
  
  
//printf("/********************************1st sem time table********************************/\n"); 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		graph[i][j]=0;
	}
}

for(i=0;i<(m);i++)
{
		graph[(M[i].first_vertex)-1][(M[i].second_vertex)-value]=1;
}

for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==1)
		{
			printf("%s---->(%s %s)",c[i].course,H[j].slt.slot,H[j].cl.room_no);
			printf("\n");
		}
	}
	}
}
printf("!!! Time table generated successfully !!!");
mat[0][0]="Day";
mat[0][1]="8:30-9:25";mat[0][2]="9:30-10:25";mat[0][3]="10:35-11:30";mat[0][4]="11:35-12:30";
mat[0][5]="2:00-3:25";mat[0][6]="3:30-4:55";mat[0][7]="5:00-6:25";mat[0][8]="6:30-7:55";
mat[1][0]="Monday";mat[2][0]="Tuesday";mat[3][0]="Wednesday";mat[4][0]="Thursday";mat[5][0]="Friday";


 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

/**********************************matrix filling************************************/
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==1)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
			   strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}	
			}
		}
	}
	}
}
 
 /******************************printing output in CSfirst sem file********************************************/
 csIsem = fopen("csIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(csIsem,"%s",mat[i][0]);
			for(j=1;j<9;j++)
 	        {
 		       fprintf(csIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csIsem,"\n\n",mat[i][j]);
		}
    fclose(csIsem); 
}
 
/******************************printing output in CSIII sem file********************************************/
 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==2)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
			if(local<4)
			{
			strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
			    for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}	
			}
		}
	}
	}
}
 
 csIIIsem = fopen("csIIIsem.txt", "w");

    if (csIIIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    	    fprintf(csIIIsem,"%s",mat[i][0]);
			for(j=1;j<9;j++)
 	        {
 		       fprintf(csIIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csIIIsem,"\n\n",mat[i][j]);
		}
    fclose(csIIIsem); 
}
 
 /******************************printing output in MEIII sem file********************************************/
 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==3)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
			if(local<4)
			{
			    strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
			  strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
			   
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}	
			}
		}
	}
	}
}
 
 meIIIsem = fopen("meIIIsem.txt", "w");

    if (meIIIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(meIIIsem,"%s",mat[i][0]);
    		for(j=1;j<9;j++)
 	        {
 		       fprintf(meIIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(meIIIsem,"\n\n",mat[i][j]);
		}
    fclose(meIIIsem); 
}
 
  /******************************printing output in EEIII sem file********************************************/
 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==4)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
			    strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}	
			}
		}
	}
	}
}
 
 eeIIIsem = fopen("eeIIIsem.txt", "w");

    if (eeIIIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(eeIIIsem,"%s",mat[i][0]);
    		for(j=1;j<9;j++)
 	        {
 		       fprintf(eeIIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(eeIIIsem,"\n\n",mat[i][j]);
		}
    fclose(eeIIIsem); 
}
 
  /******************************printing output in CSV sem file********************************************/
 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==5)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
			if(local<4)
			{
			   strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
			    strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}	
			}
		}
	}
	}
}
 
 csVsem = fopen("csVsem.txt", "w");

    if (csVsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(csVsem,"%s",mat[i][0]);
    		for(j=1;j<9;j++)
 	        {
 		       fprintf(csVsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csVsem,"\n\n",mat[i][j]);
		}
    fclose(csVsem); 
} 

  /******************************printing output in MEV sem file********************************************/
 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==6)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
	  	        for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}	
			}
		}
	}
	}
}
 
 meVsem = fopen("meVsem.txt", "w");

    if (meVsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(meVsem,"%s",mat[i][0]);
    		for(j=1;j<9;j++)
 	        {
 		       fprintf(meVsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(meVsem,"\n\n",mat[i][j]);
		}
    fclose(meVsem); 
} 
 
  /******************************printing output in EEV sem file********************************************/
 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==7)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
			    strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}	
			}
		}
	}
	}
}
 
 eeVsem = fopen("eeVsem.txt", "w");

    if (eeVsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(eeVsem,"%s",mat[i][0]);
    		for(j=1;j<9;j++)
 	        {
 		       fprintf(eeVsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(eeVsem,"\n\n",mat[i][j]);
		}
    fclose(eeVsem); 
}   
 /******************************printing output in CSVII sem file********************************************/
 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==8)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
			    strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}	
			}
		}
	}
	}
}
 
 csVIIsem = fopen("csVIIsem.txt", "w");

    if (csVIIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(csVIIsem,"%s",mat[i][0]);
    		for(j=1;j<9;j++)
 	        {
 		       fprintf(csVIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csVIIsem,"\n\n",mat[i][j]);
		}
    fclose(csVIIsem); 
}

/******************************printing output in MEVII sem file********************************************/
 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==9)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
			    strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}	
			}
		}
	}
	}
}
 
 meVIIsem = fopen("meVIIsem.txt", "w");

    if (meVIIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(meVIIsem,"%s",mat[i][0]);
    		for(j=1;j<9;j++)
 	        {
 		       fprintf(meVIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(meVIIsem,"\n\n",mat[i][j]);
		}
    fclose(meVIIsem); 
}

/******************************printing output in EEVII sem file********************************************/
 for(i=1;i<6;i++)
 {
 	for(j=1;j<9;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==10)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<3;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
			    strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
		}
	}
	}
}
 
 eeVIIsem = fopen("eeVIIsem.txt", "w");

    if (eeVIIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(eeVIIsem,"%s",mat[i][0]);	
    		for(j=1;j<9;j++)
 	        {
 		       fprintf(eeVIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(eeVIIsem,"\n\n",mat[i][j]);
		}
    fclose(eeVIIsem); 
}


return 0;
}
