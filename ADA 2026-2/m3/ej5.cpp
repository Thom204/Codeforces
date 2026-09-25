#include <iostream>
#include <string>

using namespace std;

const string verificationLetters = "TRWAGMYFPDXBNJZSQVHLCKE";

int countCompatible(string& dni, int position) {
	if (position == 8) {
		long long number = 0;
		for (int i = 0; i < 8; ++i) {
			number = number * 10 + (dni[i] - '0');
		}

		return verificationLetters[number % 23] == dni[8] ? 1 : 0;
	}

	if (dni[position] != '?') {
		return countCompatible(dni, position + 1);
	}

	int compatible = 0;
	for (char digit = '0'; digit <= '9'; ++digit) {
		dni[position] = digit;
		compatible += countCompatible(dni, position + 1);
	}
	dni[position] = '?';

	return compatible;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cases;
	cin >> cases;

	while (cases--) {
		string dni;
		cin >> dni;
		cout << countCompatible(dni, 0) << endl;
	}
}
