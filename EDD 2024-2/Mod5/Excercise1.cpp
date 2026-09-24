#include<iostream>
#include<bits/stdc++.h>
#include<deque>

using namespace std;

int main(){
    int people, bol, pos, ctr, first, idFirst;
    string in;
    deque<int> dq;
    deque<int> ids;

    getline(cin>>ws, in);

    pos= in.find_first_of(' ');

    people= stoi(in.substr(0, pos));
    bol= stoi(in.substr(pos));

    for(int i=0; i<people; i++){
        getline(cin>>ws, in);
        pos= in.find_first_of(' ');

        ids.push_back(stoi(in.substr(0, pos)));
        dq.push_back(stoi(in.substr(pos)));
    }


    ctr=1;
    while(bol>0 && people>0){
        first= dq.front();
        idFirst= ids.front();

        if(first >= bol){
            dq.pop_front();
            dq.push_front(bol);
            bol= 0;
            cout<<ids.front()<<' '<<dq.front()<<endl;
            break;
        }

        if(ctr%5!=0){
            bol-=first;
            dq.push_back(first);
            ids.push_back(idFirst);
            dq.pop_front();
            ids.pop_front();
            ctr++; 
        }else{
            bol-= first;
            dq.pop_front();
            ids.pop_front();
            ctr++;
            people--;
        }
        if(people==0){
            cout<<"quedaron boletas disponibles"<<endl;
        }
    }

    return 0;
}