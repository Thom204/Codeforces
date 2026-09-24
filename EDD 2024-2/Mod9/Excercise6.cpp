#include <bits/stdc++.h>
#include <sstream>
#define cont(p, h) p.find(h) != p.end()

using namespace std;
typedef unordered_set<int> iSet;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    iSet pdd, pdi, pdc, todos;
    string input, partido;
    int id, uno, dos, tres;

    while(getline(cin>>ws, input) && input!="#"){
        stringstream ss(input);
        ss>>id>>partido;
        todos.insert(id);

        if (partido == "pdd" ) pdd.insert(id);

        if (partido == "pdi" ) pdi.insert(id);

        if (partido == "pdc" ) pdc.insert(id);
    }

    uno=0; dos=0; tres=0;

    for(int e: todos){
        int cnt= pdd.count(e) + pdi.count(e) + pdc.count(e);

        if(cnt==1) uno++;
        if(cnt==2) dos++;
        if(cnt==3) tres++;
    }

    cout<<uno<<" "<<dos<<" "<<tres;
    return 0;
}