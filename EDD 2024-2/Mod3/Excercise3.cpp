#include <iostream>
#include <vector>

using namespace std;
void delNum(int n, vector<int>& log){
    if(n<= log.size()){
        for(int i=0; i<n; i++){
            log.pop_back();
        }
    }
}

void printNum(int i, int j, vector<int>& log, vector<string>& out){
    string s= "";
    if(j>=i && j<= log.size()){
        for(int e= i; e<=j; e++){
            s += to_string(log[e-1]);
        }
        out.push_back(s);
    }
}

int main(){
    int pos, arg1, arg2;
    string input= "";
    char comm;
    vector<int> log={};
    vector<string> out={};

    while(input!="end"){
        getline(cin>>ws, input);
        comm= input[0];

        switch(comm){
            case 'C':
                delNum(1, log);
                break;
            case 'D':
                arg1= stoi(input.substr(1, input.length()-1));
                delNum(arg1, log);
                break;
            case 'M':
                pos= input.find_last_of(' ');
                arg1= stoi(input.substr(2, pos));
                arg2= stoi(input.substr(pos, input.length()-1));
                printNum(arg1, arg2, log, out);
                break;
            case 'e':
                break;
            default:
                log.push_back(stoi(input));
        }
    }
    for(string i: out){
        cout<<i<<endl;
    }
    return 0;
}