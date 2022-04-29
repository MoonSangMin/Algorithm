#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int d, h, w;
    cin >> d >> h >> w;

    double ratio = d / sqrt(pow(w, 2) + pow(h, 2));
    cout << (int)(h * ratio) << ' ' << (int)(w * ratio);
}