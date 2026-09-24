#include <iostream>
#include <vector>

using namespace std;
int multiSum(int n, vector<int>& v){
    int acm=0;
    for(int i: v){
        (i%n==0)?acm+=i:acm+=0;
    }
    return acm;
}

int main(){
    char comm=' ';
    int val;
    string input;
    vector<int> v={};
    vector<int> output={};
    while(true){ 
        getline(cin>>ws, input);
        if(input[0]=='E'){
            break;
        }else{
            comm= input[0];
            val= stoi(input.substr(2, input.length()-1));
            if(comm=='A'){
                v.push_back(val); 
            }else if (comm=='M'){
                output.push_back(multiSum(val, v));
            }
        }
    }

    for(int i: output){
        cout<<i<<endl;
    }
    return 0;
}