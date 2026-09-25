#include<iostream>
#include<limits>
#include<sstream>
#include<vector>
#include<algorithm>



template <typename T, typename Func>

void permute(std::vector<T>& v, std::size_t start, std::size_t end, Func proc_fn) {
    if (start >= end) {
        proc_fn(v);
        return;
    }

    for (std::size_t i = start; i <= end; ++i) {
        std::swap(v[start], v[i]);
        permute(v, start + 1, end, proc_fn);
        std::swap(v[start], v[i]);
    }
}


using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int nc,c;
    string s;
    cin>>nc;

    for(;nc>0;nc--){
        cin>>c;
        vector<vector<int>> adjm(c, vector<int>(c));
        vector<int> rt(c);

        for(int i = 0;i<c;i++){
            getline(cin>>ws, s);
            stringstream ss(s);
            string d;
            int j=0;
            while (ss >> d) {
                adjm[i][j] = (d=="n.a"?-1: stoi(d));
                j++;
            }
            rt[i] = i;
        }
        int glob_min = numeric_limits<int>::max();

        permute(rt, 0, c-1, [&glob_min, &adjm](const vector<int>& vv){
            int dsum=0;
            for (size_t i =0; i< vv.size()-1;i++) {
                if (adjm[vv[i]][vv[i+1]]<0) return;
                dsum += adjm[vv[i]][vv[i+1]];                

                if (dsum > glob_min) return;
            }
            glob_min = min(glob_min, dsum);    
        });

        if (glob_min < numeric_limits<int>::max()) cout<<(glob_min + 5) / 10;
        else cout<<"imposible";
        cout<<endl;
    }

    return 0;
}