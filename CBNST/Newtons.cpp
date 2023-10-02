// You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.

// You can apply the following operation on any of the two strings any number of times:

// Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
// Return true if you can make the strings s1 and s2 equal, and false otherwise.
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n!=m)
            return false;
        int a[26]={0};
        for(int i=0;i<n;i++)
        {
            a[s1[i]-'a']++;
            a[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]!=0)
                return false;
        }
        return true;
    }
};
