#include<bits/stdc++.h>
using namespace std;
 
float func( float x)
{
    return (1 / ( 1 + x * x ));
}
 
float calculate(float ll, float ul,int il )
{
    float value;
    float is = (ul - ll)/ il;
    float sum = func(ll) + func(ul);
 
    for (int i = 1 ; i < il ; i++)
    {
        if (i % 3 == 0)
            sum = sum + 2 * func(ll + i * is);
        else
            sum = sum + 3 * func(ll + i * is);
    }
    return ( 3 * is / 8 ) * sum ;
}
 
int main()
{
    int interval_limit = 10;
    float lower_limit = 1;
    float upper_limit = 10;
    float integral_res = calculate(lower_limit, upper_limit,
                                   interval_limit);
 
    cout << integral_res;
    return 0;
}