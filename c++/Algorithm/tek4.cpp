#include <bits/stdc++.h>

using namespace std;

long long int giai_thua(int n)
{
    if ( n == 1 )
    {
        return 1;
    }
    else
    {
        return n * giai_thua(n - 1);
    }
}
int main()
{
    
    int k; cin >> k;
    int n; cin >> n;

    cout << giai_thua(n) / ( giai_thua(k) * giai_thua(n-k));

    return 0;
}