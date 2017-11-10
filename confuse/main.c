#include <stdio.h>
#include <stdlib.h>

// TODO 个人认为应该是数组最大空间的问题，
//      而不是原帖子中三层循环顺序的问题
int confuse1(void)
{
 int a[60][250][1000],i,j,k;  
 for(k=0;k<=1000;k++)  
   for(j=0;j<250;j++)  
     for(i=0;i<60;i++)  
       a[i][j][k]=0; 
  return 0;
}

// float 类型是不精确的
int test()
{
  const float f = 99.9;
  printf("f = %f\n", f);
  printf("f == 99.9 %d\n", (f == 99.9)); // return FALSE
  printf("f - 99.9 = %f\n", (f - 99.9));
  printf("1e-6 = %f\n", 1e-6);
  printf("f == 99.9 %d\n", abs(f - 99.9)<= 1e-6); // return TRUE
  return 0;
}

int length()
{
 char str[] = "http://www.ibegroup.com/";
 printf("sizeof is: %d\n", sizeof(str));
 return 0;
}

int main()
{
  //confuse1();
  //test();
  length();
}
