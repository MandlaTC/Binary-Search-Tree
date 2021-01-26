#include <iostream>

using namespace std;

class TreeNode{
public:
    // Pointer to the left child
    //  Initialised to nullptr (this syntax is a new C++11 feature)
    TreeNode* left = nullptr;
    // Pointer to the right child
    //  Initialised to nullptr (this syntax is a new C++11 feature)
    TreeNode* right = nullptr;

    // Value in the node
    int value;

    // Constructor, sets the value
    TreeNode(int v) : value(v) {}
    // Destructor, nifty trick to recursively delete all the nodes
    //  be careful though, when you delete just a single node, make
    //  sure that you set left and right = nullptr first
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Tree{
private:
    TreeNode* root = nullptr;

public:
    // These functions do the actual work
    void insert(int v, TreeNode* &subtree){
        if(subtree == nullptr){
           subtree = new TreeNode(v);
        }else if(v < subtree->value){
            insert(v, subtree->left);
        }else{
            insert(v, subtree->right);
        }
    }

    void preOrderTraversal(TreeNode* subtree) const{

    }

    void inOrderTraversal(TreeNode* subtree) const{

    }

    void postOrderTraversal(TreeNode* subtree) const{

    }

    int min(TreeNode* subtree) const{
        int min;
        TreeNode *curr;
        if (subtree!=nullptr){
            min = subtree->value;
            curr = subtree;
            while (curr->left!=nullptr){
                curr = subtree->left;
                min = curr->value;
            }
        }
        return min;
    }
    int max(TreeNode* subtree) const{
        int max; 
        TreeNode *curr; 
        if (subtree!=nullptr){
            curr = subtree;
            max = subtree->value;
            while (curr->right!=nullptr){
                curr = curr->right;
                max = curr->value;
            }
        }
    }
    bool contains(int value, TreeNode* subtree) const{

    }
    void remove(int value, TreeNode* &subtree){

    }

    void insert(int value){
        insert(value, root);
    }

    void preOrderTraversal(){
        preOrderTraversal(root);
        cout << endl;
    }
    void inOrderTraversal(){
        inOrderTraversal(root);
        cout << endl;
    }
    void postOrderTraversal(){
        postOrderTraversal(root);
        cout << endl;
    }
    int min(){
        return min(root);
    }
    int max(){
        return max(root);
    }
    bool contains(int value){
        return contains(value, root);
    }
    void remove(int value){
        remove(value, root);
    }
    ~Tree(){
        // This ends up deleting all the nodes recursively.
        delete root;
    }
};

int main(){
    Tree t;
    int value;
    // Sample code to read and construct the tree.
    while(cin >> value && value != -1){
        t.insert(value);
    }

    // Do some stuff...
    cout<<t.min()<<endl<<t.max();

}
