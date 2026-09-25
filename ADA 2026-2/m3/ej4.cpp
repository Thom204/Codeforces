#include <iostream>
#include <string>
#include <vector>

template <typename T, typename Func>
void combine(const std::vector<T>& v, int n, Func proc_fn) {
    std::vector<T> selected;

    auto generate = [&](auto&& self, int start) -> void {
        if (static_cast<int>(selected.size()) == n) {
            proc_fn(selected);
            return;
        }

        int remaining = n - static_cast<int>(selected.size());
        for (int i = start; i <= static_cast<int>(v.size()) - remaining; ++i) {
            selected.push_back(v[i]);
            self(self, i + 1);
            selected.pop_back();
        }
    };

    if (n >= 0 && n <= static_cast<int>(v.size())) {
        generate(generate, 0);
    }
}

template <typename T, typename Func>

void permute(std::vector<T>& v, std::size_t start, std::size_t end, Func proc_fn) {
    if (start >= end) {
        proc_fn(v);
        return;
    }

    for (std::size_t i = start; i <= end; ++i) {
        std::swap(v[start], v[i]);
        permute(v, start + 1, end, proc_fn);
        std::swap(v[start], v[i]);
    }
}

using namespace std;

long long buildNumber(const vector<int>& digits) {
	long long number = 0;
	for (int digit : digits) {
		number = number * 10 + digit;
	}
	return number;
}

bool isHerederNumber(long long number) {
	string text = to_string(number);
	int digitCount = static_cast<int>(text.size());

	if (digitCount % 2 != 0) {
		return false;
	}

	int parentDigits = digitCount / 2;
	vector<int> digits;
	for (char digit : text) {
		digits.push_back(digit - '0');
	}

	bool found = false;
	combine(digits, parentDigits, [&](const vector<int>& firstDigits) {
		if (found) {
			return;
		}

		vector<int> firstCount(10, 0);
		vector<int> secondDigits;
		for (int digit : firstDigits) {
			firstCount[digit]++;
		}

		vector<int> remainingCount(10, 0);
		for (int digit : digits) {
			remainingCount[digit]++;
		}
		for (int digit = 0; digit <= 9; ++digit) {
			remainingCount[digit] -= firstCount[digit];
			for (int count = 0; count < remainingCount[digit]; ++count) {
				secondDigits.push_back(digit);
			}
		}

		vector<int> first = firstDigits;
		permute(first, 0, first.size() - 1, [&](const vector<int>& firstParent) {
			if (found || firstParent[0] == 0) {
				return;
			}

			long long firstNumber = buildNumber(firstParent);
			vector<int> second = secondDigits;
			permute(second, 0, second.size() - 1, [&](const vector<int>& secondParent) {
				if (found || secondParent[0] == 0) {
					return;
				}

				long long secondNumber = buildNumber(secondParent);
				found = firstNumber * secondNumber == number;
			});
		});
	});

	return found;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cases;
	cin >> cases;
	while (cases--) {
		long long number;
		cin >> number;
		cout << (isHerederNumber(number) ? "Heredero" : "No") << '\n';
	}
}
