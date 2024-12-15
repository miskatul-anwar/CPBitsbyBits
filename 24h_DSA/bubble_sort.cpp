#include <iostream>
#include <vector>
using namespace std;
template<typename T>class ArrayBub{
    private:
        vector<T>v;
        int nElems;
        void swap(int one, int two){
            T temp = v[one];
            v[one]=temp;
        }
    public:
        ArrayBub(int max):nElems(0){
            v.resize(max);
        }
        void insert(T value){
            v[nElems] = value, nElems++;
        }
        void display(){
            for(int j=0;j<nElems;j++){
                cout<<v[j]<<' ';
            }
            cout<<'\n';
        }
        void bubblesort(){
            int out, in;
            for(out= nElems-1;out>1;out--){
                if(v[in]>v[in+1]){
                    swap(in,in+1);
                }
            }
        }

};
