// M1 : Brute force

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inp(n) ll n; cin >> n;
#define inpv(v, n) for(ll i=0; i<n; i++) cin >> v[i]

class Node{
    
    public: 
        ll data;
        Node* left;
        Node* right;
    
    Node(ll data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    Node(){
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(ll left, ll right, vector<ll> &a){

    // base case
    if(left == right){
        Node* root = new Node(a[left]);
        return root;
    }

    // get maxI
    ll maxI = left;
    for(ll i=left; i<=right; i++){
        if(a[i] > a[maxI])
            maxI = i;
    }

    // Build Tree
    Node* root = new Node(a[maxI]);
    if(maxI == left){
        root->right = buildTree(maxI+1, right, a);
    }
    else if(maxI == right){
        root->left = buildTree(left, maxI-1, a);
    }
    else{
        root->left = buildTree(left, maxI-1, a);
        root->right = buildTree(maxI+1, right, a);
    }

    return root;
}

ll calculateDepth(Node* root, ll val){
    if(root->data == val)
        return 0;

    ll cnt = 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL && !q.empty()){
            cnt++;
            q.push(NULL);
            continue;
        }
        if(frontNode->data == val)
            return cnt;

        if(frontNode->left)
            q.push(frontNode->left);
        if(frontNode->right)
            q.push(frontNode->right);
    }

    return -1;
}

void solve() {
    
    inp(n);
    vector<ll> a(n);
    inpv(a, n);

    vector<ll> ans(n);

    Node* root = buildTree(0, n-1, a);

    for(ll i=0; i<n; i++){
        cout << calculateDepth(root, a[i]) << " ";
    }
    cout << endl;


}

    
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}


// --------------------------------------------------------------

// M2 : Only recursion

// #include <bits/stdc++.h> 
// using namespace std;

// #define ll long long
// #define all(x) x.begin(),x.end()
// #define inpv(v, n) for(ll i=0; i<n; i++) cin >> v[i]

// const ll MOD=998244353;
// const ll MAX=500500;

// void buildAns(ll l, ll r, vector<ll> &a, ll level, unordered_map<ll, ll> &umap){
//     // BC
//     if(l > r) return;

//     // get maxI
//     ll maxI = l;
//     for(ll i=l; i<=r; i++){
//         if(a[i] >= a[maxI])
//             maxI = i;
//     }

//     // set level
//     umap[a[maxI]] = level;
    
//     // recursive calls
//     buildAns(l, maxI-1, a, level+1, umap);
//     buildAns(maxI+1, r, a, level+1, umap);

//     return;
// }

// void solve(){
//     ll n; cin >> n;
//     vector<ll> a(n);
//     inpv(a, n);

//     unordered_map<ll, ll> umap;

//     buildAns(0, n-1, a, 0, umap);

//     for(int i=0; i<n; i++){
//         cout << umap[a[i]] << " ";
//     }
//     cout << endl;
// }

// int main()                                                                                 
// {         
//     ios_base::sync_with_stdio(false);                         
//     cin.tie(0); cout.tie(0);                               
//     ll test_cases=1;                 
//     cin>>test_cases;
//     while(test_cases--){
//         solve();
//     }
//     cout<<fixed<<setprecision(10);
//     // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n"; 
// } 