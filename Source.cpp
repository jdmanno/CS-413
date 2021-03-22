#include <iostream>
#include <cmath> 
#include <stack>
#include <queue>
using namespace std;

bool palindrome(int arr[], int n, int m) {
    if (n <= m) {
        if (abs(arr[n]) == abs(arr[m])) return palindrome(arr, n + 1, m - 1);
        else return false;
    }
}

int iterativeFactorial(int n) {
    int temp = 1;

    for (n; n > 0; n--) {
        temp = temp * n;
    }

    cout << temp << endl;
    return temp;
}

int recursiveFactorial(int n) {
    if (n == 1 || n == 0) return 1;
    else return n * recursiveFactorial(n - 1);
}

struct Node {
    char data;
    Node* left, * middle, * right;

    Node(char data)
    {
        this->data = data;
        left = middle = right = NULL;
    }
};

char DFS(stack<Node*>s, Node* node)
{
    if (node == NULL) return NULL;

    while (!s.empty()) {
        Node* temp = s.top();
        cout << temp->data << " ";
        s.pop();

        if (temp->data == 'j') return temp->data;

        if (temp->right)
            s.push(temp->right);

        if (temp->middle)
            s.push(temp->middle);

        if (temp->left)
            s.push(temp->left);

        return DFS(s, s.top());
    }

    return NULL;
}


char BFS(queue<Node*>q, struct Node* node)
{
    if (node == NULL) return NULL;

    while (!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->data == 'l') return temp->data;

        if (temp->left)
            q.push(temp->left);

        if (temp->middle)
            q.push(temp->middle);

        if (temp->right)
            q.push(temp->right);

        return BFS(q, q.front());
    }

    return NULL;
}


int main() {
    int a[1] = { 0 };
    if (palindrome(a, 0, 0)) cout << "yes" << endl;
    else cout << "no" << endl;

    int b[10] = { 1,2,3,4,5,5,4,3,2,1 };
    if (palindrome(b, 0, 9)) cout << "yes" << endl;
    else cout << "no" << endl;

    int c[9] = { 1,2,3,4,5,4,3,2,1 };
    if (palindrome(c, 0, 8)) cout << "yes" << endl;
    else cout << "no" << endl;

    int d[4] = { 1,2,2,1 };
    if (palindrome(d, 0, 3)) cout << "yes" << endl;
    else cout << "no" << endl;

    int e[4] = { 1,2,3,4 };
    if (palindrome(e, 0, 3)) cout << "yes" << endl;
    else cout << "no" << endl;

    int f[4] = { 7,6,7,6 };
    if (palindrome(f, 0, 3)) cout << "yes" << endl;
    else cout << "no" << endl;

    int g[3] = { -1,2,1 };
    if (palindrome(g, 0, 2)) cout << "yes" << endl;
    else cout << "no" << endl;

    int h[3] = { -4,5,6 };
    if (palindrome(h, 0, 2)) cout << "yes" << endl;
    else cout << "no" << endl;

    iterativeFactorial(5);
    cout << recursiveFactorial(5) << endl;

    struct Node* root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');
    root->left->left = new Node('d');
    root->left->right = new Node('e');
    root->right->left = new Node('f');
    root->right->right = new Node('g');
    root->left->right->left = new Node('h');
    root->left->right->right = new Node('i');
    root->right->right->left = new Node('j');
    root->right->right->right = new Node('k');
    root->left->right->left->left = new Node('l');
    root->left->right->left->middle = new Node('m');
    root->left->right->left->right = new Node('n');
    root->left->right->right->left = new Node('o');
    root->left->right->right->right = new Node('p');
    root->right->right->right->left = new Node('q');

    stack<Node*> s;
    s.push(root);
    cout << DFS(s, root) << endl;

    queue<Node*> q;
    q.push(root);
    cout << BFS(q, root) << endl;
}

// in-order - left root right 
// pre-order - root left right
// post-order - left right root 
