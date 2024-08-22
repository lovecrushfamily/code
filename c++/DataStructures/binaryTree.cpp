#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
#include<unordered_map>
#include<map>
#include<string>

using namespace std;


class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
    }

};

class Tree{
    public:
    Node* root;

    Tree():root(nullptr){}

    void insert(int data){
        insert(this -> root, data);
    }
    void insert(Node*& root,int data){
        if (root == nullptr || root -> data == data){
            Node* newNode = new Node(data);
            root  = newNode;
        }

        else if (root -> data > data){
            insert(root -> left, data);
        }else{
            insert(root -> right, data);
        }
    }

    // string find(int value){
    //     return bst(this -> root, value);
    // }
    // string bst(Node* root, int value){
    //     while (root != nullptr && root -> data != value)
    //     {
    //         if (root -> data < value){
    //             root = root -> right;
    //         }else{
    //             root = root -> left;
    //         }
    //     }
    //     return (root == nullptr) ? to_string(value) +" Not found !" 
    //                 : to_string(root -> data) + "'ve already exist !";    
    // }

    void printBinaryTreeBFS(){
        bfs(this -> root);
    }

    void bfs(Node* root){
        queue<Node*> queue;
        queue.push(root);

        while (!queue.empty())
        {
            int level = queue.size();
            /* code */
            for ( int i = 0; i < level; i++)        
            {
                /* code */
                Node* curr = queue.front();
                queue.pop();

                cout << curr -> data << ' ';
                
                if (curr -> left){
                    queue.push(curr -> left);
                }

                if ( curr ->right){
                    queue.push(curr -> right);
                }
            }
            // cout << '\n';
        }
    }
    void printBinaryTreeDFS(){
        dfs(this -> root);
    }
    void dfs(Node* root){
        if( root == nullptr){
            return;
        }
        cout << root -> data << ' ';
        dfs(root -> left);
        dfs(root -> right);
    }
    int maxDepth(Node* root){
        if ( root == nullptr){
            return 0;
        }

        int maxLeft =  maxDepth(root -> left);
        int maxRight = maxDepth(root -> right);
        return  max(maxLeft, maxRight) + 1;
        
    }
    int minDepth(Node* root){
        if ( root == nullptr){
            return 0;
        }

        int maxLeft =  maxDepth(root -> left);
        int maxRight = maxDepth(root -> right);
        return  min(maxLeft, maxRight) + 1;

    }
    int numberOfNode(){
        return countNode(this -> root);
    }
    int countNode(Node* root){
        if (root == nullptr){
            return 0;
        }
        int left = countNode(root -> left);
        int right = countNode(root -> right);
        return left + right + 1;
    }

    int diameter(Node* root){
        return maxDepth(root->left) + maxDepth(root -> right);
    }

    Node* checkMax(){
        return dfsMaxRight(this -> root);
    }
    Node* dfsMaxRight(Node* root){
        if( root -> right == nullptr){
            return root;
        }
        return dfsMaxRight(root -> right);
    }

