#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
  
    int i,n=1000;
    double x,y;
    double pi,st,end;

    int l;
    while(n<10000){
        printf("\nn:%d\n",n);
        for(l=1;l<=8;l=l*2){
            printf("threads:%d\t",l);
            double count=0;
        
            st=omp_get_wtime();
            omp_set_num_threads(l);
            #pragma omp parallel for 
            for(i=1;i<n;i++){
                x=(double)rand()/RAND_MAX;
                y=(double)rand()/RAND_MAX;
                if(x*x + y*y <=1 ){
                    count++;
                }
            }
            pi =(double) count / n*4;
            end=omp_get_wtime();

            printf("pi:%f\t",pi);
            printf("time:%f\n",end-st);
        }
        n+=1000;
    }
  
}