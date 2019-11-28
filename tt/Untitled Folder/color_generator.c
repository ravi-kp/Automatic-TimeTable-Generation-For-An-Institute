#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 500
#define colors 6
#define value 100
#define size 50
#define room 11
#define lab_room 10
#define lab_slot 5
#define time_slt 15
struct Course_From_Db
{
	char course[size];
	int no_of_student;
	char *sem[size];
	char *dept[size];
	char clab;
	int priority;
	char *temp_slot[size];
	char *temp_room[size];
	char *division[size];
	char selected_lab[lab_room][size];
};


struct Input_Course
{
	int Input_no_student;
	char Input_courses[size];
	int color[colors];
	char Input_lab;
	int Input_priority;
	char *Input_temp_slot[size];
	char *Input_temp_room[size];
	char *Input_division[size];
};

int main()
{
	struct Course_From_Db c[max];
	struct Input_Course course_node[max];
	int m,i,j,k;
	FILE *course_file,*course_from_db;
    course_from_db = fopen("course_from_db.txt", "r");

    if (course_from_db == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        fscanf(course_from_db, "%d", &m);
        fscanf(course_from_db,"\n");
        for(i=0;i<m;i++)
        {
        	fscanf(course_from_db,"%s %d %s %s %c %d ",&c[i].course,&c[i].no_of_student,&c[i].sem,&c[i].dept,&c[i].clab,&c[i].priority);
        	if(c[i].priority==0)
        	{
        		if(c[i].clab=='y')
        		{
        			fscanf(course_from_db,"%s ",&c[i].division);
        			for(j=0;j<3;j++)
        			{
        					fscanf(course_from_db,"%s ",&c[i].selected_lab[j]);
					}
				}
			}
			else
			{
			 if(c[i].clab=='n')
			 {
			 	fscanf(course_from_db,"%s %s ",&c[i].temp_room,&c[i].temp_slot);
				 }
				 else
				 {
				 	fscanf(course_from_db,"%s %s %s ",&c[i].temp_room,&c[i].temp_slot,&c[i].division);
				 	for(j=0;j<3;j++)
        			{
        					fscanf(course_from_db,"%s ",&c[i].selected_lab[j]);
					}
				 }	
			}
		fscanf(course_from_db,"\n");	
		}
        fclose(course_from_db);
    }
for(i=0;i<m;i++)
{    
printf("%s %d %s %s %c %d ",c[i].course,c[i].no_of_student,c[i].sem,c[i].dept,c[i].clab,c[i].priority);
	if(c[i].priority==0)
        	{
        		if(c[i].clab=='y')
        		{
        			printf("%s ",c[i].division);
        			for(j=0;j<3;j++)
        			{
        					printf("%s ",c[i].selected_lab[j]);
					}
				}
			}
		 else
			{
			 if(c[i].clab=='n')
			 {
			 	printf("%s %s ",c[i].temp_room,&c[i].temp_slot);
				 }
				 else
				 {
				 	printf("%s %s %s ",c[i].temp_room,&c[i].temp_slot,&c[i].division);
				 	for(j=0;j<3;j++)
        			{
        					printf("%s ",c[i].selected_lab[j]);
					}
				 }	
			}
			printf("\n");
}
		
for(i=0;i<m;i++)
{
for(k=0;k<colors;k++)
{
course_node[i].color[k]=0;
}
}

for(i=0;i<m;i++)
{
	strcpy(course_node[i].Input_courses,c[i].course);
	course_node[i].Input_no_student=c[i].no_of_student;
	if(!strcmp(c[i].sem,"1"))
	{
		course_node[i].color[0]=1;
		
	}
	if(!strcmp(c[i].sem,"2"))
	{
		course_node[i].color[0]=11;
		
	}
/***********************for 3rd sem courses*****************************************************/	
	if(!strcmp(c[i].sem,"3"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[0]=2;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[1]=3;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		   course_node[i].color[2]=4;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[0]=2;
			course_node[i].color[1]=3;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))
		{
			course_node[i].color[0]=2;
			course_node[i].color[2]=4;
		}
		if(!strcmp(c[i].dept,"ME,EE"))
		{
			course_node[i].color[1]=3;
			course_node[i].color[2]=4;
		}
		if(!strcmp(c[i].dept,"CSE,ME,EE"))
		{
			course_node[i].color[0]=2;
			course_node[i].color[1]=3;
			course_node[i].color[2]=4;
		}
		
	}
	
	/************************************for 4th sem courses****************************************/
		if(!strcmp(c[i].sem,"4"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[0]=12;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[1]=13;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		   course_node[i].color[2]=14;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[0]=12;
			course_node[i].color[1]=13;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))
		{
			course_node[i].color[0]=12;
			course_node[i].color[2]=14;
		}
		if(!strcmp(c[i].dept,"ME,EE"))
		{
			course_node[i].color[1]=13;
			course_node[i].color[2]=14;
		}
		if(!strcmp(c[i].dept,"CSE,ME,EE"))
		{
			course_node[i].color[0]=12;
			course_node[i].color[1]=13;
			course_node[i].color[2]=14;
		}
		
	}
	
	/******************************for 5th sem courses************************************************/
       if(!strcmp(c[i].sem,"5"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[0]=5;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[1]=6;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		   course_node[i].color[2]=7;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[0]=5;
			course_node[i].color[1]=6;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))
		{
			course_node[i].color[0]=5;
			course_node[i].color[2]=7;
		}
		if(!strcmp(c[i].dept,"ME,EE"))
		{
			course_node[i].color[1]=6;
			course_node[i].color[2]=7;
		}
		if(!strcmp(c[i].dept,"CSE,ME,EE"))
		{
			course_node[i].color[0]=5;
			course_node[i].color[1]=6;
			course_node[i].color[2]=7;
		}
		
	}
	
	/**********************************for 6th sem ***************************************/
	    if(!strcmp(c[i].sem,"6"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[0]=15;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[1]=16;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		   course_node[i].color[2]=17;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[0]=15;
			course_node[i].color[1]=16;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))
		{
			course_node[i].color[0]=15;
			course_node[i].color[2]=17;
		}
		if(!strcmp(c[i].dept,"ME,EE"))
		{
			course_node[i].color[1]=16;
			course_node[i].color[2]=17;
		}
		if(!strcmp(c[i].dept,"CSE,ME,EE"))
		{
			course_node[i].color[0]=15;
			course_node[i].color[1]=16;
			course_node[i].color[2]=17;
		}
		
	}
	
	/*****************************for 7th sem ********************************************/
