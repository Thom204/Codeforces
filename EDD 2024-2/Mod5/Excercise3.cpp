#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    deque<int> uroboro;
    string input;

    while (true) {
        getline(cin, input);
        istringstream iss(input);
        string comm;
        iss >> comm;

        if (comm == "termina") {
            break;
        }

        if (comm == "agrega") {
            int m;
            iss >> m;
            uroboro.push_back(m);
        }

        if (comm == "engulle") {
            int cola = uroboro.back();
            if (uroboro.front() > cola) {
                uroboro.pop_back();
            } else {
                uroboro.pop_front();
            }
        }
    }

    if (uroboro.empty()) {
        cout << "uroboro vacio" << endl;
    } else {
        cout << "cabeza " << uroboro.front() << " cola " << uroboro.back() << endl;
    }

    return 0;
}
