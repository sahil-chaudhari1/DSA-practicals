#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node *left;
    Node *right;
    Node(char data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
struct Stack
{
    Node *data[100];
    int top = -1;
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    int size()
    {
        return (top + 1);
    }
    void push(Node *element)
    {
        if (isFull() == true)
        {
            cout << "Overflow" << endl;
            return;
        }
        top++;
        data[top] = element;
    }
    void pop()
    {
        if (isEmpty() == true)
        {
            cout << "Underflow" << endl;
            return;
        }
        top--;
    }
    Node *peek()
    {
        return data[top];
    }
    bool isFull()
    {
        if (top == 99)
            return true;
        else
            return false;
    }
};
Node *constructTree(Stack &mystack, string expression)
{
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        if ((expression[i] == '+') or (expression[i] == '-') or (expression[i] == '/') or (expression[i] == '*'))
        {
            Node *op1 = mystack.peek();
            mystack.pop();
            Node *op2 = mystack.peek();
            mystack.pop();
            Node *newnode = new Node(expression[i]);
            newnode->left = op1;
            newnode->right = op2;
            mystack.push(newnode);
        }
        else
        {
            Node *newnode1 = new Node(expression[i]);
            mystack.push(newnode1);
        }
    }
    return mystack.peek();
}
void inorder_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data;
    inorder_traversal(root->right);
}

void delete_root(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    delete_root(root->left);
    delete_root(root->right);
    delete (root);
}

void iterative_postorder(Node *root)
{
    if (root == NULL)
        return;
    Stack stack1;
    Stack stack2;
    stack1.push(root);
    while (stack1.isEmpty() != true)
    {
        Node *temp = stack1.peek();
        stack1.pop();
        stack2.push(temp);
        if (temp->left != NULL)
            stack1.push(temp->left);
        if (temp->right != NULL)
            stack1.push(temp->right);
    }
    while (stack2.isEmpty() != true)
    {
        cout << stack2.peek()->data;
        stack2.pop();
    }
    cout << endl;
}
int main()
{
    Stack mystack;
    string s;
    cout << "Enter the prefix expression here-\n";
    cin >> s;
    Node *root = constructTree(mystack, s);
    cout << "Inorder traversal of the prefix tree is- ";
    inorder_traversal(root);
    cout << "\n";
    
    cout << "Iterative postorder traversal of the expression tree is- ";
    iterative_postorder(root);
    cout<<"tree is deleted!!";
    delete_root(root);
    return 0;
}