if(!strcmp(c[i].sem,"7"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[3]=8;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[4]=9;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		   course_node[i].color[5]=10;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[3]=8;
			course_node[i].color[4]=9;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))
		{
			course_node[i].color[3]=8;
			course_node[i].color[5]=10;
		}
		if(!strcmp(c[i].dept,"ME,EE"))
		{
			course_node[i].color[4]=9;
			course_node[i].color[5]=10;
		}
		if(!strcmp(c[i].dept,"CSE,ME,EE"))
		{
			course_node[i].color[3]=8;
			course_node[i].color[4]=9;
			course_node[i].color[5]=10;
		}

        }
        
    /*************************for 8th sem*************************************************************/    
      if(!strcmp(c[i].sem,"8"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[3]=18;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[4]=19;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		   course_node[i].color[5]=20;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[3]=18;
			course_node[i].color[4]=19;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))
		{
			course_node[i].color[3]=18;
			course_node[i].color[5]=20;
		}
		if(!strcmp(c[i].dept,"ME,EE"))
		{
			course_node[i].color[4]=19;
			course_node[i].color[5]=20;
		}
		if(!strcmp(c[i].dept,"CSE,ME,EE"))
		{
			course_node[i].color[3]=18;
			course_node[i].color[4]=19;
			course_node[i].color[5]=20;
		}

        }
        
    /***********************************for 5th and 7th sem*************************************************/    
     if(!strcmp(c[i].sem,"57"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[0]=5;
            course_node[i].color[3]=8;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[1]=6;
           course_node[i].color[4]=9;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		  course_node[i].color[2]=7; 
          course_node[i].color[5]=10;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[0]=5;
			course_node[i].color[1]=6;
			course_node[i].color[3]=8;
			course_node[i].color[4]=9;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))

		{
			course_node[i].color[0]=5;
            course_node[i].color[2]=7;
            course_node[i].color[3]=8;
			course_node[i].color[5]=10;
		}
			if(!strcmp(c[i].dept,"CSE,ME,EE"))

		{
			course_node[i].color[0]=5;
			course_node[i].color[1]=6;
            course_node[i].color[2]=7;
            course_node[i].color[3]=8;
            course_node[i].color[4]=9;
			course_node[i].color[5]=10;
		}
		
	} 
/*******************************************for 6th and 8th sem************************************************/			
 if(!strcmp(c[i].sem,"68"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[0]=15;
            course_node[i].color[3]=18;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[1]=16;
           course_node[i].color[4]=19;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		  course_node[i].color[2]=17; 
          course_node[i].color[5]=20;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[0]=15;
			course_node[i].color[1]=16;
			course_node[i].color[3]=18;
			course_node[i].color[4]=19;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))

		{
			course_node[i].color[0]=15;
            course_node[i].color[2]=17;
            course_node[i].color[3]=18;
			course_node[i].color[5]=20;
		}
		
			if(!strcmp(c[i].dept,"CSE,ME,EE"))

		{
			course_node[i].color[0]=15;
			course_node[i].color[1]=16;
            course_node[i].color[2]=17;
            course_node[i].color[3]=18;
            course_node[i].color[4]=19;
			course_node[i].color[5]=20;
		}
		
	}
/*************************************colors are generated*******************************************/ 	 	
}


for(i=0;i<m;i++)
{
	printf("%s \n",course_node[i].Input_courses);
} 

course_file = fopen("course_file1.txt", "w");

    if (course_file == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        fprintf(course_file, "%d\n", m);
        for(i=0;i<m;i++)
        {
        	fprintf(course_file,"%s %d ",c[i].course,c[i].no_of_student);
        	for(k=0;k<colors;k++)
        	{
        		fprintf(course_file,"%d ",course_node[i].color[k]);
			}
			fprintf(course_file,"%c %d ",c[i].clab,c[i].priority);
			if(c[i].priority == 0)
			{
			  if(c[i].clab=='y')
        		{
        			fprintf(course_file,"%s ",&c[i].division);
        			for(j=0;j<3;j++)
        			{
        					fprintf(course_file,"%s ",c[i].selected_lab[j]);
					}
				}	
			}
		  else
			{
			 if(c[i].clab=='n')
			 {
			 	fprintf(course_file,"%s %s ",c[i].temp_room,&c[i].temp_slot);
				 }
				 else
				 {
				 	fprintf(course_file,"%s %s %s ",c[i].temp_room,&c[i].temp_slot,&c[i].division);
				 	for(j=0;j<3;j++)
        			{
        					fprintf(course_file,"%s ",c[i].selected_lab[j]);
					}
				 }	
			}	
			
			
			fprintf(course_file,"\n");
        	
		}
        fclose(course_file);
    }  

	return 0;
}
