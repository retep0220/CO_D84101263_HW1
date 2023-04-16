//
//  main.c
//  co4
//
//  Created by 王吉朗 on 2023/4/16.
//

// description: matrix muliply without for loop
#include<stdio.h>


int main() {
  int i=0;
  int h[9]={0}, x[3]={0}, y[3]={0};
  FILE *input = fopen("../input/4.txt","r");
  for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
  for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
  for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
  fclose(input);
  int *p_x = &x[0] ;
  int *p_h = &h[0] ;
  int *p_y = &y[0] ;
  asm volatile("");
  p_y = &y[0];
  for(i = 0; i<3; i++)
    printf("%d \n", *p_y++);
  return(0)  ;
}
