/*
  Cho 1 list các từ vựng và 1 list câu hỏi
  Với mỗi câu hỏi trả bao gồm 1 xâu: trả lời xâu đó xuất hiện bao nhiêu lần trong list

  Input
  7
  asd
  dsa
  asd
  khoi
  hoang
  huy
  du

  5
  asd
  s
  as
  khoi
  du

  Output:
  2
  0
  0
  1
  1
*/

#include <iostream>
using namespace std;

const int N = 26;

struct Node {
    char value;
    int count;
    Node* next[N];
};

Node* newNode() {
    Node* res = new Node;
    res->value = '.';
    res->count = 0;
    for (int i = 0; i < N; ++i) res->next[i] = nullptr;
    return res;
};

Node* newNode(char val) {
    Node* res = newNode();
    res->value = val;
    return res;
}

void append(Node*& head, string s) {
    Node* tmp = head;
    for (auto c : s) {
        if (!tmp->next[c - 'a']) tmp->next[c - 'a'] = newNode(c);
        tmp = tmp->next[c - 'a'];
    }
    tmp->count += 1;
}

int find(Node*& head, string s) {
    Node* tmp = head;
    for (auto c : s) {
        if (tmp->next[c - 'a']) tmp = tmp->next[c - 'a'];
        else return false;
    }
    return tmp->count;
}

void traverse(Node*& head) {
    if (head == nullptr) return;
    cout << head->value << " ";
    for (int i = 0; i < N; ++i) traverse(head->next[i]);
}

int main() {
    freopen("trie.inp", "r", stdin);
    int n, m;
    string s;

    Node* head = newNode();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        append(head, s);
    }
    traverse(head);
    cout << endl;

    cin >> m;
    for (int i = 0; i < m; ++i){
        cin >> s;
        cout << find(head, s) << endl;
    }
};

/*
    Apple ra mắt iphone 14

    iphone

    Apple

    ra

    mắt
    

    pple
*/