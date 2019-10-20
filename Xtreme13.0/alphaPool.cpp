#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

  unsigned long long int sum[10000];

    

  unsigned long long int find(  unsigned long long int* &Arr, int index) {
    if(Arr[index]!=-1) {
        return Arr[index];
    }
    else {
          unsigned long long int sss = 0;
          int i = 1;
        while(1) {
              int d = index - sum[i];
            if (d<0) {
                break;
            }
            else {
                sss += find(Arr,d);
                sss = sss % mod;
            }
            i++;
        }
          int ans = sss % mod;
        Arr[index] = ans;
        return ans;
    }
}


int main() {
    
      int N, B;
    cin >> N;
    
      int add = 1;
    sum[0] = 0;
    sum[1] = add;
    for(  int i=2; i<1000; i++) {
        add = (add*2) % mod ;
        sum[i] = sum[i-1] + add;
    }
    
    for(  int w=0; w<N; w++) {
        cin >> B;
        if (B==0) {
            cout << "1" << endl;
            return 0;
        }
        
        
        unsigned long long int* Arr = new unsigned long long int[B+1];
        for(  int i=1; i<=B; i++) {
            Arr[i]=-1;
        }
        
        Arr[0] = 1;
        unsigned long long int ans = find(Arr,B) % mod;
        ans = (2*ans) % mod;
        cout << ans << endl;
    }
    
    return 0;
}