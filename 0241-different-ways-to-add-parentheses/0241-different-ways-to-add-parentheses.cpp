class Solution {
public:
    int compute(int a, int b, char op)
    {
        if(op=='+') return a + b;
        else if(op=='-') return a-b;
        else return a*b;
    }
    
    vector<int> diffWaysToCompute(string expression) {
       int n = expression.size();
        if(n==0)
            return {};
        vector<int>results;
        int isNumber = 1;
        for(int i =0;i<n;i++)
        {
            if(!isdigit(expression[i]))
            {
                isNumber = 0;
                vector<int>left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1, n-1));
                
                for(auto x: left )
                {
                    for(auto y: right)
                    {
                        results.push_back(compute(x,y, expression[i]));
                    }
                }
            }
        }
        if(isNumber == 1)
        {
            results.push_back(stoi(expression));
        }
        return results;
    }
};