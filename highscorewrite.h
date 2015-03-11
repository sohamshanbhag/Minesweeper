#include <iostream>
#include <cstdio>
#include<string.h>
using namespace std;

//declaration of structure
struct hs{
 char name[50];
 float time;
};
int main(){

hs newinfo;
cout<<"enter new name"; //New name
gets(newinfo.name);
int l=strlen(newinfo.name);
newinfo.name[l]='\n';

cin>>newinfo.time;
hs info[5];
FILE *fn;
fn=fopen("hsname.txt","r+");
FILE *ft;
ft=fopen("hstime.txt", "r+");
for(int i=0;i<5;i++){
fgets(info[i].name, 100,fn);
fscanf(ft, "%f", (&info[i].time));
}
for(int i=0;i<5;i++)
    cout<<info[i].name<<'\t'<<info[i].time<<endl;

int maxt=0;
for(int i=0;i<5;i++){
    if(info[i].time>newinfo.time){
        maxt=i;
        break;
    }
}

for(int i=4;i>maxt;i--){
    info[i]=info[i-1];
}
info[maxt]=newinfo;

rewind(fn);
rewind(ft);
//fn=fopen("hsname.txt","w");
//ft=fopen("hstime.txt", "w");
for(int i=0;i<5;i++){
    fputs(info[i].name, fn);
    fprintf(ft, "%f\n", info[i].time);
    }
}







