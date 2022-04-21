#include <iostream>
using namespace std;

int findXOR(int n)
{
    int mod = n % 4;
 
    if (mod == 0) return n;
    else if (mod == 1) return 1;
    else if (mod == 2) return n + 1;
    else if (mod == 3) return 0;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int l, r;
        cin >> l >> r;
    
        cout << (findXOR(l - 1) ^ findXOR(r)) << '\n';
    }
}