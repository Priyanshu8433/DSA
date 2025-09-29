class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s;
        int collisions=0;

        for(int i=0; i<directions.length(); i++){
            char dir=directions[i];

            if(dir=='R'){
                s.push('R');
            }
            else if(dir=='L'){
                if(!s.empty() && s.top()=='R'){
                    collisions+=2;
                    s.pop();
                    while(!s.empty() && s.top()=='R'){
                        s.pop();
                        collisions+=1;
                    }
                    s.push('S');
                }
                else if(!s.empty() && s.top()=='S') collisions+=1;                
            }
            else{
                // dir is 'S'
                while(!s.empty() && s.top()=='R'){
                    s.pop();
                    collisions+=1;
                }
                s.push('S');
            }
        }

        return collisions;
    }
};