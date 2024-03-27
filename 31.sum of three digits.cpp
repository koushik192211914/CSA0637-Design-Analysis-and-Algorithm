#include <stdio.h>


int main()
{

    int number, sum = 0;

    printf("Enter the number ");
    scanf("%d", &number);

    printf("The number is = %d\n", number);

    
    while (number != 0)
    {
    
        sum += number % 10;

     
        number = number / 10;
    }

    printf("Sum: %d\n", sum);

    return 0;
}
