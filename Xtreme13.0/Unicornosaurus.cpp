#include <bits/stdc++.h>

using namespace std;

unsigned int N, M, S;

class Superpower {
public:
    unsigned int a, b, c;
    
    Superpower() {};

    void set(unsigned int aa, unsigned int bb, unsigned int cc) {
        a = aa;
        b = bb;
        c = cc;
    }
};

Superpower Powers[100000];

void addPower(unsigned int index, unsigned int a, unsigned int b, unsigned int c) {
    Superpower power;
    power.set(a,b,c);
    Powers[index] = power;
}

class State {
public:          
    unsigned int sum;
    long long int totalCost;
    int Fench[100000];
    bool avail[100000];

    State(unsigned int M, unsigned int S) {
        for(int i=0; i<S; i++) {
            Fench[i] = 1;
        }
        for(int i=0; i<M; i++) {
            avail[i] = true;
        }
        sum = S;
        totalCost = 0;
    }

    void setFench(unsigned int index, int value) {
        int prev = Fench[index];
        Fench[index] = value;
        if(value==0) {
            sum--;
        }
        else {
            if(prev==0) {
                sum++;
            }
        }
    }
};

State calculateNewState(State oldState, unsigned int index) {
    State state(M,S);
    unsigned int a, b, c;
    Superpower power = Powers[index];
    a = power.a; b = power.b; c = power.c;
    state.sum = oldState.sum;
    state.totalCost = oldState.totalCost + c;
    for(int i=0; i<S; i++) {
        state.Fench[i] = oldState.Fench[i];
        if((a<=i)&&(i<=b)) {
            state.setFench(i,1);
        }
    }
    for(int i=0; i<M; i++) {
        state.avail[i] = oldState.avail[i];
    }
    state.avail[index] = false;

    return state;
}

long long int solve(State state) {
    bool foundPower = false, foundSolution = false;
    long long int min;
    for(int i=0; i<M; i++) {
        if(state.avail[i]) {
            foundPower = true;
            State newState = calculateNewState(state, i);
           
            if(newState.sum == S) {
                if(foundSolution) {
                    if(newState.totalCost < min) {
                        min = newState.totalCost;
                    }
                }
                else {
                    foundSolution = true;
                    min = newState.totalCost;
                }
            }
            else {
                solve(newState);
            }
        }
    }
    if(!foundPower) {
        return -1;
    }
    return min;
}

int main(void) {
    cin >> N >> M >> S;
    State state(M,S);

    unsigned int Sum = S;
    unsigned int l, r;
    for(int i=0; i<N; i++) {
        cin >> l >> r;
        for(int j=(l-1); j<=(r-1); j++) {
            state.setFench(j,0);
        }
    }

    unsigned int a, b, c;
    for(int i=0; i<M; i++) {
        cin >> a >> b >> c;
        addPower(i,a,b,c);
    }

    long long int res = solve(state);
    cout << res << endl;

    return 0;
}