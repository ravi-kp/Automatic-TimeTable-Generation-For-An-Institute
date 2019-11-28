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
#define matrix_row 6
#define matrix_col 9
#define slot_size 3
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

struct Input_Room{
    char *room_no[size];
	int capacity;
};

struct Slot_Name{
	char *slot[size];
};
struct Slot_Room_Combination
{
	struct Input_Room cl;
	struct Slot_Name slt;
};

struct Color_Checking
{
	char tslot[size];
	int tcolor[colors];
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
struct Timetable_Filling
{
	char temp_array[value];
};
  struct Day_Time_Node
 {
 	char time_slot[size];
	int  day[slot_size];
	int time[slot_size];
 };
 
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
 struct Input_Room r[max];
 struct Slot_Name s[max];
 struct Slot_Room_Combination H[max];
 int graph[value][max];
 struct Graph_Vertext M[max];
 struct Slot_From_Database ts[time_slt];
 struct Timetable_Filling array[max];
 struct Day_Time_Node ts_new[max];
 int slot_room,slot_lab,number_of_slot=15;
 char* mat[matrix_row][matrix_col];
 char* mat_sec[time_slt][matrix_col];
 char* room_occupancy[(room+lab_room)+1][slot_size];
 char tslot[size];
 char *temp_stringL1[size],*temp_stringL2[size],*temp_stringLX[size],*temp_stringL3[size],*temp_stringL4[size],*temp_stringL5[size],*temp_stringL6[size];
 char *temp_string12[size],*temp_string13[size],*temp_string14[size],*temp_string15[size];
 char *temp_slot_occupied[size];
 char *temp_row_first[size];
 slot_room=number_of_slot*room;
 slot_lab=lab_room*lab_slot;
 FILE *room_file,*course_file,*slot_file,*input_graph,*output_graph;
 FILE *csIsem,*csIIIsem,*meIIIsem,*eeIIIsem,*csVsem,*meVsem,*eeVsem,*csVIIsem,*meVIIsem,*eeVIIsem;
 FILE *csIIsem,*csIVsem,*meIVsem,*eeIVsem,*csVIsem,*meVIsem,*eeVIsem,*csVIIIsem,*meVIIIsem,*eeVIIIsem;
 FILE *room_occupancy_file;
 enum color_code{ csIsem_color=1,csIIIsem_color=2,meIIIsem_color=3,eeIIIsem_color=4,csVsem_color=5,
                  meVsem_color=6,eeVsem_color=7,csVIIsem_color=8,meVIIsem_color=9,eeVIIsem_color=10,
                  csIIsem_color=11,csIVsem_color=12,meIVsem_color=13,eeIVsem_color=14,csVIsem_color=15,
                  meVIsem_color=16,eeVIsem_color=17,csVIIIsem_color=18,meVIIIsem_color=19,eeVIIIsem_color=20
                };
 /****taking slot as input from database file************************/
 slot_file = fopen("slot_fromdb.txt", "r");

