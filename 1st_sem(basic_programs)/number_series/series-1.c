// S=1+3+5+... up to n terms

#include<stdio.h>
int main()
{
    int s,n,i;
    char ch;
    do
    {
        s=0;
        printf("\n Enter the number of terms: "); scanf("%d", &n);
        if(n<0)
        {
            printf("\nHow on earth do you think range can be negative ??? Next time, enter using your brain...\n");
        }
        else
        {
            printf(" S = ");
            for(i=1; i<=n; i++)
            {
                printf("%d + ",(2*i-1));
                s=s+(2*i-1);
            }
            printf("\b\b = %d",s);
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
