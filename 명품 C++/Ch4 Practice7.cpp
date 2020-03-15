#include <iostream>
using namespace std;

class Person {
private:
	string name;
	string tel;
public:
	Person() {}
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel) {
		this->name = name;
		this->tel = tel;
	}
};

int main() {
	Person p[3];
	string tmpName, tmpTel;
	cout << "이름과 전화번호를 입력해주세요" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i+1 << ">>";
		cin >> tmpName >> tmpTel;
		p[i].set(tmpName, tmpTel);
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++)
		cout << p[i].getName()<<' ';
	cout << endl;

	cout << "전화번호를 검색합니다. 빈칸 없이 이름을 입력하세요>>";
	cin >> tmpName;

	for (int i = 0; i < 3; i++) {
		if (tmpName == p[i].getName())
			cout << "전화번호는 "<<p[i].getTel()<<"입니다";
	}
	cout << endl;
}