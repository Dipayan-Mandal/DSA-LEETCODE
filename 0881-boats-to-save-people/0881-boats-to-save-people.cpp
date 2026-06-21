class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int lo=0;
        int hi=n-1;
        int count=0;
        while(lo<=hi)
        {
            if(people[lo]+people[hi]<=limit)
            {
                count++;
                lo++;
                hi--;
            }
            else 
            {
                count++;
                hi--;
            }
        }
        return count;
    }
};