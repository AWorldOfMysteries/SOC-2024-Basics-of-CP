#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        unordered_map<int, int> heightToRopeLength;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            int h, l;
            cin >> h >> l;

            if(l < h)
                ans++;
        }

        cout << ans << endl;


    }

    return 0;
}