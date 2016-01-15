/* Problem 1
   Multiples of 3 and 5

   If we list all the natural numbers below 10 that are multiples of 3 or 5, 
   we get 3, 5, 6 and 9. The sum of these multiples is 23.
   
   Find the sum of all the multiples of 3 or 5 below 1000. */

#include <stdio.h>
#include <ctime>

int solution1(long int number)
{
    long int sum = 0, i = 0;
    for (i = 0; i < number; i++)
    {
        if ( i % 3 == 0 or i % 5 == 0)
        {
            sum = sum + i;
        }
    }
    printf("Solution 1: %ld\n", sum);
    return 0;
}

int solution2(long int number)
{
    long int sum = 0, i = 0;
    for (i = 0; i < number; i += 3)
    {
        sum = sum + i;
    }
    for (i = 0; i < number; i += 5)
    {
        sum = sum + i;
    }
    for (i = 0; i < number; i += 15)
    {
        sum = sum - i;
    }
    printf("Solution 2: %ld\n", sum);
    return 0;
}

int solution3(long int number)
{
    long int sum = 0;
    number--;
    sum = (3 + ( number - number % 3 )) * (( number - number % 3) / 3) / 2 + 
          (5 + ( number - number % 5 )) * (( number - number % 5) / 5) / 2 -
          (15 + ( number - number % 15 )) * (( number - number % 15) / 15) / 2;
    printf("Solution 3: %ld\n", sum);
    return 0;
}

int main()
{
    //long int number = 10000000000;
    long int number = 1000;
    long double startTime, diffTime;
    
    printf("Sum of all the multiples of 3 or 5 below %ld is.\n", number);
    
    startTime = time(0);
    solution1(number);
    diffTime = time(0) - startTime;
    printf("Execution time in sec: %Lf\n", diffTime);
    
    startTime = time(0);
    solution2(number);
    diffTime = time(0) - startTime;
    printf("Execution time in sec: %Lf\n", diffTime);
    
    startTime = time(0);
    solution3(number);
    diffTime = time(0) - startTime;
    printf("Execution time in sec: %Lf\n", diffTime);

    return 0;
}
