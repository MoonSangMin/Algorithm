#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    long long kingHP, solHP, kingAD, solAD;
    long long skill, heal;

    cin >> solHP >> solAD >> kingHP >> kingAD;
    cin >> skill >> heal;

    long long solDeathCount = ceil((double)solHP / kingAD); //용사가 죽는 지점(횟수)
    long long kingDeathCount;
    
    long long tmp = (kingHP - skill) % solAD;

    if(tmp && tmp + skill <= solAD) kingDeathCount = ceil((double)kingHP / solAD);
    else kingDeathCount = ceil(((double)kingHP + heal) / solAD);

    if(solDeathCount >= kingDeathCount) cout << "Victory!";
    else cout << "gg";
}