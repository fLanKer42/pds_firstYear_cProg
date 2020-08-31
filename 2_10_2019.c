#include <stdio.h>
#include <stdlib.h>
int main()
{
  int N,i,sum=0;
  float avg;
  int* p;
  printf("enter number of students");
  scanf("%d",&N);
  p= (int*) malloc(N*sizeof(int));
  if(p==NULL)
    {
      printf("\n memory cannot be allocated");
      exit(1);
    }
  printf("\n input value for %d students",N);
  for(i=0;i<N;i++)
    {
      printf("\n enter the value for student number %d  :  ",i+1);
      scanf("%d",&p[i]);
    }
  for(i=0;i<N;i++)
    {
      sum=sum+p[i];
    }
  avg=(float)sum/(float)N;
  printf("average is %f",avg);
  free(p);
  return 0;
}

  
  
  
