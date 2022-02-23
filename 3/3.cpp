#include <math.h>
#include <string.h>
#include <omp.h>
#include <iostream>

using namespace std;


long Strike(bool composite[], long i, long stride, long limit)
{
    for (; i <= limit; i += stride)
        composite[i] = true;
    return i;
}

long CacheUnfriendlySieve(long n)
{
    long count = 0;
    long m = (long)sqrt((double)n);
    bool *composite = new bool[n + 1];
    memset(composite, 0, n);
    
    for (long i = 2; i <= m; ++i)
        if (!composite[i])
        {
            ++count;
            // Strike walks array ofsize n here.
            Strike(composite, 2 * i, i, n);
        }
    for (long i = m + 1; i <= n; ++i)
        if (!composite[i])
        {
        ++count;
        }
    
    return count;
}

long CacheFriendlySieve(long n){
    long count = 0;
    long m = (long)sqrt((double)n);
    bool* composite = new bool[n+1];
    memset( composite, 0, n );

    long* factor = new long[m];
    long* striker = new long[m];
    long n_factor = 0;

    

    for( long i=2; i<=m; ++i )

        if( !composite[i] ){
            ++count;
            striker[n_factor] = Strike( composite, 2*i, i, m );
            factor[n_factor++] = i;
        }

        // Chops sieve into windows of size ≈ sqrt(n)
        for( long window=m+1; window<=n; window+=m ){
            long limit = min(window+m-1,n);

            for( long k=0; k<n_factor; ++k ){
                // Strike walks window of size sqrt(n) here.
                striker[k] = Strike( composite, striker[k], factor[k],limit );
            }
           

            for( long i=window; i<=limit; ++i ){
                if( !composite[i] ){
                    ++count;
                }      
            }
        }

return count;
}

int main(){
    input :
    long n;
    cin >> n;
    cout << CacheUnfriendlySieve(n)<<endl;
    cout << CacheUnfriendlySieve(n)<<endl;
    goto input;
}
