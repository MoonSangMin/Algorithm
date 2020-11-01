#include <iostream>
using namespace std;

int main() {
	int firBurger, secBurger, thirBurger;
	int coke, cider;
	int cheaperBurger=0, cheaperDrink=0;
	int setSum = 0;

	cin >> firBurger >> secBurger >> thirBurger >> coke >> cider;

	cheaperBurger = firBurger;
	if (cheaperBurger > secBurger)
		cheaperBurger = secBurger;

	if (cheaperBurger > thirBurger)
		cheaperBurger = thirBurger;

	cheaperDrink = coke;
	if (cheaperDrink > cider)
		cheaperDrink = cider;

	setSum = cheaperBurger + cheaperDrink - 50;

	cout << setSum << endl;
}