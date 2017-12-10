#include<stdio.h>
/*
Logic:
    just like we find the HCF/GCD between a and b, by division method.
*/

int main()
{
    int a, b, r, gcd;
    char ch;

    printf("\n---------------------- WELCOME TO GCD/HCF FINDER BETWEEN 2 NUMBERS ----------------------\n");
    do
    {
        printf("\nEnter the First number: ");
        scanf("%d", &a);
        printf("Enter the Second number: ");
        scanf("%d", &b);

        do
        {
            gcd = (b % a == 0) ? a : r;
            r = b % a;
            b = a;
            a = r;

        } while(r);
        printf("\nGCD/HCF between the two numbers is %d", gcd);

        printf("\n\nDo you want repeat? (y/n):");
        scanf(" %c", &ch);
    }while(ch == 'y');
    return 0;
}

