#include<bits/stdc++.h>
using namespace std;
#define makeIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define EDL std::cout<<endl;
typedef long long ll;

template <class T>
struct TreeNode{
    T key;
    TreeNode* left;
    TreeNode* right;
    int size;  // Size of the tree rooted at this node
    int count; // Number of occurrences of this node's key
    TreeNode(T value) : key(value), left(nullptr), right(nullptr), size(1), count(1) {}
};

template <class T>
struct BinarySearchTree{
    TreeNode<T>* root = nullptr;

    void init(){ root = nullptr;}
    void insert(int value) {
        root = insert(root, value);
    }
    void remove(int value) {
        root = remove(root, value);
    }

    TreeNode<T>* insert(TreeNode<T>* node, int value){
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }
        if (value < node->key) {
            node->left = insert(node->left, value);
        } else if (value > node->key) {
            node->right = insert(node->right, value);
        } else {
            node->count++;
        }
        node->size = (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0) + node->count;
        return node;
    }

    TreeNode<T>* remove(TreeNode<T>* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->key) {
            node->left = remove(node->left, value);
        } else if (value > node->key) {
            node->right = remove(node->right, value);
        } else {
            if (node->count > 1) {
                node->count--;
            } else {
                if (node->left == nullptr) {
                    TreeNode<T>* temp = node->right;
                    delete node;
                    return temp;
                } else if (node->right == nullptr) {
                    TreeNode<T>* temp = node->left;
                    delete node;
                    return temp;
                } else {
                    TreeNode<T>* successor = findMinNode(node->right);
                    node->key = successor->key;
                    node->count = successor->count;
                    node->right = remove(node->right, successor->key);
                }
            }
        }
        return node;
    }
    int queryRank(TreeNode<T>* node, int v) {
        if (node == nullptr) return 0;
        if (node->key == v) return (node->left ? node->left->size : 0) + 1;
        if (node->key > v) return queryRank(node->left, v);
        return queryRank(node->right, v) + (node->left ? node->left->size : 0) + node->count;
    }

    int querykth(TreeNode<T>* node, int k) {
        if (node == nullptr) return -1;

        int leftSize = (node->left ? node->left->size : 0);

        if (k <= leftSize) {
            return querykth(node->left, k);
        } else if (k <= leftSize + node->count) {
            return node->key;
        } else {
            return querykth(node->right, k - (leftSize + node->count));
        }
    }

    TreeNode<T>* findMinNode(TreeNode<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    TreeNode<T>* findMaxNode(TreeNode<T>* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    //left rotate
    TreeNode<T>* leftRotate(TreeNode<T>* node) {
        TreeNode<T>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        temp->size = node->size;
        node->size = (node->left ? node->left->size : 0) +
                     (node->right ? node->right->size : 0) + node->count;
        return temp;
    }
    //right rotate
    TreeNode<T>* rightRotate(TreeNode<T>* node) {
        TreeNode<T>* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        temp->size = node->size;
        node->size = (node->left ? node->left->size : 0) +
                     (node->right ? node->right->size : 0) + node->count;
        return temp;
    }
    //bfs
    void bfs() {
        queue<TreeNode<T>*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode<T>* node = q.front();
            q.pop();
            cout << node->key << " ";
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        EDL;
    }

};

int main(){
    makeIO;

    //Test case for bst(Binary Search Tree)
    BinarySearchTree<int> bst;
    bst.init();

    //insert test data
    int data[4] = {5, 2, 8, 3};
    FOR(i, 0, 4){
        bst.insert(data[i]);
    }

    //search for rank
    FOR(i, 0, 4){
        cout<<"Rank of "<<data[i]<<": "<<bst.queryRank(bst.root, data[i])<<endl;
    }
    EDL;

    //search for kth rank
    FORE(i, 1, 4){
        cout<<"Element with rank "<<i<<": "<<bst.querykth(bst.root, i)<<endl;
    }
    EDL;

    //remove element
    bst.remove(3);

    //search for rank again
    FOR(i, 0, 4){
        cout<<"Rank of "<<data[i]<<": "<<bst.queryRank(bst.root, data[i])<<endl;
    }
    EDL;

    bst.insert(3);

    //find min node
    cout<<"Min node: "<<bst.findMinNode(bst.root)->key<<endl;
    //find max node
    cout<<"Max node: "<<bst.findMaxNode(bst.root)->key<<endl;

    //bfs
    bst.bfs();

    //left rotate
    bst.root = bst.leftRotate(bst.root);
    bst.bfs();
    return 0;
}



