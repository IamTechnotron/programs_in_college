#include<stdio.h>
int main()
{
    int ch;
    char c;
    float a, b, result;


    printf("\n------------------------------WELCOME TO TWO NUMBER CALCULATOR------------------------------\n");
    do
    {
        printf("\nEnter the numbers, NOTE: First number is operated by the second!\n");
        printf("Enter 1st no.: "); scanf("%f", &a);
        printf("Enter 2nd no.: "); scanf("%f", &b);
        printf("Enter Calculation choice:\n");
        printf("[1] ADD \t [2] SUBTRACTION \t [3] MULTIPLICATION \t [4] DIVISION\n>> ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: result = a+b;
                    printf("%.2f + %.2f = %.2f",a,b,result);
                    break;

            case 2: result = a-b;
                    printf("%.2f - %.2f = %.2f",a,b,result);
                    break;

            case 3: result = a*b;
                    printf("%.2f X %.2f = %.2f",a,b,result);
                    break;

            case 4: if(b==0)
                    {
                        printf("Divide by Zero(0) error!");
                        break;
                    }
                    else
                    {
                        result = a/b;
                        printf("%.2f / %.2f = %.2f",a,b,result);
                        break;
                    }

            default: printf("ok, done! See, nothing happens if you don't follow orders! :D");
                    break;
        }

        printf("\n-----------------------------------------------------\n");
        printf("\n\nDo you want repeat? (y/n):");
        fflush(stdin);
        scanf(" %c",&c);
        while(c!='y' && c!='Y' && c!='n' && c!='N')
        {
            printf("Stop Misbehaving...enter y to continue, n for not continuing!");
            fflush(stdin);
            scanf(" %c",&c);

        }
    }while(c=='y' || c=='Y');
    return 0;
}


