#include<iostream>

using namespace std;
int main(){
    string tSo, tLa, tRis;
    int N, so, la, ris, cSo, cLa, cRis, turn;
    cin>>N;
    getline(cin>>ws, tSo);
    getline(cin>>ws, tLa);
    getline(cin>>ws, tRis);
    so=0;
    la=0;
    ris=0;

    for(int i=0; i<N; i++){
        cSo= stoi(tSo.substr(0, 1));
        cLa= stoi(tLa.substr(0, 1));
        cRis= stoi(tRis.substr(0, 1));

        turn= (cSo+cLa+cRis)%2;

        (cSo%2== turn)? so++: so+=0;
        (cLa%2== turn)? la++: la+=0;
        (cRis%2== turn)? ris++: ris+=0;
        
        if(i < N-1){
            tSo.erase(0,3);
            tLa.erase(0,3);
            tRis.erase(0,3);
        }
    }
    cout<<"SO:"<<so<<", LAR:"<<la<<", IS:"<<ris;    
    return 0;
}