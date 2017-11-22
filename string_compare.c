#include <ctype.h>
#define DEBUG 0


int string_compare (char[], char[]);



int
string_compare (char input[], char check[])
{
  char *p;
  char *q;
  char newInput[15];
  char newCheck[15];
  int i = 0;
  int j = 0;
  int value;
  p = input;
  q = check;

  for (i = 0; i < 15; i++)
    {
      input[i] = tolower (input[i]);
    }
  for (i = 0; i < 15; i++)
    {
      check[i] = tolower (check[i]);
    }

  for (i = 0; i < 15; i++)
    {
      if (*p == 32)
	{
	  p = p + 1;
	  i = i - 1;
	}
      else
	{
	  newInput[i] = *p;
	  p = p + 1;
	}
    }
  for (i = 0; i < 15; i++)
    {
      if (*q == 32)
	{
	  q = q + 1;
	  i = i - 1;
	}
      else
	{
	  newCheck[i] = *q;
	  q = q + 1;
	}
    }

#if DEBUG
  printf ("Comparing: %s, %s\n", newInput, newCheck);
#endif

  value = strcmp (newInput, newCheck);

#if DEBUG
  printf ("%d\n", value);
#endif

  return value;

}
