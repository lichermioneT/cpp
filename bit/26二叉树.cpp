#include <iostream>

using namespace std;

template<class k>
struct BSTreeNode
{
    BSTreeNode* left;
    BSTreeNode* right;
    k _Key;

    BSTreeNode(const k& key )
        :left(nullptr)
        ,right(nullptr)
        ,_Key(key)
    {

    }
};

template<class k>
class BSTree
{
    typedef struct BSTreeNode<k> Node;
public:

    bool Insert(const k& key)
    {
        if(_root == nullptr)
        {
            _root = new Node(key);
            return true;   
        }
        
        Node* cur = _root;
        Node* parent = nullptr;
        while(cur != nullptr)
        {
            if(cur->_Key < key)
            {   
                parent = cur;
                cur = cur->right;
            }
            else if(cur->_Key > key)
            {
                parent = cur;
                cur = cur->left;
            }
            else
            {
                return false;
            }
        }

        cur = new Node(key);
        if(parent->_Key < key)
        {
            parent->right = cur;
        }
        else
        {
            parent->left = cur;
        }

        return false;
    }

    void _InOrder(Node* root)
    {
        if(root == nullptr)
            return;
        _InOrder(root->left);
        cout<< root->_Key << " ";
        _InOrder(root->right);
    }

    void _InOrder()
    {
        _InOrder(_root);
        cout<<endl;
    }


    bool Find(const k& key)
    {
        Node* cur = _root;
        while(cur != nullptr)
        {
            if(cur->_Key > key)
            {
                cur = cur->right;
            }
            else if(cur->_Key < key)
            {
                cur = cur->left;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    // 替换法左子树最大
    // 右子树最小的
    // 左边空
    // 右边空

    bool Erase(const k&  key)
    {
        Node* parent = nullptr;
        Node* cur  =  _root;

        while(cur != nullptr)
        {
            if(cur->_Key < key)
            {
                parent  = cur;
                cur = cur->right;
            }
            else if(cur->_Key > key)
            {
                parent = cur;
                cur = cur->left;
            }
            else
            {
                
                if(cur->left == nullptr)
                {
                    if(parent->right == cur)
                    {   

                        parent->right = cur->right;
                    }
                    else
                    {
                        parent->left = cur->right;
                    }

                    delete cur;
                }
                else if(cur->right == nullptr)
                {
                    if(parent->left == cur)
                    {
                        parent->left = cur->left;
                    }
                    else
                    {
                        parent->right = cur->left;
                    }

                    delete cur;
                }
                else
                {   
                    Node* rightMinParent = nullptr;
                    Node* rightMin = cur->right;
                    while(rightMin->left != nullptr)
                    {   
                        rightMinParent = rightMin;
                        rightMin = rightMin->left;
                    }

                    cur->_Key = rightMin->_Key;
                    rightMinParent->left = rightMin->right;

                    delete rightMin;
                }

                return true;
            }
        }

        return false;
    }



private:
    Node* _root = nullptr;
};


void test()
{       
    BSTree<int> t;
    int arr[] = {11,22,55,6,7,4,3,69,24,56,47,89,33};
    for(auto e : arr)
    {
        t.Insert(e);
    }
    t._InOrder();

    t.Erase(3);
    t._InOrder();
}


int main()
{


// 它是一颗二叉树
// 左子树的节点小于右子树

// 使用场景搜索
// 最多只需要查找树的高度次

// 排序
// 中序遍历数据有序
// 搜索二叉树也叫排序二叉树

    test();













    return 0;
}