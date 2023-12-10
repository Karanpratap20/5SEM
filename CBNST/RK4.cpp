#include<bits/stdc++.h>
using namespace std;

float dydx(float x,float y){
    return ((x-y)/2);
}

float rungeKutta(float x0, float y0, float x, float h){
    int n = (int)((x - x0) / h);
    float k1, k2, k3, k4,k5;
    float y = y0;
    for (int i=1; i<=n; i++){
        k1 = h* dydx(x0 ,y);
        k2 = h* dydx(x0 + 0.5*h , y + 0.5*k1);
        k3 = h* dydx(x0 + 0.5*h , y + 0.5*k2);
        k4 = h* dydx(x0 + h , y + k3);
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
        x0 = x0 + h;
    }
    return y;
}

int main(){
    float x0 = 0, y = 1, x = 2, h = 0.2;
    cout <<"\nThe value of y at x is : "<< rungeKutta(x0, y, x, h)<<endl;
    return 0;
}