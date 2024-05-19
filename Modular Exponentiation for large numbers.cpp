class Solution
{
    public:
        long long int PowMod(long long int x,long long int n,long long int M)
        {
            if(n == 0) return 1;
            long long int mul =PowMod(x,n/2,M);
            if(n&1) return ((x*mul)%M)*mul%M;
            else return mul*mul%M;
        }
};