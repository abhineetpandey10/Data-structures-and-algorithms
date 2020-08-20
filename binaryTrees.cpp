#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<stack>
using std::stack;
class node
{
public:
    int data;
    node *left,*right;
    node(int n)
    {
        data=n;
        left=nullptr;
        right=nullptr;
    }
};
class tree
{
public:
    node *root;
    tree():root(nullptr){}
    void insert(int n)
    {
        node *newNode=new node(n);
        if(root==nullptr)
        {
            root=newNode;
            return;
        }
        node *parent=nullptr,*ptr=root;
        while(ptr!=nullptr)
        {
            parent=ptr;
            if(ptr->data>n) ptr=ptr->left;
            else if(ptr->data<n) ptr=ptr->right;
            else if(ptr->data==n)
            {
                cout<<"Duplicate\n";
                return;
            }
        }
        if(parent->data>n) parent->left=newNode;
        if(parent->data<n) parent->right=newNode;
    }
    void remove(int key){remove(key,root);}
    node *findMin(node *_root)
    {
        if(_root==nullptr) return nullptr;
        if(_root->left==nullptr) return _root;
        return findMin(_root->left);
    }
    void remove(int key,node *&_root)
    {
        if(_root==nullptr)//key not found
            return;
        else if(_root->data<key) remove(key,_root->right);
        else if(_root->data>key) remove(key,_root->left);
        else if(_root->left!=nullptr && _root->right!=nullptr) //both children
        {
            _root->data=findMin(_root->right)->data;
            remove(_root->data,_root->right);
        }
        else
        {
            node* oldNode=_root;
            if(_root->left!=nullptr) _root=_root->left;
            else _root=_root->right;
            delete oldNode;
        }
    }
    void inorder()
    {
        node *ptr=root;
        stack<node*> a;
        while(a.empty()==false || ptr!=nullptr)
        {
            while(ptr!=nullptr)
            {
                a.push(ptr);
                ptr=ptr->left;
            }
            ptr=a.top();
            a.pop();
                cout<<ptr->data<<' ';
                ptr=ptr->right;
        }
        cout<<endl;
    }
    void preorder()
    {
        node *ptr=root;
        stack<node*> a;
        a.push(ptr);
        while(ptr!=nullptr && a.empty()==false)
        {
            ptr=a.top();
            cout<<ptr->data<<' ';
            a.pop();
            if(ptr->right!=nullptr) a.push(ptr->right);
            if(ptr->left!=nullptr) a.push(ptr->left);
        }
        cout<<endl;
    }
    void postorder()
    {
        if(root==nullptr) return;
        stack<node*> a,b;
        node *ptr=root;
        a.push(root);
        while(a.empty()==false && ptr!=nullptr)
        {
            ptr=a.top();
            a.pop();
            b.push(ptr);
            if(ptr->left!=nullptr) a.push(ptr->left);
            if(ptr->right!=nullptr) a.push(ptr->right);
        }
        while(b.empty()==false)
        {
            cout<<b.top()->data<<' ';
            b.pop();
        }
        cout<<endl;
    }
};
int main()
{
    tree t;
    while(1)
    {
        cout<<"1.insert\n2.inorder\n3.preorder\n4.postorder\n5.remove\n0.exit\n";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:cin>>ch;
                t.insert(ch);
                break;
            case 2:t.inorder();
                break;
            case 3:t.preorder();
                break;
            case 4:t.postorder();   
                break;
            case 5:cin>>ch;
                t.remove(ch);
                break;
            case 0:exit(0);
        }
    }
}