#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct _VECTOR{
  int dim;
  float vec_arr[100];
};


float dot_product(struct _VECTOR vec_1,struct _VECTOR vec_2);
float cross_product(struct _VECTOR vec_1,struct _VECTOR vec_2);
int orthogonal_parallel(struct _VECTOR vec_1,struct _VECTOR vec_2);

int main()
{
  int i,N,ortho_parallel;
  struct _VECTOR  arr_1,arr_2;
  float scaler_product,cr_product;
  printf("enter the value of N: \n");
  scanf("%d",&N);
  arr_1.dim=N;
  arr_2.dim=N;
  printf("enter the first array: \n");
  for(i=0;i<arr_1.dim;i++)
    {
      printf("enter the element number %d for the first vector: \n",i+1);
      scanf("%f",&arr_1.vec_arr[i]);
    }
  printf("enter the second array: \n");
  for(i=0;i<arr_2.dim;i++)
    {
      printf("enter the element number %d for the first vector: \n",i+1);
      scanf("%f",&arr_2.vec_arr[i]);
    }
  scaler_product=dot_product(arr_1,arr_2);
  cr_product=cross_product(arr_1,arr_2);
  ortho_parallel=orthogonal_parallel(arr_1,arr_2);
  printf("Dot product of the two vectors is %f.\n",scaler_product);
  printf("Cross product of the two vectors is %f.\n",cr_product);
  switch(ortho_parallel)
    {
    case 0:
      printf("both vectors are zero vectors./n");
      break;
    case 1:
      printf("The vectors are orthogonal.\n");
      break;
    case 2:
      printf("The vectors are parelle.\n");
      break;
    case 3:
      printf("The vectors are neither orthogonal nor parellel.\n");
      break;
    default:
      break;
    }
  return 0;

}

float dot_product(struct _VECTOR arr_1,struct _VECTOR arr_2)
{
  int i;
  float scaler_product=0.0;
  for(i=0;i<arr_1.dim;i++)
    {
      scaler_product=(arr_1.vec_arr[i]*arr_2.vec_arr[i])+scaler_product;
    }
  return scaler_product;
}


float cross_product(struct _VECTOR arr_1,struct _VECTOR arr_2)
{
  int i;
  float cr_product,theta,As=0,Bs=0;
  for(i=0;i<arr_1.dim;i++)
    {
      As=pow(arr_1.vec_arr[i],2)+As;
      Bs=pow(arr_2.vec_arr[i],2)+As;
    }
  //theta=sin inverse of ((A.B)/|A|*|B|)
  theta=acos((dot_product(arr_1,arr_2)/(sqrt(As)*sqrt(Bs))));
  cr_product=(sqrt(As)*sqrt(Bs)*sin(theta));
  return cr_product;
}

int orthogonal_parallel(struct _VECTOR arr_1,struct _VECTOR arr_2)
{
  int return_val;
  if(dot_product(arr_1,arr_2)==0.0&&cross_product(arr_1,arr_2)==0.0)
    return 0;
  if(dot_product(arr_1,arr_2)==0.0)
    return 1;
  if(cross_product(arr_1,arr_2)==0.0)
    return 2;
  else
    return 3;
}


  
  
