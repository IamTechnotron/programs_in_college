#include<stdio.h>
int main()
{

    int h,i,j,a;
    char ch,c;

    printf("\n              ---------------Welcome to Triangle Generator system v0.2---------------");

    do
    {
        //input section
        printf("\n\n Enter the height:");
        scanf("%d",&h);
        printf(" Enter the character:");
        scanf(" %c", &c);
        a=h;
        //looping and output
        for(i=0;i<h;i++)
        {
            for(j=0;j<h;j++)
            {
                if(j>=i)
                    printf("%c", c);
                else
                    printf(" ");
            }
            printf("\n");
        }
        printf("Want to re-run? (y/n):");
        scanf(" %c",&ch);
    }while(ch=='y');
    return 0;
}
