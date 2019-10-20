#include <iostream>
#include <set>
#include <map>
using namespace std; 
# define INF 10000000000
  
int N;
typedef long long ll;
ll read_int() {
    ll n = 0;
    char c = getchar_unlocked();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

map<pair<int, long long >,long long> A;
map<pair<int, long long >,long long>::iterator it;
ll ks[10][100];
int kn[10];



long long a(int i, long long B){
    //
    if(B<0)return -1*INF;
    if((i==N)&&(B>=0))return 0;
    pair<long long , int> p(i,B);
    it = A.find(p);
    if (it != A.end())return it->second;
    
    long long max=-1*INF;
    long long tmp;
    for( int j=0; j<kn[i]; j++){
        tmp=a(i+1, B-ks[i][j])+ks[i][j];
        if(max<tmp) max=tmp;
    }
    A[p]=max;
    //cout<<max<<"\n";
    return max;
  
}




int main(){
    int T;
    long long B;
    
    T = read_int();
    for(int t=0; t<T; t++){
        B=read_int();
        N=read_int();
        for(int n=0; n<N; n++){
            kn[n]=read_int();;   
        }
        for(int n=0; n<N; n++){
            for(int k=0; k<kn[n]; k++){
                ks[n][k]=read_int();;
            } 
        }
        
        A.clear();
        if(a(0,B)>0)cout<<a(0,B)<<"\n";
        else cout<<"0\n";
    }
    return 0;
}