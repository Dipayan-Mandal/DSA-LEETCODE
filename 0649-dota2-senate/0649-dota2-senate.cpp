class Solution {
public:
    string predictPartyVictory(string arr) {
        queue<int> q;
        queue<int> r;
        queue<int> d;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            q.push(i);
            if(arr[i]=='R')
            r.push(i);
            else d.push(i);
        }
        while(r.size() && d.size())
        {
            if(arr[q.front()]=='R')
            {
                if(r.front()==q.front())
                {
                    arr[d.front()]='x';
                    d.pop();
                    q.push(q.front());
                    q.pop();
                    r.push(r.front());
                    r.pop();
                }
            }
            else if(arr[q.front()]=='x') q.pop();
            else if(arr[q.front()]=='D')
            {
                if(d.front()==q.front())
                {
                    arr[r.front()]='x';
                    r.pop();
                    q.push(q.front());
                    q.pop();
                    d.push(d.front());
                    d.pop();
                }
            }
        }
        if(r.size()!=0) return "Radiant";
        else return "Dire";
    }
};