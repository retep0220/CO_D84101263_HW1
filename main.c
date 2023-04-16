//
//  main.c
//  co2
//
//  Created by 王吉朗 on 2023/4/9.
//

// description: cn = an - bn
#include <stdio.h>
int main () {
    int a[10] = {0}, b[10]= {0}, c[10] = {0};
    int i, arr_size = 10;
    FILE *input = fopen("../input/2.txt","r");
    for(i = 0; i<arr_size; i++) fscanf(input, "%d", &a[i]);
    for(i = 0; i<arr_size; i++) fscanf(input, "%d", &b[i]);
    for(i = 0; i<arr_size; i++) fscanf(input, "%d", &c[i]);
    fclose(input);
    int *p_a = &a[0];
    int *p_b = &b[0];
    int *p_c = &c[0];
    /* Original C code segment
    for (int i = 0; i < arr_size; i++){
        *p_c++ = *p_a++ - *p_b++;
    }
*/
    for (int i = 0; i < arr_size; i++)
        asm volatile("movl (%[A], %[I], 4), %%eax\n\t" // Load a[i] into register %eax
                     "subl (%[B], %[I], 4), %%eax\n\t" // Subtract b[i] from %eax
                     "movl %%eax, (%[C], %[I], 4)\n\t" // Store the result in c[i]
                     : [I] "+r" (i) // i is an input and output operand
                     : [A] "r" (a), [B] "r" (b), [C] "r" (c) // a, b, c are read-only operands
                     : "memory" // %eax and memory are clobbered
                     );
    p_c = &c[0];
    for (int i = 0; i < arr_size; i++)
        printf("%d ", *p_c++);
    return 0;
}
