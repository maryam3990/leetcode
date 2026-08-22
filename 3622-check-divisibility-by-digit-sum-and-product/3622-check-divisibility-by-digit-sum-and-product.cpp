class Solution {
public:
    bool checkDivisibility(int n) 
    {
        int digitProduct = 1;
        int digitSum = 0;

        int temp = n;

        while(temp!=0)
        {
            int digit = temp % 10;
            digitProduct*=digit;
            digitSum+=digit;
            temp/=10;
        }
        return n % (digitSum + digitProduct) == 0;
    }
};