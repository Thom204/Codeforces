#include <iostream>

using namespace std;
int main(){
    int times;
    cin>>times;
    for (int i=0; i<times; i++){
        if(i%2==0){
            cout<<"Hola mundo"<<endl;
        }else{
            cout<<"Hello world"<<endl;
        }
    }
}