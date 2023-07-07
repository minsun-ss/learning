#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double revenue;
	double costs;
	double grossProfit;
	double netProfit;
	double taxRate;

	cout << "What is your revenue?\n";
	cin >> revenue;
	cout << "What is your costs?\n";
	cin >> costs;
	cout << "What is your tax rate?\n";
	cin >> taxRate;

	grossProfit = revenue-costs;

	if (grossProfit > 0) {
		netProfit = grossProfit * (1.0-taxRate);
	} else {
		netProfit = 0;
	}

	cout << "Gross profit: " << grossProfit << endl;
	cout << "Net profit: " << netProfit << endl;
	return 0;
}
