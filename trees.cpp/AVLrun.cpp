#include <iostream>
#include "AVL.cpp"

using namespace std;

int main(){
    AVL<int> avl;

    int n;
    cin >> n;

    cout << "Enter " << n << " Numbers to insert in AVL" << endl;
    int k;
    for(int i=0;i<n;++i){
        cin >> k;
        avl.insert(k);
    }

    avl.printTree();

    cout << "\nEnter a int to delete" << endl;
    cin >> k;
    avl.remove(k);

    avl.printTree();

    cout << "\nMinimum element "<< avl.findMin() << endl;
    
    cout  << "Maximum element "<< avl.findMax() << endl;

    cout << "\nSum is " << avl.sum() << endl;

}