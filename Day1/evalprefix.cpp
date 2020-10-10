#include <iostream>
using namespace std;

int stack[100], maxSize, tos = -1;
void initStack(int size)
{
    maxSize = size;
    tos = -1;
}

int isFull()
{
    if (tos == maxSize - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (tos == -1)
        return 1;
    else
        return 0;
}
int atTop()
{
    return stack[tos];
}

void push(int num)
{
    tos++;
    stack[tos] = num;
}

int pop()
{
    int temp;
	temp=stack[tos];
    tos--;
    return temp;
}

void printStack()
{
    for (int i = tos; i >= 0; i--)
    {
        cout << "|" << stack[i] << "|" << endl;
        cout << "---\n";
    }
}

int eval(int left,char op,int right)
{
    if (op=='+')
        return left+right;
    else if (op=='-')
        return left-right;
    else if (op=='*')
        return left*right;
    else if (op=='/')
        return left/right;
    else if (op=='%')
        return left%right;
}

int main()
{
    string pre;
    char s[100];
    initStack(pre.length());
    cout <<"Enter prefix for evaluation\n";
    cin >> pre;
    for (int i=pre.length()-1;i>=0;i--)
    {
        char read = pre[i];
        //cout << "read= " << read << endl;
        if (read == '+' || read == '-' || read == '*' || read == '/' || read == '%' || read == '^')
        {
            int left=pop();
            int right=pop();

            push(eval(left,read,right));
        }
        else
        {
            push(read-'0');
        }
    }
	//printStack();
    cout<<atTop();
    return 0;
}
//-+5*231  ->-i/p