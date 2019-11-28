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
#define other_fromat_no_of_row 19
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
 char* mat_sec[other_fromat_no_of_row][matrix_col];
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

mat_sec[0][0]="Courese_No";
mat_sec[0][1]="Course_Name";mat_sec[0][2]="Division";mat_sec[0][3]="Department";mat_sec[0][4]="Lec_Slot";
mat_sec[0][5]="Lec_Venue";mat_sec[0][6]="Tut_Slot";mat_sec[0][7]="Tut_Venue";mat_sec[0][8]="Instructor";

 /******************************printing output in new format CSfirst sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==csIsem_color)
		{  
                        mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="CSE,ME,EE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

 csIsem = fopen("newCSIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<other_fromat_no_of_row;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format CSIIsem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==csIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="CSE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newCSIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<other_fromat_no_of_row;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format CSIII sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==csIIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="CSE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

 csIsem = fopen("newCSIIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format CSIV sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==csIVsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="CSE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

 csIsem = fopen("newCSIVsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format CSV sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==csVsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="CSE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newCSVsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<lab_room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format CSVI sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==csVIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="CSE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newCSVIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<lab_room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format CSVII sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==csVIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="CSE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newCSVIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<matrix_col;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format CSVIII sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==csVIIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="CSE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newCSVIIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<matrix_col;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}

/******************************printing output in new format meIII sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==meIIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="ME";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newMEIIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format meIV sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==meIVsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="ME";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newMEIVsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format meV sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==meVsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="ME";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newMEVsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<lab_room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format meVI sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==meVIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="ME";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newMEVIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<lab_room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format meVII sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==meVIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="ME";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newMEVIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format meVIII sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==meVIIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="ME";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newMEVIIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format eeIII sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==eeIIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="EE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newEEIIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}/******************************printing output in new format eeIV sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==eeIVsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="EE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newEEIVsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<matrix_col;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format eeV sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==eeVsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="EE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newEEVsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<lab_room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format eeVI sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==eeVIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="EE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newEEVIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<lab_room;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format eeVII sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==eeVIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="EE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newEEVIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<matrix_col;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in new format eeVIII sem file********************************************/
 for(i=1;i<time_slt;i++)
 {
 	for(j=0;j<matrix_col;j++)
 	{
 		mat_sec[i][j]="";
	 }
 }
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==eeVIIIsem_color)
		{  
			mat_sec[k][1]=c[i].course;
			mat_sec[k][3]="EE";
			mat_sec[k][4]=H[j].slt.slot;
			mat_sec[k][5]=H[j].cl.room_no;
			mat_sec[k][6]=H[j].slt.slot;
			mat_sec[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}


 csIsem = fopen("newEEVIIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<matrix_col;i++)
   {
	for(j=0;j<matrix_col;j++)
	{
		fprintf(csIsem,"%s ",mat_sec[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
return 0;
}

