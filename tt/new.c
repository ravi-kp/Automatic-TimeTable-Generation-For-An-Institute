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

// check weather slot is taken by same semester 
int find(struct node1 c[], struct node4 H[], int i ,int j,int ch)
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
 int slot_room,slot_lab,x=15;
 char* mat[6][9];
 char tslot[size];
 slot_room=x*room;
 slot_lab=lab_room*lab_slot;
 FILE *room_file,*course_file,*slot_file,*input_graph,*output_graph;
 FILE *csIsem,*csIIIsem,*meIIIsem,*eeIIIsem,*csVsem,*meVsem,*eeVsem,*csVIIsem,*meVIIsem,*eeVIIsem;
 /******************************defining slots ***************************************************/
 ts[0].time_slot="S1";
 ts[0].day[0]=0;ts[0].time[0]=0;
 ts[0].day[1]=1;ts[0].time[1]=1;
 ts[0].day[2]=3;ts[0].time[2]=2;
 
 ts[1].time_slot="S2";
 ts[1].day[0]=0;ts[1].time[0]=1;
 ts[1].day[1]=1;ts[1].time[1]=2;
 ts[1].day[2]=3;ts[1].time[2]=3;
 
 ts[2].time_slot="S3";
 ts[2].day[0]=0;ts[2].time[0]=2;
 ts[2].day[1]=1;ts[2].time[1]=3;
 ts[2].day[2]=3;ts[2].time[2]=0; 
 
 ts[3].time_slot="S4";
 ts[3].day[0]=0;ts[3].time[0]=3;
 ts[3].day[1]=1;ts[3].time[1]=0;
 ts[3].day[2]=3;ts[3].time[2]=1; 
 
 ts[4].time_slot="S5";
 ts[4].day[0]=2;ts[4].time[0]=2;
 ts[4].day[1]=4;ts[4].time[1]=3;
 
 ts[5].time_slot="S6";
 ts[5].day[0]=2;ts[5].time[0]=3;
 ts[5].day[1]=4;ts[5].time[1]=2;
 
 ts[6].time_slot="S7";
 ts[6].day[0]=2;ts[6].time[0]=0;
 ts[6].day[1]=4;ts[6].time[1]=0;
 
 ts[7].time_slot="S8";
 ts[7].day[0]=0;ts[7].time[0]=4;
 ts[7].day[1]=3;ts[7].time[1]=4;
 
 ts[8].time_slot="S9";
 ts[8].day[0]=0;ts[8].time[0]=5;
 ts[8].day[1]=3;ts[8].time[1]=5;
 
 ts[9].time_slot="S10";
 ts[9].day[0]=1;ts[9].time[0]=4;
 ts[9].day[1]=4;ts[9].time[1]=4;
 
 ts[10].time_slot="S11";
 ts[10].day[0]=1;ts[10].time[0]=5;
 ts[10].day[1]=4;ts[10].time[1]=5;
 
 ts[11].time_slot="S12";
 ts[11].day[0]=0;ts[11].time[0]=6;
 ts[11].day[1]=3;ts[11].time[1]=6;
 
 ts[12].time_slot="S13";
 ts[12].day[0]=0;ts[12].time[0]=7;
 ts[12].day[1]=3;ts[12].time[1]=7;
 
 ts[13].time_slot="S14";
 ts[13].day[0]=1;ts[13].time[0]=6;
 ts[13].day[1]=4;ts[13].time[1]=6;
 
 ts[14].time_slot="S15";
 ts[14].day[0]=1;ts[14].time[0]=7;
 ts[14].day[1]=4;ts[14].time[1]=7;
  
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
    
/*************************all inputs has been taken from files *************************************/

/********************Sorting the course according to no of student enrolled  **************************/
   sort((m),c);
/******************** course has been sorted ***************************************/   
   
 /*for(i=0;i<(m);i++)
 {
 	printf("%s\t%d\t",c[i].course,c[i].no_student);
 	for(j=0;j<3;j++)
 	{
 		printf("%d\t",c[i].color[j]);
	 }
	 printf("%c",c[i].lab);
 	printf("\n");
 }  */
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
		//H[k].slt.slot=s[i].slot;
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
 
 
 for(i=0;i<(m);i++)
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
	//printf("temp1 %d %s %s\n",temp1[ch].tcolor, temp1[ch].tslot, H[j].slt.slot);
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



