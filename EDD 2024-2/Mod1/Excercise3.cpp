#include <iostream>

using namespace std;
int main(){
    int Ninput;
    int num;
    int poSum=0;
    int negSum=0;

    cin>>Ninput;
    for (int i=0; i<Ninput; i++){
        cin>>num;
        if(num>=0){
            poSum+=num;
        }else{
            negSum+=num;
        }
        num=0;
    }
    cout<<"positivos "<<poSum<<", negativos "<<negSum;
    return 0;
}