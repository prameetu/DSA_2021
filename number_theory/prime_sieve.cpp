//SEIVE OF ERATOSTENES

#include<bits/stdc++.h>

using namespace std;

void prime_sieve(int n)
{
    vector <int> prime(n+1,0);
    
    //marking the odd no.s as potential prime numbers and evens are never prime 
    for(int i=3;i<=n;i+=2)
    {
        prime[i] = 1;
    }
     
    //as we have already declared the multiples of 2 as not prime now we start with three
    for(int i=3;i<=n;i++)
    {
        //the current number if its is marked as prime
        if(prime[i] == 1)
        {
            //mark all multiples of i as not prime
            for(int j = i*i; j <= n ;j+=i)
                prime[j] = 0;
        }
    }

    prime[2] = 1;
    prime[0] = prime[1] = 0;

    for(int i=2;i<=n;i++)
    {
        if(prime[i] == 1)
        {
            cout << i << " " ; 
        }
    }

}


int main()
{
    int n;
    cin >> n;

    prime_sieve(n);

}