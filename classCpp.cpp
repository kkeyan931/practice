#include <iostream>
#include <vector>

using namespace std;

class Vector
{
private:
    double *elem;
    int size;
    int k=0;

public:
    Vector(int size) : elem{new double[size]}, size{size} {}
    double &operator[](int i) { return elem[i]; }
    int sizeN() { return size; }
    double &getE(int i){return elem[i];}
    void setE(double i){ elem[k]=i ;k++;}
};

int main()
{

    Vector *v = new Vector(5);
    for (int i = 0; i != v->sizeN(); ++i){
        int k;
        cin >> k;
        v->setE(k);
    }

    // double sum = 0;
    // for (int i = 0; i != v->sizeN(); ++i)
    //     sum = sum + v[i];
   
    // cout << sum << endl;
    cout << v->getE(1) << endl;

    
}