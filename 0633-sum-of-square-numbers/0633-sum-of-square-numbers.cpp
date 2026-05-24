class Solution {
public:
    bool isPerfectSquare(int k)
    {
        int root=sqrt(k);
        if(root*root==k) return true;
        else return false;
    }
    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
        if(isPerfectSquare(x) && isPerfectSquare(y)) return true;
        else if(isPerfectSquare(x))
        {
            y=(int)sqrt(y)*(int)sqrt(y);
            x=c-y;
        }
         else
        {
            x=((int)sqrt(x)+1)*((int)sqrt(x)+1);
            y=c-x;
        }
        }
        return false;
    }
};