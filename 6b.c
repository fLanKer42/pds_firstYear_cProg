#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float compute_mean(float* Arr,int N);
float compute_mean_squares(float* Arr,int N);

int main()
{
  int i,N;
  float* Arr;
  float mean,variance,std_dev;
  /*input*/
  printf("Enter the number of elemnents in the array: \n");
  scanf("%d",&N);
  Arr=(float*)malloc(N*sizeof(float));
  for(i=0;i<N;i++)
    {
      printf("Enter the element number %d: \n",i+1);
      scanf("%f",&Arr[i]);
    }
  /*calling mean function*/
  mean=compute_mean(Arr,N);
  /*using formula forvariance and standard deviation*/
  variance=compute_mean_squares(Arr,N)-(mean*mean);
  std_dev= sqrt(variance);
  /*output*/
   printf("The mean of the array is %f. \n",mean);
  printf("The standard deviation of the array is %f.\n",std_dev);
  return 0;
}

float compute_mean(float* A,int n)
{
  /*summing all elements in the array and dividing by n*/
  int i;
  float sum=0;
  for(i=0;i<n;i++)
    {
      sum+=A[i];
    }
  return sum/n;
}

float compute_mean_squares(float* A,int n)
{
  /*summing the squares of all the elements and dividing by n*/
  int i;
  float sum=0;
  for(i=0;i<n;i++)
    {
      sum+=(A[i]*A[i]);
    }
  return sum/n;
}

  
