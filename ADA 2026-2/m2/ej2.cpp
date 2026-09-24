#include <iostream>
#include <sstream>

using namespace std;

unsigned long long GCD(unsigned long long a,unsigned long long b) {return b==0?a:GCD(b, a%b);}

unsigned long long LCM(unsigned long long a, unsigned long long b) {
    return (a*b)/GCD(a,b);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    unsigned long long nc, n;
    string s;

    for(cin>>nc;nc>0;nc--) {
        // LCM(a,b) = a*b / GCD(a,b)
        // LCM(a,b,c) = LCM(LCM(a,b), c)
        getline(cin>>ws, s);
        stringstream ss(s);
        unsigned long long lcm;
        ss>>lcm;

        while(ss>>n) {
            lcm = LCM(lcm, n);
        }
        cout<<lcm<<endl;
    }

    return 0;
}