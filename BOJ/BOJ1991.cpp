#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<char, pair<char, char> > tree;

void preorder(char c){
    if(tree.find(c) == tree.end()) return;
    else{
        cout << c;
        if(tree[c].first != '.') preorder(tree[c].first);
        if(tree[c].second != '.') preorder(tree[c].second);
    }
    
    return;
}//전위순회 루트->왼쪽->오른쪽 순서로 순회

void inorder(char c){
    if(tree.find(c) == tree.end()) return;
    else{
        if(tree[c].first != '.') inorder(tree[c].first);
        cout << c;
        if(tree[c].second != '.') inorder(tree[c].second);
    }
    
    return;
}//중위순회 왼쪽->루트->오른쪽 순서로 순회

void postorder(char c){
    if(tree.find(c) == tree.end()) return;
    else{
        if(tree[c].first != '.') postorder(tree[c].first);
        if(tree[c].second != '.') postorder(tree[c].second);
        cout << c;
    }
    
    return;
}//후위순회 왼쪽->오른쪽->루트 순서로 순회

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;

    cin >> n;
    for(int i=0; i<n; i++){
        char tmp[3];
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        tree[tmp[0]] = make_pair(tmp[1], tmp[2]);
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}