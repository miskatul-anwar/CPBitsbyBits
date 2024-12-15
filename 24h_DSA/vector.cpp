#include<stdlib.h>
#include<stdio.h>
template<typename T>class vector{
    private:
        T*v;
        size_t size;
    public:
        vector(size_t max):size(0){
            v=(T*)malloc(size*sizeof(T));
        }
        void insert(size_t index, T value){
            v[index]= value;
        }
        void display(){
            for(size_t i=0;i<size;i++){
                printf("%d ",v[i]);
                printf("\n");
            }
        }
};
int main(){
    vector<int>v(2);
    v.insert(0,2);
    v.insert(1,6);
    v.display();
    return 0;
}
