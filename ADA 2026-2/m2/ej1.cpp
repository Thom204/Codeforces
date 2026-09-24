#include <iostream>
#include <math.h>

using namespace std;

int factorize(int n) {
    int confcount = 0, lim = sqrt(n);

    for (int i=1; i<=lim; i++) {
        if (n % i == 0) {
            confcount += (i==lim)?1:2;
        }
    }

    return confcount;
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int nc, number;
    cin>>nc;

    for(;nc>0;nc--){
        cin>>number;
        cout<<factorize(number)<<endl;
    }

    return 0;
}