#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

struct dirent* dptr;

int main(int argc,char* argv[]){
    char buff[100];
    DIR* dirp;
    printf("\n\nEnter the directory name: ");
    scanf("%s",buff);
    if((dirp=opendir(buff))==NULL){
        printf("\n\nError opening directory");
        exit(1);
    }
    while(dptr=readdir(dirp)){
        printf("\n%s",dptr->d_name);
    }
    closedir(dirp);
}