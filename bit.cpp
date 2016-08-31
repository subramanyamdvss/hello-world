#include <bits/stdc++.h>
#include <string.h>
using namespace std;

typedef  long long lli;
typedef vector< long long int > vi;
typedef  double d;
typedef  pair<lli,pair<lli,lli> >  pipii;
#define bg begin()
#define rbg rbegin()
#define ren rend()
#define en end()
#define f first
#define s second
#define For(ii,aa,bb) for(lli ii=aa;ii<=bb;++ii)
#define Rof(ii,aa,bb) for(lli ii=aa;ii>=bb;--ii)
#define pb push_back
#define minf(a,b,c) min(min(a,b),c)
#define maxf(a,b,c) max(max(a,b),c)
#define mp make_pair
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}
/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;


void createbit(lli A[],lli bit[],lli n){
    For(i,1,n){
        lli r=i&(-i);
        //error(r);
        lli k=i;
        while(r--){
            bit[i]+=A[k];
            error(r,k,A[k]);
            k--;
        }
    }
    return;
}

void update(lli A[],lli bit[],lli n,lli key ,lli val){
    lli x=key;
    while(x<=n){
        bit[x]+=val;
        x+=x&(-x);
    }
    return;
}

lli prefixsum(lli A[],lli bit[],lli n,lli key){
    lli prb=key,sum=0;
    while(prb>=1){
        sum+=bit[prb];
        prb=prb-(prb&(-prb));
    }
    return sum;
}

int main(){
    lli n;
    cout<<"enter n"<<endl;
    cin>>n;
    lli A[n+1],bit[n+1];
    cout<<"enter A values"<<endl;
    For(i,1,n){
        cin>>A[i];
        bit[i]=0;
    }
    createbit(A,bit,n);
    For(i,1,n) cout<<bit[i]<<endl;
    cout<<"enter key and val"<<endl;
    lli key,val;
    cin>>key>>val;
    update(A,bit,n,key,val);
    lli sum=prefixsum(A,bit,n,key);
    cout<<"sum: "<<sum<<endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}






