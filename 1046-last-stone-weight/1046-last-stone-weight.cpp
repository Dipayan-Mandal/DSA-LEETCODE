class Solution {
public:
    typedef pair<int,int> pi;
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x:stones)
        {
            pq.push(x);
        }
        while(pq.size()>1)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            if(x==y) pq.pop();
            else
            {
                pq.pop();
                pq.push(abs(y-x));
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};