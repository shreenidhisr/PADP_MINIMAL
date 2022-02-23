#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void print_matrix(int *arr[],int a,int b){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int a,b,m,n,i,j,k;

    printf("enter a & b:");
    scanf("%d%d",&a,&b);

    printf("enter c & d:");
    scanf("%d%d",&m,&n);
    
    int *arr1[100],*arr2[100];

    for(i=0;i<a;i++){
        arr1[i]=(int *)malloc(b*sizeof(int));
    }

    for(i=0;i<m;i++){
        arr2[i]=(int *)malloc(n*sizeof(int));
    }

    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            arr1[i][j]=rand()%10;
        }
    }
    print_matrix(arr1,a,b);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            arr2[i][j]=rand()%10;
        }
    }
    print_matrix(arr2,m,n);

    int *arr3[100];
    for(i=0;i<a;i++){
        arr3[i]=(int *)malloc(n*sizeof(int));
    }


    for(i=0;i<a;i++){
        for(j=0;j<n;j++){
            arr3[i][j]=0;
            for(k=0;k<b;k++){
                arr3[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }

    print_matrix(arr3,a,n);
}