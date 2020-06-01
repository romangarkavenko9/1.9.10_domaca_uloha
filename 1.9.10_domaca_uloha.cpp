#include <stdio.h>
#include <stdlib.h>
typedef struct{
unsigned int rows;
unsigned int cols;
float *elem;
}MAT;
#define ELEM(M,r,c) (M.elem[(M.cols)*r+c])

MAT* mat_create_with_type(unsigned int rows, unsigned int cols){

MAT* m=(MAT*)malloc(sizeof(MAT)*rows*cols);

if( m == NULL ){
free(m);
return NULL;
}
else{
return m;
}
}

int main(){
unsigned int a,b;
MAT* m;
int* c;
mat_create_with_type(a,b);
}

