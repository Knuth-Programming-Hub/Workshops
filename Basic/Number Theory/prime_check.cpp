#include <iostream>
using namespace std;
/// 1- brute force O(n)
bool isprime(int n)
{
    if(n==1)
    {
        return false;
    }
    if(n==2)
    {
        return true;
    }
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

/// 2- square root approach O(root n)
bool isprime2(int n)
{
     if(n==1)
    {
        return false;
    }
    if(n==2)
    {
        return true;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;

}
int main() 
{
    int n;
    cin>>n;
    bool x=isprime2(n);
    if(x==true)
    {
        cout<<"It is a prime no";
    }
    else
    {
        cout<<"Not a prime no";
    }
}