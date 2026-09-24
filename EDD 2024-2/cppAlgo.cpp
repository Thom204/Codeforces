#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void indef_splitToVector(string input, vector<int>& arr, string delim){
    size_t start= 0;
    int len= delim.length();
    for(size_t i=0; i<input.length(); i++){
        if(input.substr(i, len) == delim){
            arr.push_back(stoi(input.substr(start, i-start)));
            start= i+len;
        }
    }
    arr.push_back(stoi(input.substr(start)));
}

void splitToArray(string input, int* arr, int size, char delim){
    int delPos;
    for(int i=0; i<size; i++){
        delPos= input.find_first_of(delim);
        string sub= input.substr(0, delPos);
        input.erase(0, delPos+1);
        *(arr+i)= stoi(sub);
    }
}

void ptrSplitTovector(string input, vector<int>* v, int size, char delim){
    int dPos;
    int start= 0;
    string sub;
    for(int i=0; i<size; i++){
        dPos= input.find_first_of(delim);
        sub= input.substr(start, dPos-start);
        start+= dPos+1;
        (*v)[i] = stoi(sub);
    }
}

/*void splitToVector(string input, vector<int>& arr, int size, char delim){
    int delPos;
    int start=0;
    string sub;
    for(int i=0; i<size; i++){
        delPos= input.find_first_of(delim);
        sub= input.substr(start, delPos-start);
        start+= delPos+1;
        arr[i]= stoi(sub);
    }
}*/

/*void splitToVector(string input, vector<int>& arr, int size,char delim){
    int delPos;
    for(int i=0; i<size; i++){
        delPos= input.find_first_of(delim);
        string sub= input.substr(0, delPos);
        input.erase(0, delPos+1);
        arr[i]= stoi(sub);
    }
}*/

void splitStream_ToVector(const std::string& input, std::vector<int>& arr, char delim) {
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delim)) {
        arr.push_back(std::stoi(token));
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int len;
    string i;
    string i2;
    cin>>len;
    getline(cin>>ws, i);
    getline(cin>>ws, i2);
    vector<int> vec(len);

    ptrSplitTovector(i, &vec, len, ' ');
    //indef_splitToVector(i2, vec, " ");
    //splitStream_ToVector(i2, vec, ' ');

    for(int j: vec){
        cout<<j<<endl;
    }
    return 0;
}