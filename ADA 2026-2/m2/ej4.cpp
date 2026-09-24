#include <iostream>

using namespace std;

int GCD(int a, int b) {
    return b==0?a:GCD(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int c, I,V,X;

    for(cin>>c;c>0;c--) {
        cin>>I; cin>>V; cin>>X;

        int gcd = GCD(GCD(I,V), X);

        cout<<(int)(I/gcd + V/gcd + X/gcd)<<endl;
    }
    return 0;
}