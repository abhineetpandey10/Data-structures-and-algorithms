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
    /*void findIOS(node *&ios, node *&parentOfIOS)
    {
        while(ios->left!=nullptr)
        {
            parentOfIOS=ios;
            ios=ios->left;
        }
    }*/
    void remove(int key)
    {
        node *curr=root,*parent=nullptr;
        //search the node which contains the given key
        while(curr!=nullptr && curr->data!=key)
        {
            parent=curr;
            if(curr->data>key) curr=curr->left;
            else if(curr->data<key) curr=curr->right;
        }
        if(curr==nullptr) //tree does not contain the given value
        {
            cout<<"Key not found\n";
            return;
        }
        //@IMPORTANT
        /*do correction for deletion from root*/
        else if(curr->left==nullptr && curr->right==nullptr) //the node containing the given value is a leaf
        {
            if(parent!=nullptr)
            {
                if(parent->left==curr) parent->left=nullptr; //if the node to be deleted is the left child of its parent
                else if(parent->right==curr) parent->right=nullptr; //if the node to be deleted is the left child of its parent
            }
            delete curr;
        }
        else if(curr->left!=nullptr && curr->right==nullptr) //the the node containing the given value has only the left child
        {
            if(parent!=nullptr)
            {
                if(parent->left==curr) //if the node to be deleted id the left child of its parent
                    parent->left=curr->left;
                else if(parent->right==curr) // if the ndoe to be deleted is the right child of its parent
                    parent->right=curr->left;
            }
            curr->left=nullptr;
            delete curr;
        }
        else if(curr->left!=nullptr && curr->right==nullptr) //the the node containing the given value has only the right child
        {
            if(parent!=nullptr)
            {
                if(parent->left==curr) //if the node to be deleted id the left child of its parent
                    parent->left=curr->right;
                else if(parent->right==curr) // if the ndoe to be deleted is the right child of its parent
                    parent->right=curr->right;
            }
            curr->right=nullptr;
            delete curr;
        }
        else if(curr->left!=nullptr && curr->right!=nullptr) //the node containg the given value has both the children
        {
            node *&ios=curr->right,*parentOfIOS=curr;
            while(ios->left!=nullptr)
            {
                parentOfIOS=ios;
                ios=ios->left;
            }
            int tmp=ios->data;
            ios->data=curr->data;
            curr->data=tmp;
            if(parentOfIOS==curr) //the right node of the node to be deleted is a leaf
                parentOfIOS->right=nullptr;
            else if(parentOfIOS!=nullptr)
                parentOfIOS->left=nullptr;
            delete ios;
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