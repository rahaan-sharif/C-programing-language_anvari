#include <stdio.h>
#include <stdlib.h>
#define tool 50

//dar in barname, amal e taghsim ra anjam midahim:

void tavazon(int* p){
    //why did you start from tool? why did'nt you start from tool-1?
    for(int i=tool-1; i>-1; i--)
    {
        if (p[i]>9)
        {
            p[i-1]++;
            p[i]-=10;
        }
    }

}

void tafrigh(int* p, int* q){
    for(int i=0; i<tool; i++)
        {p[i]=p[i]-q[i];}}

void min(int *p){
    for(int i=tool-1; i>0; i--)
        {if (p[i]<0)
            {p[i]+=10;
             p[i-1]--;}}}

int shart(int *p1, int *p2)
{
    for(int i=0; i<tool; i++)
    {
        if(p1[i]>p2[i])
            return 1;
        else if(p1[i]<p2[i])
            return 0;
    }
    return 1;
}

int main(void){

    printf("dar in barname amal e taghsim do adad e ");
    printf("panjah raghami ra anjam midahim\n\n");
    char voroodi[tool]={0};

    printf("maghsoom ra vared konid:\n");
    scanf("%s",voroodi);
    int a1[tool]={0};
    for(int i=0; i<tool; i++)
        {a1[i]=voroodi[i]-48;}

    printf("maghsoom elaih ra vared konid:\n");
    scanf("%s", voroodi);
    int a2[tool]={0};
    for (int i=0; i<tool; i++)
        {a2[i]=voroodi[i]-48;}


    int kharej[tool]={0};



    while(shart(a1, a2))
    {
         tafrigh(a1,a2);
         min(a1);
         kharej[tool-1]++;
         tavazon(kharej);
         tavazon(a1);
    }

    printf("kharej e ghesmat mishavad:\n");

    for(int i=0; i<tool; i++)
    {
        if(kharej[i]!=0)
        {
            for(int j=i; j<tool; j++)
                printf("%d", kharej[j]);
            break;
        }
    }

    printf("\nbaghimandeh mishavad:\n");
    for(int i=0; i<tool; i++)
    {
        if(a1[i]!=0)
        {
            for(int j=i; j<tool; j++)
                printf("%d", a1[j]);
            break;
        }
    }


    return 0;}
