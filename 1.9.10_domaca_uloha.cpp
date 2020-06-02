#include <stdio.h>
#include <stdlib.h>
typedef struct{
	unsigned int rows;
	unsigned int cols;
	float *elem;
}MAT;

#define ELEM(M,r,c) (M->elem[(M->cols)*r+c])

MAT* mat_create_with_type(unsigned int rows, unsigned int cols){

	MAT* m=(MAT*)malloc(sizeof(float)*rows*cols);

	if( m == NULL )
	{
		free(m);
		return NULL;
	}
	else
	return m;
}

void mat_destroy(MAT *mat){
	
	free(mat);
}

void mat_random(MAT *mat){
	
	int i,j;
	float a;
	float pole[mat->cols*mat->rows];
	mat->elem=pole;
		for(i=0;i<mat->rows;i++)
		{
			for(j=0;j<mat->cols;j++)
			{
				ELEM(mat,i,j)=(rand()/(float)(RAND_MAX)) * 2 - 1;
			}
		}
}



int main(){
	
	unsigned int a=2,b=2;
	MAT* m;
	
	m=mat_create_with_type(a,b);
	
	m->cols=2;
	m->rows=2;
	mat_random(m);

	mat_destroy(m);
}

