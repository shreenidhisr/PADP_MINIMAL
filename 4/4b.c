#include<stdio.h>
#include<gd.h>
#include<omp.h>

int main(int argc,char* argv[]){
    char *iname,*oname;
    iname=argv[1];
    oname=argv[2];

    FILE* fp=fopen(iname,"r");
    gdImagePtr img;
    img=gdImageCreateFromPng(fp);

    int w,h;
    w=gdImageSX(img);
    h=gdImageSY(img);

    omp_set_num_threads(4);

    int x,y,color,red,green,blue,temp,tid;

    #pragma omp parallel for private(y,color,red,green,blue) schedule(static,50)
    for(x=0;x<w;x++){
        for(y=0;y<h;y++){

            tid=omp_get_thread_num();

            color=gdImageGetPixel(img,x,y);

            red=gdImageRed(img,color);
            green=gdImageGreen(img,color);
            blue=gdImageBlue(img,color);

            temp=(red+green+blue)/3;

            if(tid==0){
                color=gdImageColorAllocate(img,temp,0,0);
                gdImageSetPixel(img,x,y,color);
            }
            if(tid==1){
                color=gdImageColorAllocate(img,0,temp,0);
                gdImageSetPixel(img,x,y,color);
            }
            if(tid==2){
                color=gdImageColorAllocate(img,0,0,temp);
                gdImageSetPixel(img,x,y,color);
            }
        }
    }
    fp=fopen(oname,"w");
    gdImagePng(img,fp);
}
