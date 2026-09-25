#include<iostream>
#include<math.h>
#include<sstream>
#include<vector>


using namespace std;
template <typename T, typename Func>

void permute(vector<T>& v, size_t start, size_t end, Func proc_fn) {
    if (start >= end) {
        proc_fn(v);
        return;
    }

    for (size_t i = start; i <= end; ++i) {
        swap(v[start], v[i]);
        permute(v, start + 1, end, proc_fn);
        swap(v[start], v[i]);
    }
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int nc, i, n;
    string s;
    vector<int> v(9);
    cin>>nc;

    for(;nc>0;nc--){
        getline(cin>>ws, s);
        stringstream ss(s);
        i=0;
        ss>>n;
        while(ss>>v[i]) i++;

        int confctr=0;

    permute(v, 0, v.size()-1, [&confctr, &n](vector<int>&vv){
            int psum = 0;
            for(size_t e=0; e<9; e++) {
                psum += vv[e];

                if (e == 3 || e==6 ||e==8) {
                    if (e==8) psum+=vv[0];

                    if (psum != n) return;
                    
                    psum = vv[e];
                }
            }
            confctr+=1;
        });
        
        cout<<confctr<<endl;
    }

    return 0;
}