class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num==0) return true;
        int last = num%10;
        if(last==0) return false;
        return true;
    }
};