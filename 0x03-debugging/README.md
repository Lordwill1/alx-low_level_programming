`IDENTIFY ERROR`![image](https://user-images.githubusercontent.com/105258746/190832836-b113fa0f-e26f-4db1-b8c5-d094c3dfd0a7.png) `ANALYZE ERROR`


Debugging is the process of detecting and removing of existing and potential errors (also called as 'bugs') in a software code that can cause it to behave unexpectedly or crash.
`YOU HAVE TO CRAETE YOUR PROTOTYPE ON YOUR main.h file FOR YOUR CODES TO WORK`

## File: 0-main.c
In most projects, we often give you only one main file to test with. For example, this main file is a test for a postitive_or_negative() function similar to the one you worked with in an earlier C project:
```
#include "main.h"

/**
* main - tests function that prints if integer is positive or negative
* Return: 0
*/

int main(void)
{
        int i;

        i = 98;
        positive_or_negative(i);

        return (0);
}
```
Based on the `main.c` file above, create a file named `0-main.c.` This file must test that the function positive_or_negative() gives the correct output when given a case of 0.

You are not coding the solution / function, you’re just testing it! However, you can adapt your function from 0x01. C - Variables, [if, else, while - Task #0 to compile with this main file to test locally.](https://github.com/Lordwill1/alx-low_level_programming/blob/master/0x01-variables_if_else_while/0-positive_or_negative.c)

## File: 1-main.c
Copy this main file. Comment out (don’t delete it!) the part of the code that is causing the output to go into an infinite loop.
- Don’t add or remove any lines of code, as we will be checking your line count. You are only allowed to comment out existing code.
- You do not have to compile with `-Wall -Werror -Wextra -pedantic` for this task.
- 
```
#include <stdio.h>

/**
* main - causes an infinite loop
* Return: 0
*/

int main(void)
{
        int i;

        printf("Infinite loop incoming :(\n");

        i = 0;

        while (i < 10)
        {
                putchar(i);
        }

        printf("Infinite loop avoided! \\o/\n");

        return (0);
}
```
## File: 2-largest_number.c, main.h
This program prints the largest of three integers.
```
#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */

int largest_number(int a, int b, int c)
{
    int largest;

    if (a > b && b > c)
    {
        largest = a;
    }
    else if (b > a && a > c)
    {
        largest = b;
    }
    else
    {
        largest = c;
    }

    return (largest);
}
```
Fix the code in 2-largest_number.c so that it correctly prints out the largest of three numbers, no matter the case.
- Line count will not be checked for this task.

## File: 3-print_remaining_days.c, main.h
This program converts a date to the day of year and determines how many days are left in the year, taking leap year into consideration.
### NOTE: FOR YOU TO UNDERSTAND THE CODE ON SAMPLE 2, YOU NEED KNOWLEDGE OF LOGIC TRUTH TABLE.

* Code sample 1
```
#include "main.h"

/**
* main - takes a date and prints how many days are left in the year, taking
* leap years into account
* Return: 0
*/

int main(void)
{
    int month;
    int day;
    int year;

    month = 4;
    day = 01;
    year = 1997;

    printf("Date: %02d/%02d/%04d\n", month, day, year);

    day = convert_day(month, day);

    print_remaining_days(month, day, year);

    return (0);
}
```

* Code sample 2 (You need knowledge on logic truth table)
![image](https://user-images.githubusercontent.com/105258746/190833251-a0bc604c-af0d-468d-884e-53387e3c6a18.png)

```
#include <stdio.h>
#include "main.h"

/**
* main - takes a date and prints how many days are left in the year, taking
* leap years into account
* Return: 0
*/

int main(void)
{
    int month;
    int day;
    int year;

    month = 4;
    day = 01;
    year = 1997;

    printf("Date: %02d/%02d/%04d\n", month, day, year);

    day = convert_day(month, day);

    print_remaining_days(month, day, year);

    return (0);
}

carrie@ubuntu:/debugging$
carrie@ubuntu:/debugging$ cat 3-convert_day.c
#include "main.h"

/**
* convert_day - converts day of month to day of year, without accounting
* for leap year
* @month: month in number format
* @day: day of month
* Return: day of year
*/

int convert_day(int month, int day)
{
    switch (month)
    {
        case 2:
            day = 31 + day;
            break;
        case 3:
            day = 59 + day;
            break;
        case 4:
            day = 90 + day;
            break;
        case 5:
            day = 120 + day;
            break;
        case 6:
            day = 151 + day;
            break;
        case 7:
            day = 181 + day;
            break;
        case 8:
            day = 212 + day;
            break;
        case 9:
            day = 243 + day;
            break;
        case 10:
            day = 273 + day;
            break;
        case 11:
            day = 304 + day;
            break;
        case 12:
            day = 334 + day;
            break;
        default:
            break;
    }
    return (day);
}
```

* Code sample 3 (This is the code we are to work on)
```
#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
    if ((year % 4 == 0 || year % 400 == 0) && !(year % 100 == 0))
    {
        if (month >= 2 && day >= 60)
        {
            day++;
        }

        printf("Day of the year: %d\n", day);
        printf("Remaining days: %d\n", 366 - day);
    }
    else
    {
        if (month == 2 && day == 60)
        {
            printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
        }
        else
        {
            printf("Day of the year: %d\n", day);
            printf("Remaining days: %d\n", 365 - day);
        }
    }
}
```
`Output below ^1 looks good for 04/01/1997! We make a new main file 3-main_b.c to try a case that is a leap year: 02/29/2000.`
```
carrie@ubuntu:/debugging$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-convert_day.c 3-print_remaining_days.c 3-main_a.c -o 3-main_a 
carrie@ubuntu:/debugging$ ./3-main_a
Date: 04/01/1997
Day of the year: 91
Remaining days: 274
carrie@ubuntu:/debugging$
```
### Fix the `print_remaining_days()` function so that the output works correctly for all dates and all leap years.

* Line count will not be checked for this task.
- You can assume that all test cases have valid months (i.e. the value of month will never be less than 1 or greater than 12) and valid days (i.e. the value of day will never be less than 1 or greater than 31).
- You can assume that all test cases have valid month/day combinations (i.e. there will never be a June 31st or November 31st, etc.), but not all month/day/year combinations are valid (i.e. February 29, 1991 or February 29, 2427).


# AS A PROGRAMMER, WHAT DO YOU DO WHEN YOU GET STUCK?
- To help you track down that bug, start reading your code aloud. 
- Pretend that a programmer friend is sitting right next to you. 
- Explain what your code is doing and how it works. As you talk through your code, you’ll find the problem. If you don’t, have your imaginary friend ask you questions during your explanation.
- Don’t worry about going mental. You’re a C programmer. You’re already mental. 😅


As a bonus, talking through your code also helps you identify which portions need to have comments and what the comments should be.

