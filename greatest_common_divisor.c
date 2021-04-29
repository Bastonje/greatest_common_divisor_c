#include <stdio.h>

int minimum(int x, int y)
{
  int min = 0;
  if (x > y)
  {
    min = y;
  }
  else
  {
    min = x;
  }
  return min;
}

void absolute(int* number)
{
  if (*number < 0)
  {
    *number = -(*number);
  }
}

int find_greatest_common_divisor(int x, int y)
{
  int gc = 0;

  if (x != 0 && y != 0)
  {
    absolute(&x);
    absolute(&y);
    int c = minimum(x, y);
    int xmodc = 0;
    int ymodc = 0;
    do
    {
      xmodc = x % c;
      ymodc = y % c;
      gc = c;
      c = xmodc + ymodc;
    } while ((xmodc > 0) ^ (ymodc > 0));

    if (c)
    {
      gc = 1;
    }
  }
  return gc;
}

int main()
{
  int x = 0;
  int y = 0;
  int gc = 0;
  int quit = 0;

  puts("Find the greatest common divisor.");
  while (!quit)
  {
    printf("What is x? ");
    scanf("%i", &x);
    if (!x)
    {
      quit = 1;
    }
    else
    {
      printf("What is y? ");
      scanf("%i", &y);
      if (!y)
      {
        quit = 1;
      }
    }
    
    if (!quit)
    {
      gc = find_greatest_common_divisor(x, y);
      printf("The greatest common divisor of %i and %i is %i\n\n", x, y, gc);
    }
    else
    {
      printf("%i and %i do not have a common divisor, bye!\n\n", x, y);
    }
  }
  return 0;
}