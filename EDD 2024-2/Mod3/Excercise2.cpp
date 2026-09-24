#include <iostream>
#include <vector>

using namespace std;
int tinmarin(int K, vector<int>& st){
    int index=0;
    int stud;
    while (st.size()>1){
        index= (index+K-1)% st.size();
        stud= st[index];
        st.erase(st.begin()+index);
        K= stud%st.size();
        if(K==0){K++;}
    }
    return st[0];
}

int main(){
    int cases, N, K, pos;
    string input;
    vector<int> students={};
    cin>>cases;
    vector<int> out(cases);
    for(int i=0; i<cases; i++){
        getline(cin>>ws, input);
        pos= input.find_first_of(' ');
        N= stoi(input.substr(0,pos));
        K= stoi(input.substr(pos, input.length()-1));

        for(int j=0; j<N; j++){students.push_back(j+1);}
        out[i]= tinmarin(K, students);
        students.clear();
    }

    for (int i: out){
        cout<<i<<endl;
    }
    return 0;
}