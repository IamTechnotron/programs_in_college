#include<stdio.h>

int main()
{
    int n, cn, b1, b2, p, r, pos, i;
    char ch;

    printf("\n---------------------- WELCOME TO WHOLE-NUMBER INTER-CONVERTER ----------------------\n");
    printf("               Here you can inter-convert any whole-number of base 2,8,10\n");

    do
    {
        printf("\n------------------------------------------------------------------------------------\n");
        p=0; cn=0; pos=1;
        printf("\nEnter Choice: Base 2 means Binary,  Base 8 means Octal and  Base 10 means Decimal \n\n");
        printf("Enter the base of the number to be converted: "); scanf("%d", &b1);
        if(b1!=2 && b1!=8 && b1!=10)
        {
            printf("ERROR! INVALID BASE! Please enter a valid bases next time ! Exiting...\n");
            return 1;
        }
        printf("Enter the base for the number to be converted to: "); scanf("%d", &b2);
        if((b2!=2 || b2!=8 || b2!=10) && (b1 == b2))
        {
            printf("ERROR! INVALID BASE OR SAME BASE!\nPlease enter a valid bases next time ! Exiting...\n");
            return 1;
        }
        printf("Now, Please enter the number:"); scanf("%d", &n);

        if(b2 == 10)                // binary/octal to decimal
        {
            while(n != 0)
            {
                r = n%10;
                n = n/10;
                pos = 1;
                for(i=0; i<p; i++)
                    pos=pos*b1;
                cn = cn + r*pos;
                p++;
            }
        }
        else if(b1 == 10)           // decimal to binary/octal
        {
           while(n != 0)
            {
                r = n % b2;
                n = n / b2;
                pos = 1;
                for(i=0; i<p; i++)
                    pos = pos * 10;
                cn = cn + r * pos;
                p++;
            }
        }
        else if(b1!=10 && b2!=10)    // binary/octal to decimal to octal/binary
        {
            while(n != 0)
            {
                r = n % 10;
                n = n / 10;
                pos = 1;
                for(i=0; i<p; i++)
                    pos=pos*b1;
                cn=cn+r*pos;
                p++;
            }
            p=0; pos=1; n=cn; cn=0;
            while(n != 0)
            {
                r = n % b2;
                n = n / b2;
                pos = 1;
                for(i=0; i<p; i++)
                    pos = pos * 10;
                cn = cn + r * pos;
                p++;
            }
        }

        printf("Converted Number is: %d",cn);

        printf("\n\nDo you want repeat? (y/n): ");
        scanf(" %c", &ch);
    }while(ch == 'y');
    return 0;
}
