#include<iostream>
#include<vector>
using namespace std;
class HighArray{
    private:
        vector<double>v;
        int nElems;
    public:
        HighArray(): nElems(0){}
        HighArray(int max): nElems(0){ // 1 argument -> constructor
            v.resize(max);
        }
};
