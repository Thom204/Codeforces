#include <iostream>

using namespace std;

int collatz(int i){
    if(i==1){
        return 1;
    }else if(i%2==0){
        return i/2;
    }else{
        return ((3*i)+1);
    }
}

int main(){
    int n;
    cin>>n;
    cout<<n<<endl;
    while(n>1){
       n= collatz(n);
       cout<<n<<endl; 
    }
    return 0;
}