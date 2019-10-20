#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int tmp = rand()%2;
        if (tmp == 0) cout << "Y";
        else cout << "y";
    }
    cout << endl;
   
   
   //ok11
   return 0;
}