#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void splitStream_ToVector(const std::string& input, std::vector<int>& arr, char delim) {
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delim)) {
        arr.push_back(std::stoi(token));
    }
}

int main(){
    string i;
    getline(cin>>ws, i);
    vector<int> vec={};

    splitStream_ToVector(i, vec, ' ');

    for(int j: vec){
        cout<<j<<endl;
    }
    return 0;
}