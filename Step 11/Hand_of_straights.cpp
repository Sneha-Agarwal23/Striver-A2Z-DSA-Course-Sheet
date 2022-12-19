class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        if(hand.size() % groupSize != 0)
            return false;
        unordered_map<int ,int> m;
        priority_queue<int , vector<int>, greater<int>> pq;
        for(int i = 0; i < hand.size(); i++)
        {
            m[hand[i]]++;
            
        }
        for(auto i : m)
        {
            pq.push(i.first);
        }
        while(!pq.empty())
        {
            int val = pq.top();
            for(int i = 0; i < groupSize; i++)
            {
                if(m.find(i+val) == m.end())
                    return false;
                m[i+val]--;
                if(m[i+val] == 0)
                {
                    if(i+val != pq.top())
                        return false;
                    pq.pop();
                }
                    
            }
        }
        return true;
    }
};