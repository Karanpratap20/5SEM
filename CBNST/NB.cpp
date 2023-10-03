#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[50][50];
    int n=5;
    for(int i=0;i<n;i++){
        cout<<"Value"<<endl;
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    for(int j=2;j<=n;j++){
        for(int i=0;i<n-j+1;i++){
            arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    double x=1925;
    double y=arr[n-1][1];
    double u=(double)(x-arr[n-1][0]) / (arr[1][0]-arr[0][0]);
    double u1=u;
    double fact=1;

    for(int i=2;i<=n;i++){
        y=y+(u1*arr[n-i][i])/fact;
        u1=u1*(u+(i-1));
        fact=fact*i;
    }
    cout<<y<<endl;

    return 0;
}