class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n=len(s)
        while(n>2):
            newStr=""
            for i in range(1,n):
                newDigit=(int(s[i])+int(s[i-1]))%10
                newStr+=str(newDigit)
            s=newStr
            n=len(s)
        print(s)
        return s[0]==s[1]