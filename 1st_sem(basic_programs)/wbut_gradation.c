//WBUT Gradation

#include<stdio.h>
#include<math.h>
int main()
{
    float m;
    int marks;

    //Taking the input
    printf("Enter the marks:");
    scanf("%f",&m);
    marks=round(m);

    printf("GRADE is:");
    //Checking for Grade
    if (marks>=91)
        printf("O");
    else if (marks>=81 && marks<=90)
        printf("E");
    else if (marks>=71 && marks<=80)
        printf("A");
    else if (marks>=61 && marks<=70)
        printf("B");
    else if (marks>=51 && marks<=60)
        printf("C");
    else if (marks>=41 && marks<=50)
        printf("D");
    else if (marks<=40)
        printf("F");
    else
        printf("Unknown Error Occurred...");

    return 0;
}
