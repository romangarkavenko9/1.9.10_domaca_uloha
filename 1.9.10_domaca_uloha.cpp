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

	MAT* m=(MAT*)malloc(sizeof(MAT)*rows*cols);

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
			{   if(ELEM(mat,i,j)<0)
				{
				printf("%.3f  ",ELEM(mat,i,j));	
				}
				else
				printf(" %.3f  ",ELEM(mat,i,j));
			}
			
			printf("\n");
		}
	printf("\n");
}

float det_pre_2x2(MAT *mat){
	float ab;
	
	if(mat->cols==2 && mat->rows==2 )
	{
		ab=ELEM(mat,0,0)*ELEM(mat,1,1)-ELEM(mat,0,1)*ELEM(mat,1,0);
	}
		
}



void swap(float *a, float *b) 
{ 
    float t = *a; 
    *a = *b; 
    *b = t; 
} 
  



float mat_determinant(MAT *mat){
  
float cislo1,cislo2,det = 1,celok = 1;
int g;    
        
      
   float pole[mat->rows + 1];   
        
     
    for(int i = 0; i < mat->rows; i++)    
    {  
        g = i;   
            
        while(ELEM(mat,g,i) == 0 && g < mat->rows) {   
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
             
       for(int j = 0; j < mat->rows; j++)   
       {   
           pole[j] = ELEM(mat,i,j);        
       }   
    
       for(int j = i+1; j < mat->rows; j++)   
       {   
           cislo1 = pole[i];    
           cislo2 = ELEM(mat,j,i);    
                  
           for(int k = 0; k < mat->rows; k++)   
           {      
               ELEM(mat,j,k) = (cislo1 * ELEM(mat,j,k)) - (cislo2 * pole[k]);           
           }   
           celok = celok * cislo1;    
           }   
            
    }   
      
    for(int i = 0; i < mat->rows; i++)   
    {   
        det = det * ELEM(mat,i,i);   
            
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
	
	float pole[m->cols*m->rows];
	m->elem=pole;

	mat_print(m);
	ad=mat_determinant(m);
	printf("determinant matice= %.3f",ad);

	mat_destroy(m);
	
}

