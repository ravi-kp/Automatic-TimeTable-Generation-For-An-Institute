#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 500
#define colors 3
#define value 100
#define size 50
#define room 4
#define lab_room 2
#define lab_slot 8
#define time_slt 15
#define row 20
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
	char *time_slot;
	int day[3];
	int time[3];
};
struct node8
{
	char temp_array[size];
};
 
 void sort(int n,struct node1 x[]) 
 {   int i,j;
    struct node1 temp;
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
 
int main()
{
 int i,j,k,m,y,col,flag,temp,l,ch=0,edge=0,loop,local;
 struct node1 c[max];
 struct node2 r[max];
 struct node3 s[max];
 struct node4 H[max];
 int graph[value][max];
 struct node6 M[max];
 struct node7 ts[time_slt];
 struct node8 array[max];
 int slot_room,slot_lab,x=15;
 char* mat[row][row];
 char tslot[size];
 slot_room=x*room;
 slot_lab=lab_room*lab_slot;
 FILE *room_file,*course_file,*slot_file,*input_graph,*output_graph;
 FILE *csIsem,*csIIIsem,*meIIIsem,*eeIIIsem,*csVsem,*meVsem,*eeVsem,*csVIIsem,*meVIIsem,*eeVIIsem;
  
 /**************************** taking inputs from file for courses and rooms*********************/
    slot_file = fopen("slot_file.txt", "r");

    if (slot_file == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        for(i=0;i<x;i++)
        {
        	fscanf(slot_file,"%s",&s[i].slot);
		}
        fclose(slot_file);
    }
    
	
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
		}
        fclose(course_file);
    }
     sort((m),c);  
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
		strcpy(H[k].slt.slot,s[i].slot);
		strcpy(H[k].cl.room_no,r[j].room_no);
		//H[k].cl.room_no=r[j].room_no;
		H[k].cl.capacity=r[j].capacity;
		k++;
	}
} 

for(i=lab_room;i<x;i++){
	for(j=room;j<(room+lab_room);j++)
	{
		strcpy(H[k].slt.slot,s[i].slot);
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

mat[0][0]="Courese_No";
mat[0][1]="Course_Name";mat[0][2]="Division";mat[0][3]="DEpartment";mat[0][4]="Lec_Slot";
mat[0][5]="Lec_Venue";mat[0][6]="Tut_Slot";mat[0][7]="Tut_Venue";mat[0][8]="Instructor";

 for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 }
/**********************************matrix filling************************************/ 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==1)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="CSE";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in CSfirst sem file********************************************/
 csIsem = fopen("newCSIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}




for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 } 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==2)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="CSE";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in CSIV sem file********************************************/
 csIsem = fopen("newCSIVsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
 /******************************printing output in MEIV sem file********************************************/
for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 } 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==3)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="ME";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in MEIV sem file********************************************/
 csIsem = fopen("newMEIVsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
 
  /******************************printing output in EEIV sem file********************************************/
 for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 } 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==4)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="EE";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in EEIV sem file********************************************/
 csIsem = fopen("newEEIVsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
 
  /******************************printing output in CSVI sem file********************************************/

for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 } 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==5)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="CSE";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in CSVI sem file********************************************/
 csIsem = fopen("newCSVIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}

  /******************************printing output in MEV sem file********************************************/
 for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 } 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==6)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="ME";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in MEVI sem file********************************************/
 csIsem = fopen("newMEVIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
 
  /******************************printing output in EEVI sem file********************************************/
 for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 } 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==7)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="EE";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in EEVI sem file********************************************/
 csIsem = fopen("newEEVIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
 /******************************printing output in CSVIII sem file********************************************/
 for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 } 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==8)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="CSE";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in CSVIII sem file********************************************/
 csIsem = fopen("newCSVIIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}
/******************************printing output in MEVII sem file********************************************/
for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 } 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==9)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="ME";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in MEVIII sem file********************************************/
 csIsem = fopen("newMEVIIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}

/******************************printing output in EEVII sem file********************************************/
for(i=1;i<row;i++)
 {
 	for(j=0;j<row;j++)
 	{
 		mat[i][j]=" ";
	 }
 } 
k=1;
for(i=0;i<(m);i++)
{  
	for(j=0;j<(slot_room+slot_lab);j++)
	{
		for(local=0;local<colors;local++)
		{
		if(graph[i][j]==1 && c[i].color[local]==10)
		{  
			mat[k][1]=c[i].course;
			mat[k][3]="EE";
			mat[k][4]=H[j].slt.slot;
			mat[k][5]=H[j].cl.room_no;
			mat[k][6]=H[j].slt.slot;
			mat[k][7]=H[j].cl.room_no;
			k++;
				
	}
	}
}
}

for(i=0;i<row;i++)
{
	for(j=0;j<row;j++)
	{
		printf("%s\t",mat[i][j]);
	}
	printf("\n");
}



 /******************************printing output in EEVIII sem file********************************************/
 csIsem = fopen("newEEVIIIsem.txt", "w");

    if (csIsem == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
	for(i=0;i<row;i++)
   {
	for(j=0;j<row;j++)
	{
		fprintf(csIsem," %s",mat[i][j]);
	}
	fprintf(csIsem,"\n");
}	
    fclose(csIsem); 
}

return 0;
}
