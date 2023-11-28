#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fasterIO ios::sync_with_stdio(0); cin.tie(0);
//Snippet_list:snippet for algos
typedef vector<int> vi;
typedef vector<long long> vll;
//typedef pair<int,int> Pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
#define Pll pair<ll,ll>
#define Pii pair<int,int>
#define ld  long double
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define FF first
#define SS second
#define SZ(x) ((int)(x).size())
#define mset(a,x) memset(a, x, sizeof(a))
#define forn(i,a,n) for (int i=a;i<n;i++)
#define printclock  cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
const ll MOD=1000000007;
// Bitmask:     for(int i=1;i<(1<<n);i++){for(int j=1;j<=n;j++){if(i&(1<<(j-1))){}}}
ll   gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll   Lcm(ll a,ll b) {return ((a*b)/__gcd(a,b));}
ll   POW(ll a,ll b) {ll res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res; }
int  sum_digit(int x) { int sum=0; while(x>0){ sum+=x%10; x/=10; } return sum; }
ll   reverse_num(ll n){ ll tmp=n, ans=0, r; while(tmp>0){ r=tmp%10; ans=ans*10+r; tmp/=10; } return ans; }
bool isSquare(ll x){ll sq=sqrt(x);return sq*sq==x;}
bool prime(ll n) { if(n<2) return false; for(ll i=2;i<=sqrt(n);i++){ if(n%i==0)return false;} return true; }
ll   string_to_int(string s){ int len = (int)s.size();ll ans=0;forn(i,0,len)ans=ans*10+(int)s[i]-'0';return ans; }

#define CY cout<<"YES\n";
#define CN cout<<"NO\n";
#define CYR cout<<"YES\n";return;
#define CNR cout<<"NO\n";return;
#define C(s) cout<<s<<endl;
int const lim=1e5+10;
vll seg_ar(lim);
vll seg_tre(lim*4);

void build_tree(int node,int b,int e){

  if(b==e){
    seg_tre[node]=seg_ar[b];
    return;
  }
  int l=2*node,r=2*node+1;
  int mid=(b+e)/2;
  build_tree(l,b,mid);
  build_tree(r,mid+1,e);
  seg_tre[node]=seg_tre[l]+seg_tre[r];

}

ll query(int node,int b,int e,int i,int j){

  if(e<i||b>j)return 0;
  if(b>=i && e<=j)return seg_tre[node];
 int l=2*node,r=2*node+1;
 int mid=(b+e)/2;
 return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);

}

//ll val=0;
void Update(int node,int b,int e,int i,int x,int f){

  if(b>i||e<i) return;
  if(b==e && b==i){
  	if(f==1){
  		cout<<seg_tre[node]<<endl;
  		seg_tre[node]=0;
  	}
  	else if(f==2) seg_tre[node]+=x;
  	return;
    //return val;
  }
  int l=2*node,r=2*node+1;
  int mid=(b+e)/2;
  Update(l,b,mid,i,x,f);
  Update(r,mid+1,e,i,x,f);
  seg_tre[node]=seg_tre[l]+seg_tre[r];

}




void fun()
{
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)
    cin>>seg_ar[i];
  build_tree(1,1,n);
  while(q--){
    int x,u,v;cin>>x;
    if(x==1){
    	cin>>u;
        Update(1,1,n,u+1,0,1);
        //cout<<val<<endl;
    }
    else if(x==2){
    	cin>>u>>v;
      Update(1,1,n,u+1,v,2);
    }
    else {
    	cin>>u>>v;
     cout<<query(1,1,n,u+1,v+1)<<endl;;
    }
  }
 // cout<<query(1,1,n,2,5)<<endl;
  /*for(int i=1;i<=20;i++){
  	cout<<i<<" "<<seg_tre[i]<<endl;
  }*/
    

}


int main()
{
    fasterIO
    #ifndef ONLINE_JUDGE
    freopen("D:/input_output/input.txt", "r", stdin);
    freopen("D:/input_output/output.txt", "w", stdout);
    #endif
    int t=1;cin>>t;
    for(int i=1;i<=t;i++)
    {
    	cout<<"Case "<<i<<":"<<endl;
        fun();
    }
    
    printclock

}

