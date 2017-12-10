#include<stdio.h>
#include<math.h>
int main()
{
    int n,c,s,s1,t,r,p,i;
    char ch;
    /*Logic:
    sum of the digits raised to the power of the no. of digits should be equal to the original number*/

    printf("\n------------------------------WELCOME TO ARMSTRONG NUMBER CHECKER------------------------------");
    do
    {
        s=0;t=0;s1=0;
        printf("\nEnter the number:");
        scanf("%d",&n);
        c=n;
        while(n!=0)
        {
            n=n/10;
            t++;    // t counts the no. of digits.
        }
        n=c;
        while(n!=0)
        {
            r=n%10;
            p=r;
            for (i=1;i<t;i++)               // Does the power calculation
                p=p*r;          
            s=s+p;
            n=n/10;
        }
        n=c;
        if(s==c)
            printf("\n>> %d  is an Armstrong Number",c);
        else
            printf("\n>> %d  is not an Armstrong Number",c);
        printf("\n\nDo you want repeat? (y/n):");
        scanf(" %c",&ch);
    }while(ch=='y');
    return 0;
}
