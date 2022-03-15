#include<stdio.h>
#include<omp.h>
#include<mpi.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
    int rank;
    double st;
    int itr=100000;
    double x,y,pi;
    int count=0,i;
    int reduced_count;
    int reduced_itr;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if(rank==0){
        st=omp_get_wtime();
        
    }
    if(rank>0){
        for(i=1;i<itr;i++){
            x=(double)rand()/RAND_MAX;
            y=(double)rand()/RAND_MAX;
            if(x*x+y*y<=1){
                count++;
            }
        }   
    }
    MPI_Reduce(&count,&reduced_count,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    MPI_Reduce(&itr,&reduced_itr,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    reduced_itr-=itr;
    if(rank==0){
        printf("%d\n",reduced_count);
        printf("%d\n",reduced_itr);
        pi=(double)reduced_count/reduced_itr*4;
        printf("%f\n",pi);
    }
    MPI_Finalize();
}
