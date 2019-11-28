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
#define all_sem 10
#define col_for_occupancy 4
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
 int location[time_slt];
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
 char* mat[all_sem][col_for_occupancy];
 char* mat_sec[time_slt][matrix_col];
 char* room_occupancy[(room+lab_room)+1][slot_size];
 char tslot[size];
 char temp_string[time_slt][size],temp_string_sec[time_slt][size],temp_string_third[time_slt][size],temp_string_fourth[time_slt][size],temp_string_fifth[time_slt][size];
 char temp_string_sixth[time_slt][size],temp_string_seventh[time_slt][size],temp_string_eight[time_slt][size],temp_string_nine[time_slt][size],temp_string_tenth[time_slt][size];
 char *temp_slot_occupied[size];
 char *temp_row_first[size];
 slot_room=number_of_slot*room;
 slot_lab=lab_room*lab_slot;
 FILE *room_file,*course_file,*slot_file,*input_graph,*output_graph;
 FILE *csIsem,*csIIIsem,*meIIIsem,*eeIIIsem,*csVsem,*meVsem,*eeVsem,*csVIIsem,*meVIIsem,*eeVIIsem;
 FILE *csIIsem,*csIVsem,*meIVsem,*eeIVsem,*csVIsem,*meVIsem,*eeVIsem,*csVIIIsem,*meVIIIsem,*eeVIIIsem;
 FILE *student_occupancy_file;
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
/****************************************************check clashes between courses**************************************/  
for(i=0;i<m;i++)
{
	for(k=i+1;k<m;k++)
		{
				for(loop=0;loop<colors;loop++)
				{
				if((c[(M[i].first_vertex-1)].color[loop] !=0)&& (c[(M[i].first_vertex-1)].color[loop] == c[(M[k].first_vertex-1)].color[loop]))
				{
					if(!strcmp(H[(M[i].second_vertex-value)].slt.slot,H[(M[k].second_vertex-value)].slt.slot) && !strcmp((c[(M[i].first_vertex-1)].division),c[(M[k].first_vertex-1)].division))
					{
						printf("%s %s",c[(M[i].first_vertex-1)].course,H[(M[i].second_vertex-value)].slt.slot);
						printf("\t");
						printf("%s %s",c[(M[k].first_vertex-1)].course,H[(M[k].second_vertex-value)].slt.slot);
						printf("here is clashes");
						printf("\n");
					}
				}
		      }
			}
		}
/************************************************check clashes between rooms**************************************/
for(i=0;i<m;i++)
{
	for(k=i+1;k<m;k++)
		{
				if(!strcmp(H[(M[i].second_vertex-value)].slt.slot,H[(M[k].second_vertex-value)].slt.slot))
					{
						if(!strcmp(H[(M[i].second_vertex-value)].cl.room_no,H[(M[k].second_vertex-value)].cl.room_no))
						{
							printf("clash occurs at room no: %s",H[(M[i].second_vertex-value)].cl.room_no);
						}
					}
				}
		      }	
printf("Time table generated is clashfree");

return 0;
}