    if (slot_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
        for(i=0;i<(number_of_slot+lab_slot);i++)
        {
        	fscanf(slot_file,"%s ",&ts[i].time_slot);
        	if(i<4)
        	{
			
        	for(j=0;j<slot_size;j++)
        	{
        	fscanf(slot_file,"%s ",&ts[i].day[j]);
			}
			for(j=0;j<slot_size;j++)
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







/*for(i=0;i<(number_of_slot+lab_slot);i++)
        {
        	printf("%s ",&ts[i].time_slot);
        	if(i<4)
        	{
			
        	for(j=0;j<3;j++)
        	{
        	printf("%s ",&ts[i].day[j]);
			}
			for(j=0;j<3;j++)
        	{
        	printf("%s ",&ts[i].time[j]);	
			}
	     }
	    else
	     {
	     	for(j=0;j<2;j++)
        	{
        	printf("%s ",&ts[i].day[j]);	
			}
			for(j=0;j<2;j++)
        	{
        	printf("%s ",&ts[i].time[j]);	
			}
			
		
		 }
		 	printf("\n");
		}  */

    
for(i=0;i<(number_of_slot+lab_slot);i++)
{
	if(i<4)
	{
		strcpy(ts_new[i].time_slot,ts[i].time_slot);
		for(j=0;j<slot_size;j++)
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
	for(j=0;j<slot_size;j++)
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
			ts_new[i].time[j]=matrix_row;
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
    course_file = fopen("course_file1.txt", "r");

    if (course_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
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
    
     sort_priority((m),c);
    // sort_lab((m),c);
	 sort((m),c);  
    
/*	  for(i=0;i<m;i++)
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
	
	
	 
/**************taing input for room file***********************************************/     
 room_file = fopen("room_file.txt", "r");

    if (room_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
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
for(i=0;i<number_of_slot;i++){
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

for(i=number_of_slot;i<(number_of_slot+lab_slot);i++){
	for(j=room;j<(room+lab_room);j++)
	{
		//H[k].slt.slot=s[i].slot;
		strcpy(H[k].slt.slot,ts_new[i].time_slot);
		strcpy(H[k].cl.room_no,r[j].room_no);
		//H[k].cl.room_no=r[j].room_no;
		H[k].cl.capacity=r[j].capacity;
		k++;
	}
}
/*for(i=0;i<(slot_room+slot_lab);i++)
{
	printf("%s %s",H[i].slt.slot,H[i].cl.room_no);
	printf("\n");
} *
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
        // // // // printf("Can't open file for reading.\n");
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

printf("!!! Time table generated successfully !!!");
mat[0][0]="Day";
mat[0][1]="8:30-9:25";mat[0][2]="9:30-10:25";mat[0][3]="10:35-11:30";mat[0][4]="11:35-12:30";
mat[0][5]="2:00-3:25";mat[0][matrix_row]="3:30-4:55";mat[0][7]="5:00-6:25";mat[0][8]="6:30-7:55";
mat[1][0]="Monday";mat[2][0]="Tuesday";mat[3][0]="Wednesday";mat[4][0]="Thursday";mat[5][0]="Friday";


 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
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
		
		if(graph[i][j]==1 && c[i].color[k]==csIsem_color)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts_new[l].time_slot))
				local=l;
			}
		//	printf("%d\n",local);
			if(local<4)
			{
				strcpy(array[i].temp_array,c[i].course);
				strcat(array[i].temp_array,",");
				strcat(array[i].temp_array,H[j].cl.room_no);
				for(loop=0;loop<slot_size;loop++)
				{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=array[i].temp_array;
				}
			}
			else
			{
			   
			   strcpy(array[i].temp_array,c[i].course);
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			   if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			      if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   
			   
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
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
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(csIsem,"%s",mat[i][0]);
			for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(csIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csIsem,"\n\n",mat[i][j]);
		}
    fclose(csIsem); 
}
 
/******************************creating timetable for in CSIII sem file********************************************/
 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
 
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==csIIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			        if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				   
					 if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
				}	
			}
		}
	}
	}
}
 
 csIIIsem = fopen("csIIIsem.txt", "w");

    if (csIIIsem == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    	    fprintf(csIIIsem,"%s",mat[i][0]);
			for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(csIIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csIIIsem,"\n\n",mat[i][j]);
		}
    fclose(csIIIsem); 
}
 
 /******************************creating timetable for  MEIII sem file********************************************/
 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==meIIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 meIIIsem = fopen("meIIIsem.txt", "w");

    if (meIIIsem == NULL)
    {
       // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(meIIIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(meIIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(meIIIsem,"\n\n",mat[i][j]);
		}
    fclose(meIIIsem); 
}
 
  /******************************creating timetable for EEIII sem file********************************************/
 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
  strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==eeIIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				   
				 if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }	
				}	
			}
		}
	}
	}
}
 
 eeIIIsem = fopen("eeIIIsem.txt", "w");

    if (eeIIIsem == NULL)
    {
       // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(eeIIIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(eeIIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(eeIIIsem,"\n\n",mat[i][j]);
		}
    fclose(eeIIIsem); 
}
 
  /******************************creating timetable for CSV sem file********************************************/
 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
  strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==csVsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			  // strcpy(temp_string,array[i].temp_array);
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   
			   }
			   
			      if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				   if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
				}	
			}
		}
	}
	}
}
 
 csVsem = fopen("csVsem.txt", "w");

    if (csVsem == NULL)
    {
       // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(csVsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(csVsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csVsem,"\n\n",mat[i][j]);
		}
    fclose(csVsem); 
} 

  /******************************creating time table for MEV sem file********************************************/
 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
  strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==meVsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			   if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			        if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 meVsem = fopen("meVsem.txt", "w");

    if (meVsem == NULL)
    {
       // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(meVsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(meVsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(meVsem,"\n\n",mat[i][j]);
		}
    fclose(meVsem); 
} 
 
  /******************************creating timetable for EEV sem file********************************************/
 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
  strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==eeVsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			  if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			         if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 eeVsem = fopen("eeVsem.txt", "w");

    if (eeVsem == NULL)
    {
      //  // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(eeVsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(eeVsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(eeVsem,"\n\n",mat[i][j]);
		}
    fclose(eeVsem); 
}   
 /******************************creating time table for CSVII sem file********************************************/
 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
  strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==csVIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			        if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 csVIIsem = fopen("csVIIsem.txt", "w");

    if (csVIIsem == NULL)
    {
       // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(csVIIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(csVIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csVIIsem,"\n\n",mat[i][j]);
		}
    fclose(csVIIsem); 
}

