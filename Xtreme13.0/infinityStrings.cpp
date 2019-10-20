#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll read_int() {
    int n = 0;
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



char reVal(int num) 
{ 
    if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'A'); 
} 
  
// Utility function to reverse a string 
void strev(char *str) 
{ 
    int len = strlen(str); 
    int i; 
    for (i = 0; i < len/2; i++) 
    { 
        char temp = str[i]; 
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; 
    } 
} 
  
// Function to convert a given decimal number 
// to a base 'base' and 
char* fromDeci(char res[], int base, int inputNum) 
{ 
    int index = 0;  // Initialize index of result 
  
    // Convert input number is given base by repeatedly 
    // dividing it by base and taking remainder 
    while (inputNum > 0) 
    { 
        res[index++] = reVal(inputNum % base); 
        inputNum /= base; 
    } 
    res[index] = '\0'; 
  
    // Reverse the result 
    strev(res); 
  
    return res; 
} 







int main() {

    char set1[] = {'a','b','c','d','e','f','g','h','i','j'
    ,'k','l' ,'m','n', 'o','p','q','r','s','t','u'
    , 'v', 'w','x','y','z'};


    ll X,sum;
    int T,B;
    T = read_int();
    for(int i=0; i<T; i++) {
        B = read_int();
        X = read_int();
        i = 1;
        sum = B;
        ll tmp = B;
        ll prev = 0;
        while ( sum > X ) {
            prev = sum;
            i++;
            sum+=i*tmp*B;
        }
        X = X - prev;
        ll k = X / i;
        ll y = X % i;
        k--;
        y--;
        char res[10000];
        char c = fromDeci(res,i,k)[y];
        cout << "mpika" <<endl;
        int ci = (int)c;
        cout << set1[ci] << endl;
    } 
    return 0;
}
