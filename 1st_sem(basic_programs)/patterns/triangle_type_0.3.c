#include<stdio.h>
int main()
{

    int h,i,j,a;
    char ch,c;

    printf("\n              ---------------Welcome to Triangle Generator system v0.3---------------");

    do
    {
        //input section
        printf("\n\n Enter the height:");
        scanf("%d",&h);
        printf(" Enter the character:");
        scanf(" %c", &c);
        a=h-1;
        //looping and output
        for(i=0;i<h;i++)
        {
            for(j=0;j<h;j++)
            {
                if (j<a)
                     printf(" ");
                else
                   printf("%c", c);
            }
            printf("\n"); a--;
        }
        printf("Want to re-run? (y/n):");
        scanf(" %c",&ch);
    }while(ch=='y');
    return 0;
}
