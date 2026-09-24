#include <iostream>
#include <cmath>
#include <map>

using namespace std;

map<int, int> nunudon;

int nununext(int ni) {
    int di = 0, lim=sqrt(ni);
    for (int i = 1; i<=lim; i++) {
        if(ni%i==0) {di += (i*i == ni?1:2);}
    }
    return ni + di;
}

void fillnunudon(map<int,int> &numap, int n) {
    map<int,int>::reverse_iterator e = numap.rbegin();
    int ni = e->first, idx = numap[ni];

    while (ni<n) {
        ni = nununext(ni);
        idx++;
        numap[ni] = idx;
    }
    
    ni = nununext(ni);
    idx++;
    numap[ni] = idx;
}



int main() {
    ios::sync_with_stdio(false);cin.tie(0);        
    int c,a,b,nmax;
    nunudon[1] = 0;
    fillnunudon(nunudon, 100000);

    for(cin>>c;c>0;c--) {
        cin>>a; cin>>b;
        //if (b > nunudon.rbegin()->first) fillnunudon(nunudon, b);
        cout<<nunudon.upper_bound(b)->second - nunudon.lower_bound(a)->second<<endl;
    }

    return 0;
}