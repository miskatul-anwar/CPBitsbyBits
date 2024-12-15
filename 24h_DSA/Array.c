#include<stdio.h>
#include<stdlib.h>

typedef struct vector{
    int* v=(int*) malloc(10*sizeof(int));
    void set_element(int index,int element){
        v[index]=element;
    }
    int get_element(int index){
        if(v != NULL and v[index]!=0){
            return v[index];
        }
        return -1;
    }
    void show_all(){
        for(int i=0;*(v+i)!=0;i++){
            printf("%d ",v[i]);
        }
    }
}vector;

int main(void){
    vector v;
    v.set_element(0,5);
    v.set_element(1,6);
    v.set_element(2,7);
    v.set_element(3,8);
    v.set_element(4,9);
    printf("%d ",v.get_element(1));
    return 0;
}
