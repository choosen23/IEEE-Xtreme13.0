#include <bits/stdc++.h>

using namespace std;

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<=std::tolower(c2); }






int main() {
    int N;
    cin >> N;
    for (int i =0; i<N; i++) {
        string str;
        cin >> str;
        int n = str.length();  
        char array[n]; 
        strcpy(array, str.c_str()); 
        for (int j=0; j<N; j++) {
          cout<< array[j]<<endl;
        }
        if ( n == 1 ) { //signle character
            cout << 1 ;
        }
        else {
           if (i==N-1) { cout << 0; break; }
                                    
           // cout << "Mpika" <<endl;
            if( lexicographical_compare(array, array+n/2, 
                                array+n/2 +1, array +n
                                )) {
                cout << 1;
            }
            else 
                cout <<0;
            } 
        }
        cout << endl;
  return 0;
}