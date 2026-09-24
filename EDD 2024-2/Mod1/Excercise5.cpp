#include <iostream>

using namespace std;
int main(){
    int base; 
    unsigned long long powr, lim;    
    cin>>base;
    cin>>lim;
    powr=base;
    
    while(powr<=lim){
        cout<<powr<<endl; 
        powr*=base;
    }
        
    return 0;
}