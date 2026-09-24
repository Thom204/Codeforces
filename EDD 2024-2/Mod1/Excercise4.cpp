#include <iostream>

using namespace std;
int main(){
    int i;
    cin>>i;

    if(i%2==0){
        cout<<"es multiplo de 2";
    }else if(i%3==0){
        cout<<"es multiplo de 3";
    }else if(i%5==0){
        cout<<"es multiplo de 5";
    }else if(i%7==0){
        cout<<"es multiplo de 7";
    }else{
        cout<<"no es multiplo de ninguno de los primeros cuatro primos";
    }
    return 0;
}