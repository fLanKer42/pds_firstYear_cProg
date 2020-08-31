#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pop_Rec {
  int world_rank;
  char name[100];
  float pop;//in millions
  float yearly_change;
  int net_change;//in thousands
  int pop_density;//(prson/sq.Km)  
  struct Pop_Rec *next;
};
//done
int hash(char *country_name);
void append_list_innit(char *line,struct Pop_Rec* start,int count,char *rank,FILE* fptr);
void print_complete_list(struct Pop_Rec* start);
int search(char *name,struct Pop_Rec* start[7],int *count);
int append_allotRank(char* name,struct Pop_Rec* start[7],int *count);
int search_rank(char* name,struct Pop_Rec* start[7],int *count);
void lowest_pop_density(struct Pop_Rec* start[7],int *count);
void highest_yearly_change(struct Pop_Rec* start[7],int *count);
//pending


		   

int main()
{
  int i,a;
  float av;
  int count[7];
  char line[1000],name[1000];
  struct Pop_Rec *arr_list_starter[7],*temp;
  for(i=0;i<7;i++)
    arr_list_starter[i] = (struct Pop_Rec*)malloc(sizeof(struct Pop_Rec));

  //reading from file
  FILE *fptr;
  fptr = fopen("CountryStats.txt","r");
  if(fptr==NULL)
    {
      printf("error in opening file\n");
      exit(1);
    }
  for(i=0;i<7;i++)
    count[i]=0;
  while(fgets(line,1000,fptr)!=NULL)
    {
      fgets(name,1000,fptr);
      i=hash(name);
      append_list_innit(name,arr_list_starter[a],count[a],line,fptr);
      count[a]++;
    }
  fclose(fptr);
  

  //printing from the lists
  for(i=0;i<7;i++)
    {
      if(count[i]!=0)
	print_complete_list(arr_list_starter[i]);
    }

  // avrage length of lists
  for(i=0;i<7;i++)
    av=av+(float)(count[i]);
  av=av/7.0;
  printf("\nThe average length of lists is %f\n",av);

  //user interface
  int key;
  int rank;
  a=1;
  printf("\nIf you want to insert a country's data enter 0.\nIf you want to search for a country  enter 1.\nIf you want to find rank of a country enter 2.\nIf you want to find the country with lowest pop density enter 3.\nIf you want to find the country withhighest yearly change enter 4.\nIf you want list of countries in decending order of pop enter 5.\nIf you want list of countries in decending order of yearly change enter 6.\nIf you want list of countries in ascending order of pop density enter 7.\nIf you want list of countries in ascending order of net change enter 8.\nenter 9 or any other number to exit.\n");
  while(a>0)
    {
      
      scanf("%d",&key);
      switch(key) {
	//insert country
      case 0:
	printf("enter name of country: \n");
	scanf("%s",name);
	if(search(name,arr_list_starter,count)==1)
	  printf("already exists");
	else
	  append_allotRank(name,arr_list_starter,count);
	break;
	//search country
      case 1:
	printf("enter name of country: \n");
	scanf("%s",name);
	if(search(name,arr_list_starter,count)==0)
	  printf("Record not found\n");
	break;
	//find rank
      case 2:
	printf("enter country name: \n");
	scanf("%s",name);
	if(search_rank(name,arr_list_starter,count)==0)
	  printf("record not found");
	break;
	//find lowest pop. density
      case 3:
	lowest_pop_density(arr_list_starter,count);
	break;
	//find highest yearly change
      case 4:
	highest_yearly_change(arr_list_starter,count);
	break;
	//print descending order list of pop.
     
      case 9:
	a=-1;
	break;
      default:
	a=-1;
	break;
      }
    for(i=0;i<7;i++)
      {
	if(count[i]!=0)
	  print_complete_list(arr_list_starter[i]);
      }

    }
}

int hash(char *name)
{
  int sum,i=0;
  while(name[i]!='\0')
    {
      sum=name[i]+sum;
      i++;
    }
  return (sum%7);
}

