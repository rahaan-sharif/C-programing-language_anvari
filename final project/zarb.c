//salam,vaght be kheir;
//baraye zarb e do adad, do adad ra bedoon e estefade az alamat e zarb vared konid.



#include <stdio.h>
#include <stdlib.h>

#define tool 50

int main(void){
    printf("dar in barname mikhamim amal e zarb e do");
    printf("\nadad e panjah raghami ra anjam dahim.\n\n\n");
    char v1[tool]={0}, v2[tool]={0};
    int vv1[tool]={0}, vv2[tool]={0};
    int rev[tool]={0};

    printf("adad e aval ra vared konid:\n");
    scanf("%s",&v1);
    printf("adad e dovom ra vared konid:\n");
    scanf("%s",&v2);

     for(int i=0; i<tool; i++){
        if(v1[i]!=0)
            vv1[i]=v1[i]-48;
        if (v1[i]!=0)
            vv2[i]=v2[i]-48;}

    for(int i=0; i<tool; i++)
        rev[i]=vv1[tool-1-i];
    for(int i=0; i<tool; i++)
        vv1[i]=rev[i];


    for(int i=0; i<tool; i++)
        rev[i]=vv2[tool-1-i];
    for(int i=0; i<tool; i++)
        vv2[i]=rev[i];


    printf("\n");


   int zarb[tool*2+1]={0}, javab[tool*2]={0};
   int damdast[tool*2+1]={0};



   for(int j=0; j<tool; j++){
        for(int i=0; i<tool; i++)
            {damdast[i]=vv1[i]*vv2[j];}


        for(int p=0; p<j; p++){
            for(int i=((tool*2)-1); i>0; i--)
                {damdast[i+1]=damdast[i];}
            damdast[1]=damdast[0];
            damdast[0]=0;}

        for(int i=0; i<tool*2; i++)
            {zarb[i]+=damdast[i];
             damdast[i]=0;}}


    for(int i=0; i<2*tool; i++)
        {zarb[i+1]+=zarb[i]/10;
        zarb[i]%=10;}

    for(int i=0; i<tool*2; i++)
        rev[(2*tool)-1-i]=zarb[i];

    int adad=0;
    for(int i=0; i<tool*2; i++)
        if (rev[i]!=0)
            {adad=i;
             break;}

    printf("khorooji mishavad: \n");
    for(int i=adad; i<tool*2; i++)
        {printf("%d", rev[i]);}

    return 0;}
