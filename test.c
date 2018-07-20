    #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    // Declare second integer, double, and String variables.
    int j;
    double k;
    char l[100]; 
    
    // Read and save an integer, double, and String to your variables.
    scanf("%d",&j);
    scanf("%lf",&k);
    gets(l);

    
    // Print the sum of both integer variables on a new line.

    printf("%d\n",(j+i));

    // Print the sum of the double variables on a new line

    printf("%.1lf\n",(k+d));

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    
    printf("%s",s);
    printf("%s",l);
    return 0;
}
