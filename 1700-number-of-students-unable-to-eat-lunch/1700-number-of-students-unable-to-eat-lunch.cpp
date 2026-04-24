class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int> q;
        int count=0;
        for(int i=0;i<n;i++)
        {
            q.push(students[i]);
        }
        int i=0;
        while(q.size()>0 && count!=q.size())
        {
            if(q.front()==sandwiches[i])
            {
                q.pop();
                count=0;
                i++;
            }
            else
            {
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};