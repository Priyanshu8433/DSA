class Solution {
    public int numberOfBeams(String[] bank) {
        int m=bank.length;
        int n=bank[0].length();
        int prev=0;
        int combination=0;
        for(int i=m-1; i>=0; i--){
            int curr=0;
            for(int j=0; j<n; j++){
                if(bank[i].charAt(j)=='1') curr++;
            }
            combination+=(curr*prev);
            if(curr>0)
                prev=curr;
        }
        return combination;
    }
}