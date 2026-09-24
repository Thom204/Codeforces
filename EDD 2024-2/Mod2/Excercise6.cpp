#include <iostream>

using namespace std;

void splitToArray(string input, int* arr, int size, char delim){
    int delPos, content;
    for(int i=0; i<size; i++){
        delPos= input.find_first_of(delim);
        string sub= input.substr(0, delPos);
        input.erase(0, delPos+1);
        content= stoi(sub);
        *(arr+i)= content;
    }
}

int recorrer(int size, int map[]){
    int pos, step, acm;
    int steps[size]={0*size};
    acm=0;
    while(pos>=0 && pos<size){
        step= map[pos];
        steps[acm]= pos;
        pos+=step;
        acm++;
        for (int i: steps){
            if(pos==i){
                return acm;
            }
        }
    }
    return acm;
}

int main(){
    int casos, len;
    string mapp;
    cin>>casos;
    int output[casos];
    for (int i=0; i<casos; i++){
        cin>>len;
        int map[len];
        getline(cin>>ws, mapp);
        splitToArray(mapp, map, len, ' ');
        output[i]= recorrer(len, map);
    }
    for(int i: output){
        cout<<i<<endl;
    }
    return 0;
}