void append_list_innit(char *line,struct Pop_Rec* start,int count,char *rank,FILE* fptr)
{
  struct Pop_Rec *new_node,*temp;
  int len;
  if (count==0)
    {
      len=strlen(line)-1;
      line[len]=0;
      start->world_rank=atoi(rank);
      strcpy(start->name,line);
      fgets(line,1000,fptr);
      start->pop=atof(line);
      fgets(line,1000,fptr);
      start->yearly_change=atof(line);
      fgets(line,1000,fptr);
      start->net_change=atoi(line);
      fgets(line,1000,fptr);
      start->pop_density=atoi(line);
      fgets(line,1000,fptr);
      start->next=NULL; 
    }
  else
    {
      new_node=(struct Pop_Rec*)malloc(sizeof(struct Pop_Rec));
      new_node->world_rank=atoi(rank);
      len=strlen(line)-1;
      line[len]=0;
      strcpy(new_node->name,line);
      fgets(line,1000,fptr);
      new_node->pop=atof(line);
      fgets(line,1000,fptr);
      new_node->yearly_change=atof(line);
      fgets(line,1000,fptr);
      new_node->net_change=atoi(line);
      fgets(line,1000,fptr);
      new_node->pop_density=atoi(line);
      fgets(line,1000,fptr);
      new_node->next=NULL;

      temp=start;
      while(temp->next!=NULL)
	temp=temp->next;
      temp->next=new_node;
    }
}
void print_complete_list(struct Pop_Rec* start)
{
  struct Pop_Rec* temp;
  temp=start;
  while(temp!=NULL)
    {
      printf("World Rank: %d\n",temp->world_rank);
      printf("Name of country: %s\n",temp->name);
      printf("Population(in millions): %f\n",temp->pop);
      printf("yearly change(percnetage): %f\n",temp->yearly_change);
      printf("net change: %d\n",temp->net_change);
      printf("population density(person per sq. km): %d\n\n",temp->pop_density);
      temp=temp->next;
    }
}
int search(char *name,struct Pop_Rec* start[7],int *count)
{
  int i;
  struct Pop_Rec* temp;
  for(i=0;i<7;i++)
    {
      if(count[i]!=0)
	{
	  temp=start[i];
	  while(temp!=NULL)
	    {
	      if(strcmp(temp->name,name)==0)
		{
		  printf("world rank: %d\n",temp->world_rank);
		  printf("Name of country: %s",temp->name);
		  printf("Population(in millions): %f\n",temp->pop);
		  printf("yearly change(percnetage): %f\n",temp->yearly_change);
		  printf("net change: %d\n",temp->net_change);
		  printf("population density(person per sq. km): %d\n\n",temp->pop_density);
		  return 1;
		}
	      else
		temp=temp->next;
	    }
	}
    }
  return 0;
}
int append_allotRank(char* name,struct Pop_Rec* start[7],int *count)
{
  int i,a,rank=1;
  a=hash(name);
  struct Pop_Rec* new_node,*temp,*node,*temp1,*temp2;
  if(count[a]!=0)
    {
      node=(struct Pop_Rec*)malloc(sizeof(struct Pop_Rec));
    }
  else
    node=start[a];
  if(node==NULL)
    {
      printf("node not created");
      exit(-1);
    }
  new_node=node;
  strcpy(new_node->name,name);
  printf("enter the population(in millions): \n");
  scanf("%f",&(new_node->pop));
  printf("enter the yearly change percentage: \n");
  scanf("%f",&(new_node->yearly_change));
  printf("enter the net change(in thousands): \n");
  scanf("%d",&(new_node->net_change));
  printf("enter the popultion density: \n");
  scanf("%d",&(new_node->pop_density));
 
  for(i=0;i<7;i++)
    {
      if(count[i]!=0)
	{
	  temp=start[i];
	  while(temp!=NULL)
	    {
	      if((temp->pop)>(new_node->pop))
		rank=1+(temp->world_rank);
	      temp=temp->next;
	    }
	}
    }
  
  new_node->world_rank=rank;
  new_node->next=NULL;
  for(i=0;i<7;i++)
    {
      if(count[i]!=0)
	{
	  
	  temp1=start[i];
	  while(temp1!=NULL)
	    {
	      if((temp1->world_rank)>rank||temp1->world_rank==rank)
		temp1->world_rank=temp1->world_rank+1;;
	      temp1=temp1->next;
	    }
	}
    }
 
  if(count[a]!=0)
    {
      
      temp2=start[a];
      while(temp2->next!=NULL)
	temp2=temp2->next;
      temp2->next=node;
    }
  count[a]++;
  return 0;
}
int search_rank(char* name,struct Pop_Rec* start[7],int *count)
{
  int i;
  struct Pop_Rec* temp;
  for(i=0;i<7;i++)
    {
      if(count[i]!=0)
	{
	  temp=start[i];
	  while(temp!=NULL)
	    {
	      if(strcmp(temp->name,name)==0)
		{
		  printf("Rank of the country is: %d\n",temp->world_rank);
		  return 1;
		}
	      else
		temp=temp->next;
	    }
	}
    }
  return 0;
}
void lowest_pop_density(struct Pop_Rec* start[7],int *count)
{
  int i,counter=0;
  struct Pop_Rec* temp,*low;
  for(i=0;i<7;i++)
    {
      if(count[i]!=0)
	{
	  
	  temp=start[i];
	  while(temp!=NULL)
	    {
	      if(counter==0)
		{
		  low=temp;
		  counter++;
		}
	      else
		if(low->pop_density>temp->pop_density)
		  low=temp;
	      temp=temp->next;
	    }
	}
    }
  printf("Country with lowest pop. density is: %s\n",low->name);
  printf("It's pop. density is: %d person per sq. km\n",low->pop_density);
}
void highest_yearly_change(struct Pop_Rec* start[7],int *count)
{
  int i,counter=0;
  struct Pop_Rec* temp,*high;
  for(i=0;i<7;i++)
    {
      if(count[i]!=0)
	{
	  
	  temp=start[i];
	  while(temp!=NULL)
	    {
	      if(counter==0)
		{
		  high=temp;
		  counter++;
		}
	      else
		if(high->yearly_change<temp->yearly_change)
		  high=temp;
	      temp=temp->next;
	    }
	}
    }
  printf("Country with highest yearly change is: %s.\n",high->name);
  printf("It's yearly change was: %f.\n",high->yearly_change);
}

  
	 
  
  
  
      
  
  
  
  
  
  
      
  
