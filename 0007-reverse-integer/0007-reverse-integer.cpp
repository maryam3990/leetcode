class Solution {
public:
    int reverse(int y) 
    {
        long long x = (long long) y;
        bool isNegative = false;
        if(x<0) {
            isNegative = true;
            x*=-1;
        }
        long long ans = 0;
        long long multiplier = 1;
        int count = 0;
        
        int temp = x;
        while(temp!=0)
        {
            multiplier *=10;
            temp/=10;
        }
        multiplier /=10;
        while(x!=0)
        {
            int digit = x % 10;
            ans += (digit*multiplier);
            multiplier/= 10;
            x/=10;
        }
        if(isNegative) ans*=-1;
        
        if(ans<INT_MIN || ans>INT_MAX) return 0;
        return (int)ans;
    }
};