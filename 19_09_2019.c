#include <stdio.h>
#include <string.h>
int main()
{
  struct gospel
  {
    int num;
    char mess1[50];
    char mess2[50];
  }m;
  m.num=1;
  strcpy(m.mess1,"if all that you have is a hammer");
  strcpy(m.mess2,"Everything looks like a nail");
  printf("\n %ls%s%s",&m.num,m.mess1,m.mess2);
}

