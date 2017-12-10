#include<stdio.h>
int main()
{

    int h,i,j,a,b;
    char ch,c;

    printf("\n              ---------------Welcome to Triangle Generator system v1.0---------------");

    do
    {
        //input section
        printf("\n\n Enter the height:");
        scanf("%d",&h);
        printf(" Enter the character:");
        scanf(" %c", &c);
        a=1; b=0;

        //looping and output
        /*Logic:
        First Getting the range of column (j) where characters can be printed.
        Now printing the characters.
        Pretty straight-forward! */


        for(i=0;i<h;i++)
        {
            for(j=0;j<h*2;j++)
            {
                if (j>=h-a && j<h+b)
                    printf("%c", c);
                else
                    printf(" ");
            }
            printf("\n");
            a++;
            b++;
        }
        printf("Want to re-run? (y/n):");
        scanf(" %c",&ch);
    }while(ch=='y');
    return 0;
}
