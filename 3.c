//
//  main.c
//  co3
//
//  Created by 王吉朗 on 2023/4/9.
//

#include<stdio.h>
int main() {
  int f,i=0;
  int h[9]={0}, x[3]={0}, y[3]={0};
  FILE *input = fopen("../input/3.txt","r");
  for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
  for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
  for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
  fclose(input);
  int *p_x = &x[0] ;
  int *p_h = &h[0] ;
  int *p_y = &y[0] ;
  for (i = 0 ; i < 3; i++)
    {
      p_x = &x[0]  ;
      for (f = 0 ; f < 3; f++)
        asm volatile("movl (%[X], %[F]%3, 4), %%eax/n/t"
                     "sub (%[Y], %[I], 4), (%[H], %[F], 4), "
                     );
    }
  p_y = &y[0];
  for(i = 0; i<3; i++)
    printf("%d \n", *p_y++);
  return(0)  ;
}
