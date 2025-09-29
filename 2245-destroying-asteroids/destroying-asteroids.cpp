class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n=asteroids.size();

        for(int i=0; i<n; i++){
            if((mass>=INT_MAX-asteroids[i]) || (mass>=asteroids[n-1])) return true;
            if(mass<asteroids[i]) return false;
            if(mass>=asteroids[n-1]-asteroids[i]) return true;
            if(mass>=asteroids[i]) mass+=asteroids[i];
        }
        return false;
    }
};