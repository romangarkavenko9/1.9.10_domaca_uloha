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


void mat_unit(MAT *mat){
	
	int i,j;

		for(i=0;i<mat->rows;i++)
		{
			for(j=0;j<mat->cols;j++)
			{
				if(i==j)
				{
					ELEM(mat,i,j)= 1;
				}
				else
				{
					ELEM(mat,i,j)= 0;	
				} 	
	        
			}
			
		}
}


void mat_random(MAT *mat){
	
	int i,j;
	
		for(i=0;i<mat->rows;i++)
		{
			for(j=0;j<mat->cols;j++)
			{
				ELEM(mat,i,j)=(rand()/(float)(RAND_MAX)) * 2 - 1;
			}
		}
}

void mat_print(MAT *mat){
	
	int i,j;
	mat_unit(mat);
		for(i=0;i<mat->rows;i++)
		{
			for(j=0;j<mat->cols;j++)
			{
				printf(" %.f ",ELEM(mat,i,j));
			}
			
			printf("\n");
		}
		printf("\n");
	mat_random(mat);
		for(i=0;i<mat->rows;i++)
		{
			for(j=0;j<mat->cols;j++)
			{
				printf(" %f ",ELEM(mat,i,j));
			}
			
			printf("\n");
		}
}

int main(){
	
	unsigned int a,b;
	MAT* m;
	
	printf("zadaj pocet riadkov a pocet stlpcov:");
	scanf("%d %d",&a,&b);
	m=mat_create_with_type(a,b);
	m->cols=b;
	m->rows=a;
	
	float pole[m->cols*m->rows];
	m->elem=pole;

	mat_print(m);
	mat_destroy(m);
}

