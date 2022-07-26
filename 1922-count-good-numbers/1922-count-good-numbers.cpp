#define mod 1000000007
class Solution {
    private:
    long long power(long long x, long long y){
        if(y == 0){
            return 1;
        }
        long long ans = power(x,y/2);
        if(y % 2 == 0){       // if y is even
            return (ans*ans)%mod;
        }
        else{          // if y is odd
            return (((ans*ans)%mod)*x)%mod;
        }
    }
public:
    int countGoodNumbers(long long n) {
        long long even = (n/2)+(n%2); // no. of even index
        long long odd = n/2;          // no. of odd index 
        long long result = (power(5,even)*power(4,odd))%mod;
        return result;
    }
};