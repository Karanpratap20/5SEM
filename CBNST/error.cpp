#include<bits/stdc++.h>
using namespace std;

float AbsoluteError(float x, float y){
    return abs(x-y);
}
float RelativeError(float x, float y){
    return abs(x-y)/x;
}
float PercentageError(float x, float y){
    return abs(x-y)/x*100;
}
float roundOff(float x, int p){
    float y = x*pow(10,p);
    y = round(y);
    y = y/pow(10,p);
    return y;
}
int main(){
    float x,y;
    cin>>x;
    y=roundOff(x,4);
    float absError = AbsoluteError(x,y);
    float relError = RelativeError(x,y);
    float perError = PercentageError(x,y);
    cout<<"Absolute Error: "<<absError<<endl;
    cout<<"Relative Error: "<<relError<<endl;
    cout<<"Percentage Error: "<<perError<<endl;
    return 0;
}