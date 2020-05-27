//4개의 함수를 구현해야한다
//산술평균, 중앙값, 최빈값, 범위
//범위(range) = max - min
//최빈값(freqVal) = 가장 많이 나타나는 값
//중앙값(midVal) = 정렬해서 가운데
//산술평균(avg) = sum(Nums) / N

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr;
int cntArr[8001] = { 0, };
//0 ~ 3999는 -4000 ~ -1을 나타내고 4000 ~ 8000은 0~4000을 나타냄


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, flag = 0, maxFrequentNum, firstMax=0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	int midVal = 0;
	int freqVal = 0;
	int range = 0;
	//아래는 산술평균
	double avgVal = 0;
	for (int i = 0; i < N; i++) {
		avgVal += arr[i];
		cntArr[arr[i] + 4000]++;//최빈값 구할때 사용
	}
	//아래는 최빈값
	for (int i = 0; i < 8001; i++) {
		if (*max_element(cntArr, cntArr + 8001) == cntArr[i])
			flag++;
	}

	for (int i = 0; i < 8001; i++) {
		if (flag == 1) {//최빈값이 하나인 경우
			if (*max_element(cntArr, cntArr + 8001) == cntArr[i]) {
				freqVal = i - 4000;
				break;
			}
		}
		else {//최빈값이 여러개일때
			if (*max_element(cntArr, cntArr + 8001) == cntArr[i]) {
				if (flag == 0) {
					freqVal = i - 4000;
					break;
				}
				else//최빈값 중 가장 처음 값(제일 작은 값)은 flag가 0이 아니므로
					flag = 0;//이 else문으로 가서 flag=0으로 설정된다.
			}//그 다음 최빈값(2번째로 작은 값)은 if flag==0에서 freqVal값을 설정한다.
		}
	}
	//아래는 중앙값
	sort(arr.begin(), arr.end());
	midVal = arr[arr.size() / 2];
	//아래는 범위
	range = arr[N-1] - arr[0];
	
	cout << (int)round(avgVal / N) << '\n';
	cout << midVal << '\n';
	cout << freqVal << '\n';
	cout << range << '\n';
}