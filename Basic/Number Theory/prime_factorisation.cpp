#include <iostream>
using namespace std;
void prime_factors(int n)
{
    int c=0;
    for(int i=2;i*i<=n;i++)
    {
        c=0;
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
                c++;
            }
            cout<<i<<"->"<<c<<endl;
        }
    }
    if(n!=1)
    {
        cout<<n<<"-> "<<1<<endl;
    }
   
}
int main() 
{
    int n;
    cin>>n;
    prime_factors(n);
}
