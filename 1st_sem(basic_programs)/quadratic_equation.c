//QUADRAIC EQUATION:a(x^2)+bx+c=0

#include<stdio.h>
#include<math.h>
int main()
{

    float a,b,c,xa,xb,d;
    char ch;

    //Taking the input
    printf("Enter the Quadratic Equation:");
    do
    {
        printf("\nEnter the coeficient of x^2:");
        scanf("%f",&a);
        if (a==0)
        {
            printf("If a=0, Equations no more remains quadratic!!");
            return 0;
        }
        printf("Enter the coeficient of x:");
        scanf("%f",&b);
        printf("Enter the constant:");
        scanf("%f",&c);
        printf("So, You entered the Quadratic Equation: ");
        printf("%.1f(x^2) + %.1fx + %.1f",a,b,c);
        printf("\nAre you satisfied? (y/n):");
        scanf(" %c",&ch);
    }while(ch=='n');

    //Calculation Part
    d=(b*b)-(4*a*c);
    xa=(-b)/(2*a); xb=(sqrt(d))/(2*a);
    printf("\nValue of Determinant,D= %.1f\n", d);

    if(d >0) //condition for real roots
    {

        printf("--[Roots are Real!]--\n");
        printf("Values are : %.1f and %.1f",(xa+xb),(xa-xb));

    }
    else if(d ==0) //condition for real and equal roots
    {
         printf("--[Roots are Real and Equal!]--\n");
         printf("Value is : %.1f",(xa+xb));
    }
    else if(d <0) //condition for imaginary roots
    {
         printf("--[Roots are Imaginary]--\n");
         xb=(sqrt(-d))/(2*a);
         printf("Values are : %.1f+%.1fi and %.1f-%.1fi",xa,(xb),xa,(xb));
    }
    else
         printf("Unknown Error Occurred...");

    printf("\n");
    return 0;
}