/******************************printing output in MEVII sem file********************************************/
 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
  strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==meVIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			         if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 meVIIsem = fopen("meVIIsem.txt", "w");

    if (meVIIsem == NULL)
    {
       // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(meVIIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(meVIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(meVIIsem,"\n\n",mat[i][j]);
		}
    fclose(meVIIsem); 
}

/******************************creating timetable for EEVII sem file********************************************/
 for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }
 
  strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==eeVIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			 if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			         if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
				   
					
				}
			}
		}
	}
	}
}
 
 eeVIIsem = fopen("eeVIIsem.txt", "w");

    if (eeVIIsem == NULL)
    {
        //// // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(eeVIIsem,"%s",mat[i][0]);	
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(eeVIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(eeVIIsem,"\n\n",mat[i][j]);
		}
    fclose(eeVIIsem); 
}

/**********************************************cs II sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==csIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 csIIsem = fopen("csIIsem.txt", "w");

    if (csIIsem == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(csIIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(csIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csIIsem,"\n\n",mat[i][j]);
		}
    fclose(csIIsem); 
}

/**********************************************cs IV sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==csIVsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 csIVsem = fopen("csIVsem.txt", "w");

    if (csIVsem == NULL)
    {
        // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(csIVsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(csIVsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csIVsem,"\n\n",mat[i][j]);
		}
    fclose(csIVsem); 
}
/**********************************************me IV sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==meIVsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 meIVsem = fopen("meIVsem.txt", "w");

    if (meIVsem == NULL)
    {
        // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(meIVsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(meIVsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(meIVsem,"\n\n",mat[i][j]);
		}
    fclose(meIVsem); 
}

/**********************************************ee IV sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==eeIVsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 eeIVsem = fopen("eeIVsem.txt", "w");

    if (eeIVsem == NULL)
    {
        // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(eeIVsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(eeIVsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(eeIVsem,"\n\n",mat[i][j]);
		}
    fclose(eeIVsem); 
}

/**********************************************cs VI sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==csVIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 csVIsem = fopen("csVIsem.txt", "w");

    if (csVIsem == NULL)
    {
        // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(csVIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(csVIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csVIsem,"\n\n",mat[i][j]);
		}
    fclose(csVIsem); 
}

/**********************************************me VI sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==meVIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 meVIsem = fopen("meVIsem.txt", "w");

    if (meVIsem == NULL)
    {
        // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(meVIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(meVIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(meVIsem,"\n\n",mat[i][j]);
		}
    fclose(meVIsem); 
}

/**********************************************ee VI sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==eeVIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 eeVIsem = fopen("eeVIsem.txt", "w");

    if (eeVIsem == NULL)
    {
        // // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(eeVIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(eeVIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(eeVIsem,"\n\n",mat[i][j]);
		}
    fclose(eeVIsem); 
}

/**********************************************cs VIII sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==csVIIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 csVIIIsem = fopen("csVIIIsem.txt", "w");

    if (csVIIIsem == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(csVIIIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(csVIIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(csVIIIsem,"\n\n",mat[i][j]);
		}
    fclose(csVIIIsem); 
}

/**********************************************me VIII sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==meVIIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 meVIIIsem = fopen("meVIIIsem.txt", "w");

    if (meVIIIsem == NULL)
    {
        // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(meVIIIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(meVIIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(meVIIIsem,"\n\n",mat[i][j]);
		}
    fclose(meVIIIsem); 
}

/**********************************************ee VIII sem time  table **************************************************/
for(i=1;i<matrix_row;i++)
 {
 	for(j=1;j<matrix_col;j++)
 	{
 		mat[i][j]=".........";
	 }
 }

 strcpy(temp_stringL1,"");
 strcpy(temp_stringL2,"");
 strcpy(temp_stringLX,"");
 strcpy(temp_stringL3,"");
 strcpy(temp_stringL4,"");
 strcpy(temp_stringL5,"");
 strcpy(temp_stringL6,"");
  
