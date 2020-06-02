#include <stdio.h>
#include <stdlib.h>
typedef struct{
unsigned int rows;
unsigned int cols;
float *elem;
}MAT;
#define ELEM(M,r,c) (M.elem[(M.cols)*r+c])

MAT* mat_create_with_type(unsigned int rows, unsigned int cols){

MAT* m=(MAT*)malloc(sizeof(float)*rows*cols);

if( m == NULL ){
free(m);
return NULL;
}
else{
return m;
}
}

void mat_destroy(MAT *mat){
free(mat);
}

void mat_random(MAT *mat){
unsigned int rows,cols;
MAT* s;
s=mat_create_with_type( rows, cols);
int i,j;
float a;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			a=((float)rand() / (RAND_MAX))-0.5;
			printf("%f ",a);	
		}
	}
}



int main(){
unsigned int a,b;
MAT* m;
int* c;
a=3;
b=2;
m=mat_create_with_type(a,b);
printf("%d",m);
mat_random(m);
mat_destroy(m);
printf(" %d",m);
}

