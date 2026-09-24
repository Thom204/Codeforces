#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, len;
    string input;
    cin>>n;
    getline(cin>>ws, input);
    len= input.length()-1;
    for(int i=0; i< input.length()/2; i+=3){
        cout<<input[i]<<input[len-i];
    }
    if(((len)/3 +1)%2==1){cout<<input[len/2];}
    return 0;
}