    Node* bst(Node* root, int value){
        
        while (root != nullptr && root -> data != value)
        {
            if (root -> data < value){
                root = root -> right;
            }else{
                root = root -> left;
            }
        }
        return root; 
    }
    Node* checkDad(Node* root, Node* son){
        while(root -> right != son && root -> left != son){
            if (root -> data < son -> data){
                root = root -> right;
            }else{
                root = root -> left;
            }
        }
        return root;
    }
    void removeLeaf(){
        cout << "Leaf !";
    }
    void removeDadTwoSon(){
        cout << "Two Son !";
    }
    void removeDadOneSon(){
        cout << "One Son !";
    }
    void removeRoot(){
        cout << "Remove Root !";
        Node* maxLeft = dfsMaxRight(this -> root ->left);
        Node * dadMax = checkDad(this -> root, maxLeft);
        dadMax -> right = nullptr;
        maxLeft -> right = this -> root ->right;
        maxLeft -> left = this -> root -> left;
        delete this -> root;
        this -> root = nullptr;
        this -> root = maxLeft;

    }
    void remove(int data){
        if (this -> root -> data == data){
            removeRoot();
        }
        Node* temp = bst(this -> root, data);
        if (temp == nullptr){
            cout << to_string(data) + " Not found ! ";
            return;
        }else{
            cout << to_string(data) + " removing... ";
        }
        Node* dad = checkDad(this-> root, temp);

        if (temp -> right == nullptr && temp -> left == nullptr){
            // cout << dad -> data;
            removeLeaf();
            if (dad -> right -> data == data){
                dad -> right = nullptr;
            }else{
                dad -> left = nullptr;
            }
            delete temp;

        }else if (temp -> right != nullptr && temp -> left != nullptr){
            // check max on the left son
            removeDadTwoSon();
            // case 1: son's only have one node of the left
            if (temp -> left -> left == nullptr && temp -> left -> right == nullptr){
                if (dad -> right -> data == temp -> data){
                    dad -> right = temp -> left;
                }else{
                    dad -> left = temp -> left;
                }
                temp -> left -> right = temp -> right;
                delete temp;
                return;
            }
            //  case 2: son's have two own son
            Node* maxOnTheLeft = dfsMaxRight(temp -> left);     
            Node* maxDad = checkDad(temp, maxOnTheLeft);
            if (maxDad -> right -> data == maxOnTheLeft -> data){
                maxDad -> right = nullptr;
            }else{
                maxDad -> left = nullptr;
            }

            if (dad -> right -> data == data){
                maxOnTheLeft -> right = temp -> right;
                maxOnTheLeft -> left = temp -> left;
                dad -> right = maxOnTheLeft;
            }else{
                maxOnTheLeft -> right = temp -> right;
                maxOnTheLeft -> left = temp -> left;
                dad -> left = maxOnTheLeft;
            }
            delete temp;
            
        }else{
        
            removeDadOneSon();
            if (dad->right != nullptr && dad->right->data == data) {
                if (temp->right != nullptr) {
                    dad->right = temp->right;
                } else {
                    dad->right = temp->left;
                }
                delete temp;
                temp = nullptr; // Optional: Set temp to nullptr after deletion
            } else {
                if (temp->right != nullptr) {
                    dad->left = temp->right;
                } else {
                    dad->left = temp->left;
                }
                delete temp;
                temp = nullptr; // Optional: Set temp to nullptr after deletion
            }
        }

    }
    int sumNodeInRange(int low, int high){
        return sumNodeInRange(this -> root, low, high);
    }
    int sumNodeInRange(Node* root, int low, int high){
        if (root == nullptr){
            return 0;
        }

        int ans = 0;
        if (low <= root -> data && high >= root->data){
            ans += root -> data;
        }
        if (low <= root ->data){
            ans += sumNodeInRange(root -> left, low, high);
        }if (root -> data <= high){
            ans += sumNodeInRange(root -> right, low , high);
        }

        return ans;
    }
    bool checkBST(){
        return checkBST(this -> root, -99, 99);
    }
    bool checkBST(Node* root, int small, int large){
        if (root == nullptr){
            return true;
        }

        if ( small > root -> data || root -> data > large){
            return false;
        }

        bool left = checkBST(root -> left, small, root -> data);
        bool right = checkBST(root -> right, root -> data, large);

        return left && right;  
    }
};

class solution{
    public:
    int target;

    bool hasPathSum(Node* root, int sum){
        target = sum;
        return dfs(root, 0);
    }

    bool dfs(Node* root, int curr){
        if ( root == nullptr){
            return false;
        }
        if (root -> left == nullptr && root -> right == nullptr){
            return (curr + root -> data ) == target;
        }

        curr += root -> data;
        bool left = dfs(root ->left, curr);
        bool right = dfs(root -> right, curr);
        return left || right;
    }

    vector<int> maxOnEachLevel(Node* root){
        if (root == nullptr){
            return vector<int>{};
        }

        vector<int> ans;
        queue<Node*> queue;
        queue.push(root);


        while( !queue.empty()){
            int level = queue.size();
            int curr_max = -100;

            while(level--){
                Node* curr = queue.front();
                curr_max = max(curr_max, curr -> data);
                queue.pop();


                if ( curr -> left){
                    queue.push(curr -> left);
                }

                if (curr -> right){
                    queue.push(curr -> right);
                }
            }
            ans.push_back(curr_max);
        }

        return ans;
    }
    void maxOnLastLevel(Node* root){
        if (root == nullptr){
            return;
        }

        // int ans;
        queue<Node*> queue;
        queue.push(root);
        bool direct = true;


        while( !queue.empty()){
            int level = queue.size();
            // int curr_max = 0;

            while(level--){
                Node* curr = queue.front();
                queue.pop();


                cout << curr -> data <<" ";
                if (direct){

                    if ( curr -> left){
                        queue.push(curr -> left);
                    }

                    if (curr -> right){
                        queue.push(curr -> right);
                    }
                    direct = false;
                }else{
                    if (curr -> right){
                        queue.push(curr -> right);
                    }
                    if ( curr -> left){
                        queue.push(curr -> left);
                    }
                    direct = true;
                }
            }
        }
    }
};

int main(){

    Tree root;

    root.insert(5);
    root.insert(9);
    root.insert(20);
    root.insert(3);
    root.insert(4);
    root.insert(6);
    root.insert(1);
    root.insert(6);
    root.insert(2);
    root.insert(7);
    root.insert(10);
    root.insert(11);
    root.insert(8);


    root.printBinaryTreeBFS();
    cout << '\n' ;
    // cout << root.sumNodeInRange(1,6);
    cout << root.checkBST();
    cout << '\n' ;
    root.printBinaryTreeBFS();

}
