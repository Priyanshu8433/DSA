class Solution {
    int solve(vector<int> &v){
        int n=v.size();
        int cons=0;
        int sum=0;
        for(int i=0; i<n; i++){
            if(v[i]==0){
                cons=0;
            }
            else cons++;
            sum+=cons;
        }
        return sum;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int cnt=0;

        for(int sr=0; sr<m; sr++){
            for(int er=sr; er<m; er++){
                vector<int> temp(n);
                for(int k=0; k<n; k++){
                    int ele=1;
                    for(int j=sr; j<=er; j++){
                        ele=ele&mat[j][k];
                    }
                    temp[k]=ele;
                }
                cnt+=solve(temp);
            }
        }

        return cnt;
    }
};