#include<bits/stdc++.h>
using namespace std;

int chocolate(vector<int> v,int m){
    int n=v.size();
    int min=INT_MAX;
    sort(v.begin(),v.end());
    int i=0,j=m-1;
    while(j<n){
        if(v[j]-v[i]<min){
            min=v[j]-v[i];
        }
        i++;
        j++;
    }
    return min;
}

int main(){
    vector<int> v={7,3,2,4,9,12,56};
    int m=4;
    cout<<chocolate(v,m);
    return 0;
}