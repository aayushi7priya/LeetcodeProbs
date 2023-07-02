class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i =1;i<=n;i++)
        {
            q.push(i);
        }
        //1 2 3' 4 5 6 7 8
        //4 5 6' 7 8 1 2
        //7 8 1' 2 4 5
        //2 4 5' 1 7 8
        //1 7 8' 2 4
        // 2 4 1' 7
        //7 2 4'
        //2 7
        while(q.size()>1)
        {
            int i = 1;  //q modified
            while(i<k)
            {
                int x = q.front();
                q.pop();
                q.push(x);
                i++;
            }
            q.pop(); //popping the kth element
        }
        return q.front();
    }
};