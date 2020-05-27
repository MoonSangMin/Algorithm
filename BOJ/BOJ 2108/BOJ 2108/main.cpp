//4���� �Լ��� �����ؾ��Ѵ�
//������, �߾Ӱ�, �ֺ�, ����
//����(range) = max - min
//�ֺ�(freqVal) = ���� ���� ��Ÿ���� ��
//�߾Ӱ�(midVal) = �����ؼ� ���
//������(avg) = sum(Nums) / N

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr;
int cntArr[8001] = { 0, };
//0 ~ 3999�� -4000 ~ -1�� ��Ÿ���� 4000 ~ 8000�� 0~4000�� ��Ÿ��


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
	//�Ʒ��� ������
	double avgVal = 0;
	for (int i = 0; i < N; i++) {
		avgVal += arr[i];
		cntArr[arr[i] + 4000]++;//�ֺ� ���Ҷ� ���
	}
	//�Ʒ��� �ֺ�
	for (int i = 0; i < 8001; i++) {
		if (*max_element(cntArr, cntArr + 8001) == cntArr[i])
			flag++;
	}

	for (int i = 0; i < 8001; i++) {
		if (flag == 1) {//�ֺ��� �ϳ��� ���
			if (*max_element(cntArr, cntArr + 8001) == cntArr[i]) {
				freqVal = i - 4000;
				break;
			}
		}
		else {//�ֺ��� �������϶�
			if (*max_element(cntArr, cntArr + 8001) == cntArr[i]) {
				if (flag == 0) {
					freqVal = i - 4000;
					break;
				}
				else//�ֺ� �� ���� ó�� ��(���� ���� ��)�� flag�� 0�� �ƴϹǷ�
					flag = 0;//�� else������ ���� flag=0���� �����ȴ�.
			}//�� ���� �ֺ�(2��°�� ���� ��)�� if flag==0���� freqVal���� �����Ѵ�.
		}
	}
	//�Ʒ��� �߾Ӱ�
	sort(arr.begin(), arr.end());
	midVal = arr[arr.size() / 2];
	//�Ʒ��� ����
	range = arr[N-1] - arr[0];
	
	cout << (int)round(avgVal / N) << '\n';
	cout << midVal << '\n';
	cout << freqVal << '\n';
	cout << range << '\n';
}