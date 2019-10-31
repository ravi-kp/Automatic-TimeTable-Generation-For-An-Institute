#include<stdio.h>
#include<string.h>
#define max 500
#define size 100
#define colors 3

struct node1{
	char course[size];
	char sem[size];
	int no_of_student;
	char dept[size];
	char clab;
};

struct node2{
	char courses[size];
	int no_student;
	int color[colors];
	char lab;
};
int main()
{
	struct node1 c[max];
	struct node2 course_node[max];
	int m,i,k;
	FILE *course_file,*course_from_db;
  
    course_from_db = fopen("course_from_db.txt", "r");

    if (course_from_db == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        fscanf(course_from_db, "%d", &m);
        for(i=0;i<m;i++)
        {
        	fscanf(course_from_db,"%s %s %d %s %c\n",&c[i].course,&c[i].sem,&c[i].no_of_student,&c[i].dept,&c[i].clab);
		}
        fclose(course_from_db);
    }
/*for(i=0;i<m;i++)
{    
printf("%s %s %d %s %c\n",&c[i].course,&c[i].sem,&c[i].no_of_student,&c[i].dept,&c[i].clab);
}
	*/	
for(i=0;i<m;i++)
{
for(k=0;k<colors;k++)
{
course_node[i].color[k]=0;
}
}

for(i=0;i<m;i++)
{
	strcpy(course_node[i].courses,c[i].course);
	course_node[i].no_student=c[i].no_of_student;
	if(!strcmp(c[i].sem,"1") || !strcmp(c[i].sem,"2"))
	{
		course_node[i].color[0]=1;
		
	}
	
	if(!strcmp(c[i].sem,"3") || !strcmp(c[i].sem,"4"))
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
       if(!strcmp(c[i].sem,"5") || !strcmp(c[i].sem,"6"))
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
	
if(!strcmp(c[i].sem,"7") || !strcmp(c[i].sem,"8"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[0]=8;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[1]=9;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		   course_node[i].color[2]=10;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[0]=8;
			course_node[i].color[1]=9;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))
		{
			course_node[i].color[0]=8;
			course_node[i].color[2]=10;
		}
		if(!strcmp(c[i].dept,"ME,EE"))
		{
			course_node[i].color[1]=9;
			course_node[i].color[2]=10;
		}
		if(!strcmp(c[i].dept,"CSE,ME,EE"))
		{
			course_node[i].color[0]=8;
			course_node[i].color[1]=9;
			course_node[i].color[2]=10;
		}

        }
     if(!strcmp(c[i].sem,"5and7") || !strcmp(c[i].sem,"6and8"))
	{
		if(!strcmp(c[i].dept,"CSE"))
		{
			course_node[i].color[0]=5;
                        course_node[i].color[1]=8;
		}
		if(!strcmp(c[i].dept,"ME"))
		{
		   course_node[i].color[0]=6;
                   course_node[i].color[1]=9;	
		}
		if(!strcmp(c[i].dept,"EE"))
		{
		  course_node[i].color[0]=7; 
                  course_node[i].color[2]=10;	
		}
		if(!strcmp(c[i].dept,"CSE,ME"))
		{
			course_node[i].color[0]=8;
			course_node[i].color[1]=9;
		}
		if(!strcmp(c[i].dept,"CSE,EE"))

		{
			course_node[i].color[0]=5;
                        course_node[i].color[1]=8;
			course_node[i].color[2]=10;
		}
		
	} 
	course_node[i].lab=c[i].clab;			
	
}


/*for(i=0;i<m;i++)
{
	printf("%s \n",course_node[i].courses);
} */

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
        	fprintf(course_file,"%s %d ",course_node[i].courses,course_node[i].no_student);
        	for(k=0;k<colors;k++)
        	{
        		fprintf(course_file,"%d ",course_node[i].color[k]);
			}
			fprintf(course_file,"%c",course_node[i].lab);
			fprintf(course_file,"\n");
        	
		}
        fclose(course_file);
    }

	return 0;
}
