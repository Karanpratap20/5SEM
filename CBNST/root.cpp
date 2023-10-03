#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x  - 2 * x  - 1;
}
double func(double a,double b,double epsilon){
    if(f(a)*f(b)>0){
        cout<<"Wrong Input"<<endl;
        return 0;
    }
    double c;
    while((b-a)>=epsilon){
        c=(a+b)/2;
        if(f(c)==0.0){
            break;
        }
        else if(f(c)*f(a)<0){
            b=c;
        }
        else{
            a=c;
        }
    }
    return c;
}
int main(){
    double a,b,epsilon;
    cin>>a>>b>>epsilon;
    double ans=func(a,b,epsilon);
    cout<<ans<<endl;
    return 0;
}