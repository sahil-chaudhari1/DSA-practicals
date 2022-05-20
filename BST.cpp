//(2)
// SHIVPRASAD BODKE

#include <iostream>
using namespace std;

class node
{
public:
    node *lchild;
    int data;
    node *rchild;
};

class BST
{
private:
    node *root;

public:
    BST();
    node *get_root();
    void insert(int key);
    node *search(int key);
    void inorder(node *t);
    void preorder(node *t);
    void postorder(node *t);
    int min_element(node *t);
    int max_element(node *t);
    int height(node *t);
    void mirror_image(node *t);
};

BST ::BST()
{
    root = nullptr;
}

node *BST ::get_root()
{
    return root;
}

void BST ::insert(int key)
{
    node *t = root;

    node *p;
    node *r;

    // ROOT IS EMPTY
    if (root == nullptr)
    {
        p = new node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while (t != nullptr)
    {
        r = t;

        if (key == t->data)
        {
            return;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }

    // NOW T POINTS AT NULL AND R POINTS AT INSERT LOCATION
    p = new node;
    p->data = key;
    p->lchild = p->rchild = nullptr;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

node *BST ::search(int key)
{
    node *t = root;

    while (t != nullptr)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return nullptr;
}

void BST ::inorder(node *t)
{
    if (t != nullptr)
    {
        inorder(t->lchild);
        cout << t->data << "    ";
        inorder(t->rchild);
    }
}
void BST ::preorder(node *t)
{
    if (t != nullptr)
    {
        cout << t->data << "    ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void BST ::postorder(node *t)
{
    if (t != nullptr)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        cout << t->data << "    ";
    }
}

int BST ::min_element(node *t)
{
    while(t->lchild != nullptr)
    {
        t = t->lchild;
    }
    return t->data ;
}

int BST ::max_element(node *t)
{
    while( t->rchild != nullptr)
    {
        t = t->rchild;
    }
    return t->data;
}

int BST ::height(node *t)
{
    int x,y;

    if( t == nullptr)
    {
        return 0;
    }
    x = height(t->lchild);
    y = height(t->rchild);

    if(x>y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }
}

void BST ::mirror_image(node *t)
{
    node *temp;

    if (t == nullptr)
    {
        return;
    }
    else
    {
        mirror_image(t->lchild);
        mirror_image(t->rchild);

        temp = t->lchild;
        t->lchild = t->rchild;
        t->rchild = temp;
    }
}

int main()
{
    BST bst;
    node *temp;
    int x,operation;

    do
    {
        cout<<"\n\t1.INSERT\n\t2.INORDER\n\t3.PREORDER\n\t4.POSTORDER\n\t5.SEARCH\n\t6.FIND MIN\n\t7.FIND MAX\n\t8.HEIGHT\n\t9.MIRROR IMAGE\n\t10.QUIT";

        cout<<"\nENTER YOUR CHOICE : ";
        cin>>operation;

        switch (operation)
        {
            case 1:
            cout<<"\nENTER INT ELEMENT FOR INSERT : ";
            cin>>x;
            bst.insert(x);
            break;
        
            case 2:
            cout<<"\nINORDER :  ";
            bst.inorder(bst.get_root());
            break;

            case 3:
            cout<<"\nPREORDER :  ";
            bst.preorder(bst.get_root());
            break;

            case 4:
            cout<<"\nPOSTORDER :  ";
            bst.postorder(bst.get_root());
            break;

            case 5:
            cout<<"\nENTER INT ELEMENT FOR SEARCH : ";
            cin>>x;
            temp= bst.search(x);
            if (temp != nullptr)
            {
                cout << "\nNODE FOUND : " << temp->data;
            }
            else
            {
                cout << "\nNODE NOT FOUND !";
            }
            break;

            case 6:
            cout<<"\nMIN ELEMENT : "<<bst.min_element(bst.get_root());
            break;

            case 7:
            cout<<"\nMAX ELEMENT : "<<bst.max_element(bst.get_root());
            break;

            case 8:
            cout<<"\nHEIGHT : "<<bst.height(bst.get_root());
            break;

            case 9:
            bst.mirror_image(bst.get_root());
            cout<<"\nMIRROR IMAGE TREE :";
            bst.inorder(bst.get_root());
            break;

            case 10:
            cout<<"\nEXIT";
            break;

        }
    } while (operation !=10);

    return 0;
}

// SHIVPRASAD BODKE