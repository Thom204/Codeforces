#include <iostream>
#include <deque>
#include <string>

using namespace std;

bool validateSeq(const string& seq) {
    deque<char> D;

    for(char i: seq){
        if(i!=' ')D.push_back(i);
    }
    D.pop_back();

    while (!D.empty()) {
        char C = D.front(); D.pop_front();

        if (C == '(') {
            if (D.front() != ')' && D.back() != ')') {
                return false;
            } else if (D.front() == ')') {
                D.pop_front();
            } else {
                D.pop_back();
            }

        } else if (C == '[') {
            if (D.front() != ']' && D.back() != ']') {
                return false;
            } else if (D.front() == ']') {
                D.pop_front();
            } else {
                D.pop_back();
            }

        } else if (C == '{') {
            if ((D.front() != '}' && D.back() != '}')) {
                return false;
            } else if (D.front() == '}') {
                D.pop_front();
            } else {
                D.pop_back();
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        string in;
        getline(cin>>ws, in);

        if (validateSeq(in)) {
            cout << "correcta" << endl;
        } else {
            cout << "incorrecta" << endl;
        }
    }
    
    return 0;
}