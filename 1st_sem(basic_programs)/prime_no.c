#include<stdio.h>
#include<math.h>
int main()
{
    int n,t=0,i;


 for(;;)

 {

       printf("\nEnter the number:");
        scanf("%d",&n);
        if(n<0)
            n=-n;

        for(i=2;i<n;i++)
            if(n%i==0)
                t++;
        if(t==0)
            printf("Prime");
        else
            printf("Not Prime");


}
 return 0;
}
