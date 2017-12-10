#include<stdio.h>
int main()
{

    int h,i,j,a,b,k;
    char ch,c;

    printf("\n              ---------------Welcome to Triangle Generator system v2.0---------------");

    do
    {
        //input section
        printf("\n\n Enter the height:");
        scanf("%d",&h);
        printf(" Enter the character:");
        scanf(" %c", &c);
        a=1; b=0;k=1;

        //looping and output
        /*Logic:
        First getting the range of column nos, to be printed, ie the values/range of j
        Next, printing characters only the alternate occurrences in the range,omitting out the characters in even place.
        [Note: Its the even occurrence of the 'Character', Not the column(j) value.] */


        for(i=0;i<h;i++)
        {
            for(j=0;j<h*2;j++)
            {
                if ((j>=h-a && j<h+b) && (k%2)!=0)
                {
                    printf("%c", c);
                    k++;
                }
                else
                {
                    printf(" ");
                    k=1;
                }
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