for(i=0;i<(m);i++)
 {
 	//printf("%s-->",c[i].course);
 	for(j=0;j<(slot_room+slot_lab);j++)
 	{
 	 	if(graph[i][j]==1)
 		{
 			edge=edge+1;
		 } 
		// printf("%d",graph[i][j]);
	 }
	 //printf("\n");
  } 



 /*for(i=0;i<(m);i++)
 {
 	printf("%s-->",c[i].course);
 	for(j=0;j<(slot_room+slot_lab);j++)
 	{
 		if(graph[i][j]==1)
 		{
 			printf("(%s,%s)",H[j].slt.slot,H[j].cl.room_no);
 			//printf("\t");
		 }
	 }
	 printf("\n");
  }  */
  
  
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
 
 
/******************after matching****************/
//printf("After matching \n");
//printf("/*****************************************************************************************/\n");
output_graph = fopen("output_graph.txt", "r");

    if (output_graph == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
       // fscanf(output_graph,"%d",&matching_no);
        for(i=0;i<max;i++)
        {
        	fscanf(output_graph,"%d \t %d",&M[i].first_vertex,&M[i].second_vertex);
		}
        fclose(output_graph);
    }


/*for(i=0;i<(m);i++)
{
	printf("%s--->(%s %s)\n",c[(M[i].first_vertex)-1].course,H[(M[i].second_vertex)-value].slt.slot,H[(M[i].second_vertex)-value].cl.room_no);
} */
  
  
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
		graph[(M[i].first_vertex)-1][(M[i].second_vertex)-100]=1;
}

/*for(i=0;i<(m);i++)
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
}*/
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
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
 		       fprintf(csIsem,"%35s\t",mat[i][j]);
 		            
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
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
 		       fprintf(csIIIsem,"%35s\t",mat[i][j]);
 		            
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
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
 		       fprintf(meIIIsem,"%35s\t",mat[i][j]);
 		            
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
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
 		       fprintf(eeIIIsem,"%35s\t",mat[i][j]);
 		            
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
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
 		       fprintf(csVsem,"%35s\t",mat[i][j]);
 		            
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
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
 		       fprintf(meVsem,"%35s\t",mat[i][j]);
 		            
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
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
 		       fprintf(eeVsem,"%35s\t",mat[i][j]);
 		            
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
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
 		       fprintf(csVIIsem,"%30s\t",mat[i][j]);
 		            
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
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
 		       fprintf(meVIIsem,"%35s\t",mat[i][j]);
 		            
	           }
	           fprintf(meVIIsem,"\n\n",mat[i][j]);
		}
    fclose(meVIIsem); 
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
		
		if(graph[i][j]==1 && c[i].color[k]==10)
		{
			for(l=0;l<time_slt;l++)
			{
				if(!strcmp(H[j].slt.slot,ts[l].time_slot))
				local=l;
			}
			if(local<4)
			{
				for(loop=0;loop<3;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
				}
			}
			else
			{
			   if(c[i].lab=='y')
			   {
			   	mat[(ts[local].day[0])+1][(ts[local].time[0])+1]=c[i].course;
			   	mat[(ts[local].day[0])+1][(ts[local].time[0])+2]=c[i].course;
			   }
			   else
			   {
			   
			   for(loop=0;loop<2;loop++)
				{
					mat[(ts[local].day[loop])+1][(ts[local].time[loop])+1]=c[i].course;
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
        printf("Can't open file for reading.\n");
    }
    else
    {
		for(i=0;i<6;i++)
    	{
    		fprintf(eeVIIsem,"%s",mat[i][0]);	
    		for(j=1;j<9;j++)
 	        {
 		       fprintf(eeVIIsem,"%35s\t",mat[i][j]);
 		            
	           }
	           fprintf(eeVIIsem,"\n\n",mat[i][j]);
		}
    fclose(eeVIIsem); 
}

return 0;
}
