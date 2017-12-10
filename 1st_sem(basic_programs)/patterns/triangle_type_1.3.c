#include<stdio.h>
int main()
{

    int h,i,j,k;
    char ch;

    printf("\n              ---------------Welcome to Triangle Generator system v1.3---------------");

    do
    {
        //input section
        printf("\n\n Enter the height:");
        scanf("%d",&h);
        /*Logic: breaking the pattern into two parts,
        using 4 loops!
        1st to get the rows
        2nd to print the spaces in front
        3rd to print 1st half and
        4th to print the second half! */


         for(i=1;i<=h;i++)
        {
            for(j=0;j<h-i;j++)
                printf(" ");
            for(k=i;k<=(2*i-1);k++)
                printf("%d",k);
            for(k-=2;k>=i;k--)
               printf("%d",k);
            printf("\n");

        }
        printf("Want to re-run? (y/n):");
        scanf(" %c",&ch);
          }while(ch=='y');
    return 0;
}

