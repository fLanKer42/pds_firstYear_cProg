#include <stdio.h>
#include <stdlib.h>
void main()
{
  unsigned int seed;
  printf("enter seed: ");
  scanf("%u",&seed);
  srand(seed);
  printf("%d",1+(rand()%6));
}
