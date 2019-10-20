#include <iostream> 
using namespace std; 
  

int main () 
{ 
    
    long long N, A, B, x,y;
    cin>>N;
    cin>>A;
    cin>>B;
    if(A>N)cout<<"NO\n";
    
    if((B>=N)&&(A<=N))cout<<N<<"\n";
    else{
        x=N%B;
        y=N/B;
        if(x>=A){
            cout<<"YES\n";
            cout<<x;
            for(int i=1; i<=y; i++)cout<<" "<<B;
            cout<<"\n";
        }
        else{
            bool ok= false;
            long long cur=-42;
            long long y1=y;
            long long x1=x;
            while(y1>0){
                y1--;
                cur=B+x1-A;
                if(cur>=A){
                    ok=true;
                    break;
                }
                else x1=cur;
            }
                
                
            if(ok){
                cout<<"YES\n";
                
                long long y2=y;
                long long x2=x;
                for(int i=1; i<=y-y1; i++)cout<<A<<" ";
                if(y1<y)cout<<cur;
                for(int i=1; i<=y1; i++)cout<<" "<<B;
                cout<<"\n";
            }
            else cout<<"NO\n";
        }
    }
    
    return 0; 
}