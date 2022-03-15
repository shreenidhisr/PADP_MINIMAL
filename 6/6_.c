#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char search_word[20][10]={"Hi","where","given","get","low","The","there","just","hello","hey"};
int count[10];


int is_alpha(char c){
    return ((c>=65 && c<=90) || (c>=97 && c<=122));
}

int check_equal(char *a,char *key,int ign){
    char b[20];
    strcpy(b,key);
    int len_a=strlen(a);
    int len_b=strlen(b);
    int i;
    if(len_a!=len_b){
        return 0;
    }


    //convert all to perticular case if ign=1
    if(ign==1){
        for(i=0;i<len_a;i++){
            if(a[i]>90){
                a[i]-=32;
            }
        }

        for(i=0;i<len_b;i++){
            if(b[i]>90){
                b[i]-=32;
            }
        }
    }

    return strcmp(a,b)==0;
}

void read_word(char *tmp,FILE* fp){
    char ch;
    int i=0;

    while((ch=fgetc(fp))!=EOF && is_alpha(ch)==0){

    }

    while(ch!=EOF && is_alpha(ch)==1){
        tmp[i++]=ch;
        ch=fgetc(fp);
    }
    tmp[i]='\0';
}

int determine_count(char *key,char* filename,int ign){
    FILE* fp=fopen(filename,"r");
    char temp[20];
    int count=0;

    while(feof(fp)==0){
        read_word(temp,fp);
        if(check_equal(temp,key,ign)!=0){
            count++;
        }
    }
    return count;
}

int main(){
   int i;

   for(i=0;i<10;i++){
       count[i]=determine_count(search_word[i],"1.txt",1);
   }

   for(i=0;i<10;i++){
       printf("%s : %d\n",search_word[i],count[i]);
   }
}
