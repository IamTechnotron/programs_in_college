#include<stdio.h>
int main()
{

    int h,i,j,a;
    char ch,c;

    printf("\n              ---------------Welcome to Triangle Generator system v0.4---------------");

    do
    {
        //input section
        printf("\n\n Enter the height:");
        scanf("%d",&h);
        printf(" Enter the character:");
        scanf(" %c",&c);
       //looping and output
        for(i=h;i>=1;i--)
        {
            for(j=1;j<=i;j++)
                printf("%c", c);
            printf("\n");
        }
        printf("Want to re-run? (y/n):");
        scanf(" %c",&ch);
    }while(ch=='y');
    return 0;
}
