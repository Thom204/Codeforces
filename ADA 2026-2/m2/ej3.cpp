#include <iostream>
#include <bitset>
#include <math.h>
#include <vector>
#include <omp.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int c, n;
    cin>>c;
    bitset<100001> compdb;
    vector<int> acm(1000001);
    
    compdb[0] = compdb[1] = true;

    int lim = 316;

    #pragma omp parallel;
    for(int j = 4; j<=100000; j+=2) {
        compdb[j] = true; //marcar pares
    }

    for(int p = 3; p<=lim; p+=2) {
        if (!compdb[p]) {
            for (int i = p*p; i<=100000; i+=2*p) {
                compdb[i] = true; //ir eliminando multiplos de primos
            }
        }
    }
    
    int ctr = 0;
    for(int i =0; i<100001; i++) {
        ctr += (int)(!compdb[i]);
        acm[i] = ctr;
    }

    for(;c>0;c--){
        cin>>n;
        cout<<(int)round(acm[n] - n/log(n))<<endl;
    }

    return 0;
}
