#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100000;
vector<int>prime(N,1);
vector<int>spf(N);

void sieve(){
    prime[0] = 0;
    prime[1] = 0;
    for(int i=4;i<N;i+=2){
        prime[i] = 0;
    }
    for(int i=3;i<N;i+=2){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[j] = 0;
            }
        }
    }
}

void spfCreate(){
    //spf[i] = i assuming all numbers are prime initially
    for(int i=2;i<N;i++){
        spf[i] = i;
    }
    //Even Numbers
    for(int i=4;i<N;i+=2){
        spf[i] = 2;
    }
    //Odd Numbers
    for(int i=3;i<N;i+=2){
        if(spf[i] == i){
            for(int j=i*i;j<N;j+=i){
                //does j has a spf assigned?
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

void primeFactorise(int n){
    while(n != 1){
        cout << spf[n] << ' ';
        n /= spf[n];
    }
    cout << "\n";
    // time complexity = log(n)
}

int32_t main()
{
    sieve();
    spfCreate();
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int n;
        cin >> n;
        //cout << prime[n] << ' ' << spf[n] << endl;
        primeFactorise(n);
    }
    return 0;
}