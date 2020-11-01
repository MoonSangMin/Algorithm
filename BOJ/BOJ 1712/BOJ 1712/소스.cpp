#include <iostream>
using namespace std;

int main() {
	unsigned int fixedExpense = 0, varExpense = 0, price = 0;

	cin >> fixedExpense >> varExpense >> price;

	if((price-varExpense)>0)
		cout << (fixedExpense / (price - varExpense))+1;
	else
		return -1;
}