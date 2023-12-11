#include<bits/stdc++.h>
using namespace std;

double forward(vector<vector<int>> arr,int n,double x){
    double y=arr[n/2][1]; 
    double u=(x-arr[n/2][0])/(arr[1][0]-arr[0][0]);
    double u1=u;
    double fact=1;
    for(int i=2;i<=n;i++){
        y=y+(u1/fact)*arr[(n-1)/i][i];
        fact=fact*i;
        if(i%2==0){
            u1=u1*(u-(i/2));
        }
        else{
            u1=u1*(u+(i/2));
        }
    }
    return y;
}

double backward(vector<vector<int>> arr,int n,double x){
    double y=arr[n/2][1]; 
    double u=(x-arr[n/2][0])/(arr[1][0]-arr[0][0]);
    double u1=u;
    double fact=1;
    for(int i=2;i<=n;i++){
        y=y+(u1/fact)*arr[(n-2)/i][i];
        fact=fact*i;
        if(i%2==0){
            u1=u1*(u+(i/2));
        }
        else{
            u1=u1*(u-(i/2));
        }
    }
    return y;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n+1));
    double x;
    for(int i=0;i<n;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    cout<<"enter the value to predict\n"<<endl;
    cin>>x;
    for(int j=2;j<n+1;j++){
        for(int i=0;i<n-j+1;i++){   
            arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"Value forward at "<<x<<" is "<<forward(arr,n,x)<<endl;
    cout<<"Value backward at "<<x<<" is "<<backward(arr,n,x)<<endl;
    
    return 0;
}