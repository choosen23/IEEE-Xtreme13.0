#include <bits/stdc++.h>



using namespace std;

typedef unsigned long long ll;



int main() {
    ll fores,maxi,mini,K,J,res=0;
    cin >> K >> J;

    maxi = max(K, J);
    mini = min(J, K);
    
    if(((maxi==0)||(mini==0))||((maxi==1)&&(mini==1))) {
        cout << "0" << endl;
        return 0;
    }
    
    if (maxi==2) {
        cout << "1" << endl;
        return 0;
    }
    
    fores=maxi/mini;
    if (fores >= 2 ) {
        res = mini;
    }
    else {
        res+=(maxi-mini);
        ll N = 2*mini - maxi;
        res+=(2*(N/3));
        if (N % 3 == 2) res++;
    }
    cout << res <<endl;
    
}