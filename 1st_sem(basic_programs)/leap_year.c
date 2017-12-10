#include<stdio.h>
int main()
{
    int n, flag;
    char c;
    printf("\n------------------------------ WELCOME TO LEAP YEAR CHECKER ------------------------------\n");
    do
    {
        flag=0;
        printf("Enter the year: "); scanf("%d", &n);
        if(n<0)
        {
            n=-n;
            printf("\nHey, Welcome to Earth! It seems you are new to this planet.\nHere on earth, we only have positive value for years.\n");
            printf("For years before 0, i.e. Birth of Christ, we don't say -%d, but say %d BC.\n",n,n);
        }
        if(n%100 == 0)                  //checking for Centenary Years
        {
            if(n%400 == 0)
                flag = 1;
        }
        else
            if(n%4 == 0)
                flag = 1;

        if(flag == 1)
            printf("\n%d is leap year!",n);
        else
            printf("\n%d is Not a leap year!",n);
        printf("\n----------------------------------------------------------------------------------------\n");
        printf("\nDo you want repeat? (y/n):");
        fflush(stdin);
        scanf(" %c",&c); printf("\n");
        while(c!='y' && c!='Y' && c!='n' && c!='N')
        {
            printf("Stop misbehaving ... enter y to continue, n for not continuing!");
            fflush(stdin);
            scanf(" %c",&c);

        }
    }while(c=='y' || c=='Y');
    return 0;
}


