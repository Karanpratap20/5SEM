#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of points: "<<endl;
    cin>>n;
    vector<vector<int>> v(2,vector<int>(n));
    for(int i=0;i<n;i++){
        cin>>v[0][i];
        cin>>v[1][i];
    }
    cout<<"Enter the value of x: "<<endl;
    double x;
    cin>> x;
    double ans=0,num,den;
    for(int i=0;i<n;i++){
        num=den=1;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            num*=(x-v[0][j]);
            den*=(v[0][i]-v[0][j]);
        }
        ans+=((1.0*num*v[1][i])/den);
    }
    cout<<"The value of y at x is: "<<ans<<endl;
    return 0;
}