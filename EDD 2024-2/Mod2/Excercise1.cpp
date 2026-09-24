#include <iostream>

using namespace std;

int main(){
    string str;
    int N, acm;
    cin>>N;
    int arr[N];
    getline(cin>>ws, str);

    for(int i=0; i<N; i++){
        int pos= str.find_first_of(' ');
        string sub= str.substr(0, pos);
        str.erase(0, pos+1);
        arr[i]= stoi(sub);
    }
    acm= arr[N-1];
    for(int a=(N-1); a>0; a--){
        acm+= arr[a-1];
        cout<<acm<<endl;
    }
}