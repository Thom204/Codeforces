#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void splitToVector(string input, vector<int>& arr, int size,char delim){
    int delPos;
    for(int i=0; i<size; i++){
        delPos= input.find_first_of(delim);
        string sub= input.substr(0, delPos);
        input.erase(0, delPos+1);
        arr[i]= stoi(sub);
    }
}

int repartir(int n, int b, vector<int>& bills){
    vector<int> distribucion(n);
    fill(distribucion.begin(), distribucion.end(), 0);
    int actor, len;
    for (int i=0; i<b; i++){
        distribucion[i%n]= bills[i]+ distribucion[i%n];
    }
    return *max_element(distribucion.begin(), distribucion.end()) - *min_element(distribucion.begin(), distribucion.end());
}


int main(){
    int casos, n, b, pos;
    string line, bills;
    cin>>casos;
    int out[casos];
    for (int i=0; i<casos; i++){
        getline(cin>>ws, line);
        getline(cin>>ws, bills);
        pos= line.find_first_of(' ');
        n= stoi(line.substr(0, pos));
        b= stoi(line.substr(pos, line.length() -1));
        vector<int> billetes(b); 
        splitToVector(bills, billetes, b, ' ');
        out[i]= repartir(n, b, billetes);
    }
    for(int i: out){
        cout<<i<<endl;
    }
    return 0;
}