#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bitset>
#include <cstdio>
#include <string>
using namespace std;
int IP[1001][4];
bitset<8> comp[1001];
bitset<8> netmask[4];
bitset<8> netaddress[4];
bool brk = false;

int main() {
	int n;
	int flag = 10;//flag가 초기값이면 아직 못찾음
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d.%d.%d.%d", &IP[i][0], &IP[i][1], &IP[i][2], &IP[i][3]);
	}

	int tmp = IP[0][0];
	for (int i = 1; i < n; i++) {
		if (tmp != IP[i][0]) {
			flag = 0;
			break;
		}
	}


	if (flag == 10) {
		int tmp = IP[0][1];
		for (int i = 1; i < n; i++) {
			if (tmp != IP[i][1]) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 10) {
		int tmp = IP[0][2];
		for (int i = 1; i < n; i++) {
			if (tmp != IP[i][2]) {
				flag = 2;
				break;
			}
		}
	}

	if (flag == 10) {
		int tmp = IP[0][3];
		for (int i = 1; i < n; i++) {
			if (tmp != IP[i][3]) {
				flag = 3;
				break;
			}
		}
	}

	if (flag == 10) {
		cout << IP[0][0] << "." << IP[0][1] << "." << IP[0][2] << "." << IP[0][3]
			<<'\n' << "255.255.255.255";
	}
	else {
		int saveflag = flag;
		for (int i = 0; i < n; i++) {
			comp[i] = bitset<8>(IP[i][flag]);
		}

		for (int i = 7; i >= 0; i--) {
			for (int j = 0; j < n - 1; j++) {
				if (comp[j][i] != comp[j + 1][i]) {
					brk = true;
					flag = (flag * 8) + (7 - i);
					break;
				}
			}
			if (brk == true)
				break;
		}

		for (int i = 0; i <= saveflag; i++) {
			netmask[i].set();
		}
		for (int i = 0; i < 8 - (flag - saveflag * 8); i++) {
			netmask[saveflag].set(i, false); //flag부터 나머지를 0으로
		}

		netaddress[0] = netmask[0] & bitset<8>(IP[0][0]);
		netaddress[1] = netmask[1] & bitset<8>(IP[0][1]);
		netaddress[2] = netmask[2] & bitset<8>(IP[0][2]);
		netaddress[3] = netmask[3] & bitset<8>(IP[0][3]);
		for (int i = 0; i < 8 - (flag - saveflag * 8); i++) {
			netaddress[saveflag].set(i, false);
		}


		cout << stoi(netaddress[0].to_string(), 0, 2) << "."
			<< stoi(netaddress[1].to_string(), 0, 2) << "."
			<< stoi(netaddress[2].to_string(), 0, 2) << "."
			<< stoi(netaddress[3].to_string(), 0, 2) << '\n';

		cout << stoi(netmask[0].to_string(), 0, 2) << "."
			<< stoi(netmask[1].to_string(), 0, 2) << "."
			<< stoi(netmask[2].to_string(), 0, 2) << "."
			<< stoi(netmask[3].to_string(), 0, 2) << '\n';
	}
}