#include <iostream>
#include <vector>

using namespace std;

template<typename Object>
class matrix{
    public:
        matrix(int r) : array(r){}
        const Object& operator[](int i) const{ return mat[i];}
        Object& operator[](int i){return mat[i];}

    private:
        vector<vector<Object>> mat;
};

int main(){

    matrix<int> mat(2);


}