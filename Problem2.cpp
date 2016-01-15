/* Problem 1
    Even Fibonacci numbers

    Each new term in the Fibonacci sequence is generated by adding the previous 
    two terms. By starting with 1 and 2, the first 10 terms will be:

        1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

    By considering the terms in the Fibonacci sequence whose values do not 
    exceed four million, find the sum of the even-valued terms. */

#include <stdio.h>
#include <ctime>

int solution1(long int number)
{
    long int sum = 0, i = 0, ia = 0, ib = 1;
    for (i = 1; i < number; i = ia + ib)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
        ia = ib; 
        ib = i;
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
    long int number = 4000000;
    long double startTime, diffTime;
    
    printf("Sum of the even-valued Fibonacci terms %ld is.\n", number);
    
    startTime = time(0);
    solution1(number);
    diffTime = time(0) - startTime;
    printf("Execution time in sec: %Lf\n", diffTime);
    
/*    startTime = time(0);
    solution2(number);
    diffTime = time(0) - startTime;
    printf("Execution time in sec: %Lf\n", diffTime);
    
    startTime = time(0);
    solution3(number);
    diffTime = time(0) - startTime;
    printf("Execution time in sec: %Lf\n", diffTime);
*/
    return 0;
}