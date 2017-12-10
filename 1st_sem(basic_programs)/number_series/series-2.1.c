// S= 1 + 2/2! - 3/3! + 4/4! - 5/5! ... up to n terms.

#include<stdio.h>
int main()
{
    int n, i, j, f;
    float s;
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
            s=1;
            printf("S = 1 + ");
            for(i=2; i<=n; i++)
            {
                f=1;
                for(j=1; j<=i; j++)
                    f=f*j;
                if(i%2==0)
                {
                    s=s+(float)i/f;
                    printf("%d/%d! - ",i,i);

                }
                else
                {
                    s=s-(float)i/f;
                    printf("%d/%d! + ",i,i);
                }
            }
            printf("\b\b = %.2f",s);

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
