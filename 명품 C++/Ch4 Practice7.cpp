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
	cout << "�̸��� ��ȭ��ȣ�� �Է����ּ���" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "��� " << i+1 << ">>";
		cin >> tmpName >> tmpTel;
		p[i].set(tmpName, tmpTel);
	}

	cout << "��� ����� �̸��� ";
	for (int i = 0; i < 3; i++)
		cout << p[i].getName()<<' ';
	cout << endl;

	cout << "��ȭ��ȣ�� �˻��մϴ�. ��ĭ ���� �̸��� �Է��ϼ���>>";
	cin >> tmpName;

	for (int i = 0; i < 3; i++) {
		if (tmpName == p[i].getName())
			cout << "��ȭ��ȣ�� "<<p[i].getTel()<<"�Դϴ�";
	}
	cout << endl;
}