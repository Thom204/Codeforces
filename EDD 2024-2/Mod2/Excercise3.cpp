#include<iostream>
#include <vector>

using namespace std;

void M1(std::vector<char>& vec){
    char tmp;
    for(int i=0; i< vec.size()-1; i+=2){
        tmp= vec[i+1];
        vec[i+1]= vec[i];
        vec[i]=tmp;
    }
}

void M2(std::vector<char>& vec){
    char tmp;
    int size= vec.size()-1;
    for(int i=0; i<(size/2)+1; i++){
        tmp=vec[size-i];
        vec[size-i]= vec[i];
        vec[i]=tmp;
    }
}

int main(){
    int num;
    cin>>num;
    vector<string> input(num);

    for(int i=0; i<num; i++){
        getline(cin>>ws, input[i]);
    }

    for(string i: input){
        vector<char> vec((i.length()/2)+1);
        int index=0;

        for(char c: i){
            if(c != ' '){
                vec[index]= c;
                index++;
            }
        }
        M2(vec);
        M1(vec);
        string decoded(vec.begin(), vec.end());
        cout<<decoded<<endl;
    }  
    return 0;
}