for(i=0;i<(m);i++)
{
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(k=0;k<colors;k++)
		{
		
		if(graph[i][j]==1 && c[i].color[k]==eeVIIIsem_color)
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
			   strcat(array[i].temp_array,c[i].division);
			   strcat(array[i].temp_array,",");
			   strcat(array[i].temp_array,H[j].cl.room_no);
			   strcat(array[i].temp_array,"::");
			    if(!strcmp(H[j].slt.slot,"L1"))
			   {
			   	strcat(temp_stringL1,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L2"))
			   {
			   	strcat(temp_stringL2,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"LX"))
			   {
			   	strcat(temp_stringLX,array[i].temp_array);
			    
			   }
			   if(!strcmp(H[j].slt.slot,"L3"))
			   {
			   	strcat(temp_stringL3,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L4"))
			   {
			   	strcat(temp_stringL4,array[i].temp_array);
			   
			   }
			   if(!strcmp(H[j].slt.slot,"L5"))
			   {
			   	strcat(temp_stringL5,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"L6"))
			   {
			   	strcat(temp_stringL6,array[i].temp_array);
			   	
			   }
			   
			       if(!strcmp(H[j].slt.slot,"S12"))
			   {
			   	strcpy(temp_string12,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S13"))
			   {
			   	strcpy(temp_string13,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S14"))
			   {
			   	strcpy(temp_string14,array[i].temp_array);
			   	
			   }
			   if(!strcmp(H[j].slt.slot,"S15"))
			   {
			   	strcpy(temp_string15,array[i].temp_array);
			   	
			   }
			   for(loop=0;loop<2;loop++)
				{
					if(!strcmp(ts_new[local].time_slot,"L1"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL1;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L2"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL2;
				   }
				   if(!strcmp(ts_new[local].time_slot,"LX"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringLX;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L3"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL3;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L4"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL4;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L5"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL5;
				   }
				   if(!strcmp(ts_new[local].time_slot,"L6"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_stringL6;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S12"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string12;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S13"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string13;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S14"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string14;
				    }
				    if(!strcmp(ts_new[local].time_slot,"S15"))
					{
					mat[(ts_new[local].day[loop])+1][(ts_new[local].time[loop])+1]=temp_string15;
				    }
					
				}	
			}
		}
	}
	}
}
 
 eeVIIIsem = fopen("eeVIIIsem.txt", "w");

    if (eeVIIIsem == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<matrix_row;i++)
    	{
    		fprintf(eeVIIIsem,"%s",mat[i][0]);
    		for(j=1;j<matrix_col;j++)
 	        {
 		       fprintf(eeVIIIsem," %s",mat[i][j]);
 		            
	           }
	           fprintf(eeVIIIsem,"\n\n",mat[i][j]);
		}
    fclose(eeVIIIsem); 
}
 /************************************** generate Room occupancy file*****************************************************/
room_occupancy[0][0]="Room_No.";room_occupancy[0][1]="Slot_occupied";room_occupancy[0][2]="Slot_Free ";
room_occupancy_file = fopen("room_occupancy_file.txt", "w");

if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
   fprintf(room_occupancy_file,"%s %s %s ",room_occupancy[0][0],room_occupancy[0][1],room_occupancy[0][2]);
   fprintf(room_occupancy_file,"\n");
  }
  

 
    if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
    fprintf(room_occupancy_file,"%s ","21");	
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"21")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
                     fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
  
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
   fprintf(room_occupancy_file,"%s ","22");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"22")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
                     fprintf(room_occupancy_file,","); 
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
    fprintf(room_occupancy_file,"%s ","23");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"23")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
                     fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
    fprintf(room_occupancy_file,"%s ","115");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"115")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
                     fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
    fprintf(room_occupancy_file,"%s ","117");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"117")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
  fprintf(room_occupancy_file,"%s ","119");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"119")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
    fprintf(room_occupancy_file,"%s ","203");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"203")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
    fprintf(room_occupancy_file,"%s ","207");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"207")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
  fprintf(room_occupancy_file,"%s ","210");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"210")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
   fprintf(room_occupancy_file,"%s ","211");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"211")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
   fprintf(room_occupancy_file,"%s ","215");
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"215")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
   if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Chemistry_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Chemistry_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}

if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Mech_Workshop");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Mech_Workshop")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}

if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Eng_Drawing_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Eng_Drawing_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}

if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Physics_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Physics_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Computer_Lab(Ground_Floor)");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Computer_Lab(Ground_Floor)")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Computer_LabII");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Computer_LabII")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Micro_Electronics_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Micro_Electronics_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}

if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Fluid_Mechanics");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Fluid_Mechanics")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Micro_Electronics_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Micro_Electronics_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","DSP/PE_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"DSP/PE_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Heat_Transfer_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Heat_Transfer_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","SOM_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"SOM_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","KDOM_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"KDOM_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Measurement_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Measurement_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Manufacturing_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Manufacturing_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}
if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Machine_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Machine_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}

if (room_occupancy_file == NULL)
    {
        // // // // printf("Can't open file for reading.\n");
    }
    else
    {
	fprintf(room_occupancy_file,"%s ","Solid_Mechanics_Lab");  
      for(i=0;i<m;i++)
     {
          for(j=0;j<(slot_room+slot_lab);j++)
          {
            if(graph[i][j]==1)
             {
   	          if(!(strcmp(H[j].cl.room_no,"Solid_Mechanics_Lab")))
   	       {
   	  	     fprintf(room_occupancy_file,"%s",H[j].slt.slot);
fprintf(room_occupancy_file,",");
   	  	     
		   }
		  
	} 
}
}
fprintf(room_occupancy_file,"\n");
}

return 0;
}
