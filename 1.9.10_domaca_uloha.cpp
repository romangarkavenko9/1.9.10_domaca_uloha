#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct{
	unsigned int rows;
	unsigned int cols;
	float *elem;
}MAT;

#define ELEM(M,r,c) (M->elem[(M->cols)*r+c])   

MAT* mat_create_with_type(unsigned int rows, unsigned int cols){

	MAT* m=(MAT*)malloc(sizeof(MAT));
	if( m == NULL ) 
	{
		return NULL;	
	}
	
	m->elem=(float*)malloc(sizeof(float)*rows*cols);
	if( m->elem == NULL )
	{
		free(m);
		return NULL;			
	}
	
	else return m;
}

void mat_destroy(MAT *mat){

	free(mat->elem);
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
	
	for(i=0;i<mat->rows;i++)
	{
		for(j=0;j<mat->cols;j++)
		{   
			if(ELEM(mat,i,j)<0)
			{
				printf("%.3f  ",ELEM(mat,i,j));	
			}
			else
			{
				printf(" %.3f  ",ELEM(mat,i,j));
			}		
		}	
		printf("\n");
	}	
	printf("\n");
}

void swap(float *a, float *b){ 
    float t = *a; 
    *a = *b; 
    *b = t; 
}

float mat_determinant(MAT *mat){
  
	float cislo1,cislo2,det = 1,celok = 1;
	int g,j=0,i=0; 
   
	float* a; 
	a = &ELEM(mat,i,j); 
		
		if(mat->cols!=mat->rows)
		{
		return 0;	
		}
	        
	    if (mat->rows==1 && mat->cols==1)
		{
			det=ELEM(mat,0,0);
			return det;	
		}
		if (mat->cols==0 && mat->rows==0)
		{
			return 0;	
		}
		
		
		
		else
		{
			for(int i = 0; i < mat->rows; i++)    
	    	{ 
				g = i;   

	        	while(ELEM(mat,g,i) == 0 && g < mat->rows) 
				{   
	            	g++;       
	            }

	        	if(g == mat->rows)   
	        	{     
	            	continue;          
	        	} 

	        	if(g != i)   
	        	{     
	            	for(int j = 0; j < mat->rows; j++)   
	            	{   
	                	swap(&ELEM(mat,g,j),&ELEM(mat,i,j));      
	            	}   

	            	det = det*pow(-1,g-i);     
	       		}    
	        	   
	           	        
	       		   	    
	       		for(int j = i+1; j < mat->rows; j++)   
	       		{   
	           		cislo1 = a[i];    
	           		cislo2 = ELEM(mat,j,i);    
	                  
	           		for(int k = 0; k < mat->rows; k++)   
	           		{      
	               		ELEM(mat,j,k) = (cislo1 * ELEM(mat,j,k) - (cislo2 * a[k]));           
	           		}
					      
	           	   	celok = celok * cislo1;    
	           	}   
	            
	    	}   
	      
	    	for(int i = 0; i < mat->rows; i++)   
	    	{   
	        	det = det * ELEM(mat,i,i);   
	        } 
		}
	return (det/celok);  
}   



int main(){
	srand(time(NULL));
	unsigned int a,b;
	float ad;
	MAT* m;
	
	printf("zadaj pocet riadkov a pocet stlpcov:");
	scanf("%d %d",&a,&b);
	m=mat_create_with_type(a,b);
	m->cols=b;
	m->rows=a;
	
	mat_unit(m);
	mat_print(m);
	
 	mat_random(m);
	mat_print(m);
	if (m->cols!=0 && m->rows!=0)
	{	
		if(m->cols==m->rows)
		{
			ad=mat_determinant(m);
			printf("determinant matice= %.3f",ad);
		}
		else printf("determinant sa neda vypocitat, matica nema tvar n*n");
	}
	else printf("determinant sa neda pocitat lebo nie su ziadne cisla");
	mat_destroy(m);
	
}

