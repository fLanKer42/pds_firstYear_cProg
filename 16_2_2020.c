#include <stdio.h>

int main()
{
  float A[3][4], x[3];
  int n,k,i,j;
  printf("Gauss Seidel Method\n");
  printf("Enter the matrix A and b in Ax=b as [A|b]: \n");
  for(i=0;i<3;i++)
    {
      for(j=0;j<4;j++)
	{
	  printf("enter the element (%d,%d): \n",i+1,j+1);
	  scanf("%f",A[i]+j);
	}
    }
  printf("enter the number of iterations: \n");
  scanf("%d",&n);
  printf("enter the initial guess: \n");
  for(i=0;i<3;i++)
    {
      printf("enter value of x(%d): \n",i+1);
      scanf("%f",x+i);
    }
  for(i=0;i<n;i++)
    {
      x[0]=(A[0][3]-(A[0][1]*x[1])-(A[0][2]*x[2]))/(A[0][0]);
      x[1]=(A[1][3]-(A[1][0]*x[0])-(A[1][2]*x[2]))/(A[1][1]);
      x[2]=(A[2][3]-(A[2][0]*x[0])-(A[2][1]*x[1]))/(A[2][2]);
      printf("%f,%f,%f\n",x[0],x[1],x[2]);
    }
  printf("the required vector is %f,%f,%f \n",x[0],x[1],x[2]);
  return 0;
}
      
