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
struct node7
{
	char *time_slot;
	int day[3];
	int time[3];
};

int main()
{
char *temp="NULL";
struct node7 ts[max]; 
File *slot_file;
slot_file = fopen("slot_fromdb.txt", "r");

    if (slot_file == NULL)
    {
        printf("Can't open file for reading.\n");
    }
    else
    {
        for(i=0;i<34;i++)
        {
                fscanf(slot_file,"%s",&ts[i].time_slot);
                while(!(strcmp(temp,ts[i].time_slot))
               {
                 fscanf(slot_file,"%s %s",ts[i].day[k],ts[i].day[k]);
                }  
		}
        fclose(slot_file);
    }
return 0;
}

