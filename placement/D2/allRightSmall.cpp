#include<bits/stdc++.h>
using namespace std;

vector<int> RightSmall(vector<int> v){
    int n=v.size();
    int g=INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(v[i]>g){
            g=v[i];
            ans.push_back(v[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> v={16,17,4,3,5,2};
    vector<int> ans=RightSmall(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}