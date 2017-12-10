#include<stdio.h>
int main()
{

    int h,i,j;
    char c,ch;

    printf("\n              ---------------Welcome to Triangle Generator system v0.5---------------");

    //input section
    printf("\n\n Enter the height:");
    scanf("%d",&h);
    printf(" Enter the character:");
    scanf(" %c", &c);

    //looping and output
    do
    {
        for(i=0;i<h;i++)
        {
            for(j=0;j<(i*2)-1;j++)
                printf("%c", c);
            printf("\n");
        }
    }while(ch=='y');
    return 0;
}
