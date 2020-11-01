#include <iostream>
using namespace std;

int main() {
	string str;
	int count[26] = { 0 };
	int i, j, max = -1, check = 0;
	int index = 0;
	int A, a;

	cin >> str;

	for (i = 0; str[i] != '\0'; i++) {
		A = 65;
		a = 97;//알파벳값 초기화
		for (j = 0; j < 26; j++) {
			if ((str[i] == a) || (str[i] == A))//str[i]가 해당 알파벳이면
				count[j]++;//해당 알파벳의 count++
			a++;
			A++;//다음 알파벳으로
		}
	}

	for (i = 0; i < 26; i++) {
		if (max < count[i]) {//count[i]가 최빈값이면
			max = count[i];
			index = i;//index에 i값 저장
			check = 0;//중복없음
		}
		else if (max == count[i])
			check = 1;//중복임
	}
	if (check)//중복이면 ?출력
		cout << "?" << endl;
	else//아니라면 65+max를 char형으로 출력
		cout << (char)(65 + index) << endl;

	return 0;
}