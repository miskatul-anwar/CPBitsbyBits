#include<iostream>
#include<vector>

template<typename T>class OrdArray{
    private:
        std::vector<T>v;
        int nElems;
    public:
        OrdArray(int max): nElems(0){
            v.resize(max);
        }
        int getSize(){
            return nElems;
        }
        int find(T searchkey){
            int lowerBound=0, upperBound=nElems-1, curIn;
            while(true){
                curIn = (lowerBound+upperBound)/2;
                if(v[curIn]==searchkey){
                    return curIn;
                }else if(lowerBound>upperBound){
                    return nElems;
                }else{
                    if(v[curIn]<searchkey){
                        lowerBound = curIn + 1;
                    }else{
                        upperBound = curIn - 1;
                    }
                }
            }
        }
        void insert(T value){
            int j;
            for(j=0;j<nElems;j++){
                if(v[j>value]){
                    break;
                }
            }
            for(int k=nElems;k>j;k--){
                v[k] = v[k-1];
            }
            v[j]=value,nElems++;
        }
        bool remove(T value){
            int j = find(value);
            if(j==nElems){
                return false;
            }else{
                for(int k=j;k<nElems;k++){
                    v[k]=v[k+1];
                }
                nElems--;
                return true;
            }
        }
        void display(){
            for(int j=0;j<nElems;j++){
                std::cout<<v[j]<<' ';
            }
            std::cout<<'\n';
        }
};

int main(void){
    int maxSize = 100;
    OrdArray<double>arr(maxSize);
    arr.insert(77);
    arr.insert(89);
    arr.insert(99);
    arr.insert(22);
    arr.insert(66);
    int key = 55;
    if(arr.find(key)!=arr.getSize()){
        std::cout<<"Found "<<key<<'\n';
    }else{
        std::cout<<"Can't find "<<key<<'\n';
    }
    arr.display();
    arr.remove(99);
    arr.display();
    return 0;
}
