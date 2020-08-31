#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct _COMPLEX
{
  float real,imag;
};

float Compute_magnitude(struct _COMPLEX num);
float Compute_phase(struct _COMPLEX num);
void SortComplexNumbers(struct _COMPLEX* arr,int n,int mode);
void printComplexNumber(struct _COMPLEX num);
void readComplexNumber(struct _COMPLEX *num);

int main()
{
  int n,i;
  struct _COMPLEX *comp_arr;
  printf("enter the value of n: \n");
  scanf("%d",&n);
  if((comp_arr=(struct _COMPLEX*)malloc(n*sizeof(struct _COMPLEX)))==NULL)
    {
      printf("\n memory not allocated");
      exit(1);
    }
  printf("now enter the complex numbers: \n");
  for(i=0;i<n;i++)
    {
      readComplexNumber(comp_arr+i);
    }
  i=0;
  while(i<n)
    {
      if(i%5!=0)
	{
	  printComplexNumber(comp_arr[i]);
	  printf(",");
	  i++;
	}
      if(i%5==0)
	{
	  printf("\n");
	  printComplexNumber(comp_arr[i]);
	  printf(",");
	  i++;
	}
    }

  SortComplexNumbers(comp_arr,n,0);
  i=0;
  while(i<n)
    {
      if(i%5!=0)
	{
	  printComplexNumber(comp_arr[i]);
	  printf(",");
	  i++;
	}
      if(i%5==0)
	{
	  printf("\n");
	  printComplexNumber(comp_arr[i]);
	  printf(",");
	  i++;
	}
    }
  
  SortComplexNumbers(comp_arr,n,1);
  i=0;
  while(i<n)
    {
      if(i%5!=0)
	{
	  printComplexNumber(comp_arr[i]);
	  printf(",");
	  i++;
	}
      if(i%5==0)
	{
	  printf("\n");
	  printComplexNumber(comp_arr[i]);
	  printf(",");
	  i++;
	}
    }
  printf("\n");
  return 0;
}

float Compute_magnitude(struct _COMPLEX num)
{
  float ret_val;
  ret_val=sqrt(pow(num.real,2) + pow(num.imag,2));
  return ret_val;
}


float Compute_phase(struct _COMPLEX num)
{
  float ret_val;
  ret_val= atan((num.imag)/num.real);
  return ret_val;
}


void printComplexNumber(struct _COMPLEX num)
{
  printf("%f+i%f",num.real,num.imag);
}

void readComplexNumber(struct _COMPLEX *num)
{
  printf("real part: \n");
  scanf("%f",&(num->real));
  printf("imaginary part: \n");
  scanf("%f",&(num->imag));
}

void SortComplexNumbers(struct _COMPLEX *num,int n,int mode)
{
  int i,j,k;
  struct _COMPLEX temp;
  if(mode==0)
    {
       for(i=0;i<n;i++)
	 {
	   k=i;
	   for(j=i+1;j<n;j++)
	     {
	       if(Compute_magnitude(num[k])>Compute_magnitude(num[j]))
		 k=j;
	     }
	   temp=num[i];
	   num[i]=num[k];
	   num[k]=temp;
	 }
    }
  if(mode!=0)
    {
       for(i=0;i<n;i++)
	 {
	   k=i;
	   for(j=i+1;j<n;j++)
	     {
	       if(Compute_phase(num[k])>Compute_phase(num[j]))
		 k=j;
	     }
	   temp=num[i];
	   num[i]=num[k];
	   num[k]=temp;
	 }
    }
}
	  
  
  
  
  
