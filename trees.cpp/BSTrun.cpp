#include <iostream>
#include "BST.cpp"

using namespace std;

int main(){
    BinarySearchTree<int> bst;

    int n;
    cin >> n;

    cout << "Enter " << n << " Numbers to insert in BST" << endl;
    int k;
    for(int i=0;i<n;++i){
        cin >> k;
        bst.insert(k);
    }

    bst.printTree();

    cout << "\nEnter a int to delete" << endl;
    cin >> k;
    bst.remove(k);

    bst.printTree();

    cout << "\nMinimum element "<< bst.findMin() << endl;
    
    cout  << "Maximum element "<< bst.findMax() << endl;

    cout << "\nSum is " << bst.sum() << endl;

    cout << "height of the Tree " << bst.height() << endl;

    for(int i=1;i<=bst.height();++i){
        bst.BFS(i);
    }
    

}