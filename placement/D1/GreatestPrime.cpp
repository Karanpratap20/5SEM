#include<bits/stdc++.h>
using namespace std;

int greatestPrime(int n){
    int ans=0;
    while (n % 2 == 0) {
        ans = 2;
        n /= 2;
    }
    for (int i = 3; i*i <= n; i += 2) {
        while (n % i == 0) {
            ans = i;
            n = n / i;
        }
    }
    if (n > 2) {
        ans = n;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<greatestPrime(n);
    return 0;
}