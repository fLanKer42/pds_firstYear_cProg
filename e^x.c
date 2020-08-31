#include <stdio.h>
int main()
{
  float count,x,sum,term,N; 
  printf("this programme will calculate e power x upto N terms\n Enter value of x and N with a comma in between.");
  scanf("%f,%f",&x,&N);
  for(count=1,term=1,sum=0;count<=N;count++)
    {
      sum=sum+term;
      term=(term*x)/count;
    }
  printf("%f is answer",sum);
  return 0;
}

      
