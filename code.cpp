#include<Iostream>
using namespace std;
int main() {
	int odd_total = 0, even_total = 0, n, numbers;
	cout << "please enter the number of numbers:";
	cin >> n;
	for (int i = 1;i < n + 1;i++) {
		cin >> numbers;
		if (i % 2 == 0) {
			even_total += numbers;
		}
		else {
			odd_total += numbers;
		}
	}
	if (n % 2 == 0) {
		odd_total = odd_total / (n / 2);
		even_total = even_total / (n / 2);
	}
	else {
		odd_total = odd_total / ((n + 1) / 2);
		even_total = even_total / (n / 2);
	}
	cout << even_total << "\t" << odd_total;

}