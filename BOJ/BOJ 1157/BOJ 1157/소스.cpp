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
		a = 97;//���ĺ��� �ʱ�ȭ
		for (j = 0; j < 26; j++) {
			if ((str[i] == a) || (str[i] == A))//str[i]�� �ش� ���ĺ��̸�
				count[j]++;//�ش� ���ĺ��� count++
			a++;
			A++;//���� ���ĺ�����
		}
	}

	for (i = 0; i < 26; i++) {
		if (max < count[i]) {//count[i]�� �ֺ��̸�
			max = count[i];
			index = i;//index�� i�� ����
			check = 0;//�ߺ�����
		}
		else if (max == count[i])
			check = 1;//�ߺ���
	}
	if (check)//�ߺ��̸� ?���
		cout << "?" << endl;
	else//�ƴ϶�� 65+max�� char������ ���
		cout << (char)(65 + index) << endl;

	return 0;
}