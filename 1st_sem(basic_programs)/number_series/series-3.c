// S= 1 + (1+2) + (1+2+3) + ... up to n terms.

#include<stdio.h>
int main()
{
    int n, i, j, s, S;
    char ch;
    do
    {

        printf("\n Enter the number of terms: "); scanf("%d", &n);
        if(n<0)
        {
            printf("\nHow on earth do you think range can be negative ??? Next time, enter using your brain...\n");
        }
        else
        {
            S=1;
            printf("S = 1 + ");
            for(i=2; i<=n; i++)
            {
                s=0;
                printf("\(");
                for(j=1; j<=i; j++)
                {
                    s=s+j;
                    printf("%d+", j);
                }
                printf("\b\) + ");
                S=S+s;
            }
            printf("\b\b= %d", S);

        }
        printf("\n----------------------------------------------\n");
        printf("\nDo you want repeat? (y/n):");
        fflush(stdin);
        scanf(" %c",&ch);
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N')
        {
            printf("Stop Misbehaving...enter y to continue, n for not continuing!");
            fflush(stdin);
            scanf(" %c",&ch);

        }
    }while(ch=='y' || ch=='Y');
    return 0;
}
