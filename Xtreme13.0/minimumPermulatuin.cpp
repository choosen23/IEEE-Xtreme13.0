#include <bits/stdc++.h>

using namespace std;
int N,M;



int partition(int* &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
        }
        while(values[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}
void quicksort(int* &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}
int main() {
    
    cin >> N >> M;
    int* A = new int[N];
    int* S = new int[M];
    vector<list<int>> Final;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        list<int> newList;
        newList.push_back(A[i]);
        Final.push_back(newList);
    }
    for (int i=0; i<M; i++) cin >> S[i];
    quicksort(S,0,M-1);
    int pointerofS=0;
    int i=0;
    while (i<Final.size() && pointerofS < M){
        if (i!=0 && Final[i].front()>S[pointerofS]){
            Final[i-1].push_back(S[pointerofS]);
            pointerofS++;
            continue;
        }else if ( i==0 && Final[i].front()>S[pointerofS]){
            list<int> newList;
            newList.push_back(S[pointerofS]);
            Final.insert(Final.begin(),newList);
            pointerofS++;
            i++; 
            continue;
        }else if (i==Final.size()-1){
            Final[i].push_back(S[pointerofS]);
            pointerofS++;
            continue;
        }
        i++;     
    }
    for (int i=0; i < Final.size(); i++){
        for( list<int>::iterator t=Final[i].begin(); t!=Final[i].end(); t++){
            if (i!=Final.size()) cout << *t << " ";
            else {
                if (t!=Final[i].end()) cout << *t << " ";
                else cout << *t;
            }
        }
    }
    cout << endl;


}