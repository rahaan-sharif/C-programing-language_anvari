#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char fname[80];
    char lname[80];
    char sid[12];
    float average;
};



void add_student(struct student *pts, int* location)
{
    printf("***\n***\n");
    char fname[80]={0}, lname[80]={0}, sid[12]={0};
    float average=0;
    printf("   enter students first name:\n   ");
    scanf("%s", fname);
    printf("   enter students last name:\n   ");
    scanf("%s", lname);
    printf("   enter students id code:\n   ");
    scanf("%s", sid);
    printf("   enter students average:\n   ");
    scanf("%f", &average);

    strcpy(pts[*location].fname, fname);
    strcpy(pts[*location].lname, lname);
    strcpy(pts[*location].sid, sid);
    pts[*location].average=average;
    printf("%s ", pts[*location].fname);
    printf("%s ", pts[*location].lname);
    printf("%s ", pts[*location].sid);
    printf("%f\n", pts[*location].average);
    (*location)++;
    printf("   done!\n");
    printf("   ---\n");
}

void search_student(struct student *pts, int *location)
{
    char sid[12]={0};
    printf("   enter studens ID code:\n  ");
    scanf("%s", sid);
    printf("------ now location is: %d\n", *location);
    for(int i=0; i<(*location); i++)
    {
        printf("    location: %d\n", i);
        if (strcmp(pts[i].sid, sid)==0)
        {
            printf("      first naem: %s", pts[i].fname);
            printf("      last name: %s", pts[i].lname);
            printf("      ID: %s", pts[i].sid);
            printf("      average: %f\n", pts[i].average);
            return;
        }
    }
}

void delete_student(struct student *pts, int *location)
{
    char sid[12]={0};
    printf("***\n***\n");
    printf("   enter student'd ID: ");
    scanf("%s", sid);
    for(int i=0; i<(*location); i++)
    {
        if (!strcmp(pts[i].sid, sid))
        {
            printf("=-=-==-=-=- %s %s %s  %f\n", pts[i].fname, pts[i].lname, pts[i].sid, pts[i].average);
            for(int j=i; j<(*location-1); j++)
            {
                pts[j]=pts[j+1];
            }
            (*location)--;
            return;
        }
    }
}

void sort_students(struct student *pts, int *location)
{
    struct student temp;
    for(int i=0; i<(*location); i++)
    {
        for(int j=0; j<i; j++)
        {
            if (pts[i].average<pts[j].average)
            {
                temp=pts[i];
                pts[i]=pts[j];
                pts[j]=temp;
            }
        }
    }
}



int main(void)
{
    printf("hello!\n");
    printf("in this program, we do some operations in students list.");
    printf("\n\n\n");

    char file_location[100]={0};
    printf("enter your file location:\n");
    scanf("%s", file_location);

    struct student* pts=(struct student*)malloc(300*sizeof(struct student));
    int place=0;
    int *location=&place;

    FILE *file=NULL;
    while(file==NULL)
    {
        file=fopen(file_location, "r");
        if(file==NULL)
        {
           printf("error! can't reach your file.\n");
           printf("please try again.\n");
           printf("enter your file location:\n");
           scanf("%s", file_location);
        }
    }

    while(!feof(file))
    {
        fscanf(file, "%s", pts[*location].fname);
        fscanf(file, "%s", pts[*location].lname);
        fscanf(file, "%s", pts[*location].sid);
        fscanf(file, "%f", &pts[*location].average);
        (*location)++;
    }
    fclose(file);


    int input=-2;
    while(input!=-1)
    {
        int a;
        printf("enter number of which operation you want to do:\n");
        printf(" 1: add a new student to the list.\n");
        printf(" 2: delete a student from the lis.\n");
        printf(" 3: search a student in the list.\n");
        printf(" 4: sorting students in the list based on their average.\n");
        printf("-1: save changes and exit.\n");
        scanf("%d", &a);
        input=a;
        if (input==1)
            add_student(pts, location);
        else if (input==2)
            delete_student(pts, location);
        else if (input==3)
            search_student(pts, location);
        else if (input==4)
            sort_students(pts, location);
    }


    FILE *file2;
    file2=fopen(file_location, "w");
    for(int i=0; i<*location; i++)
    {
        fprintf(file2, "%s ", pts[i].fname);
        fprintf(file2, "%s ", pts[i].lname);
        fprintf(file2, "%s ", pts[i].sid);
        fprintf(file2, "%f\n", pts[i].average);
    }
    fclose(file2);






    free(pts);
    return 0;
}

