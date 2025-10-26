class Bank {
    vector<long long> Balance;
public:
    Bank(vector<long long>& balance) {
        Balance=balance;
    }
    
    bool enoughBalance(int account, long long amount){
        return Balance[account-1]>=amount;
    }
    bool validAccount(int account){
        if(account<1 || account>Balance.size()) return false;
        return true;
    }

    bool transfer(int account1, int account2, long long money) {
        if(!validAccount(account1) || !validAccount(account2)) return false;
        if(!enoughBalance(account1,money)) return false;
        Balance[account1-1]-=money;
        Balance[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!validAccount(account)) return false;
        Balance[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!validAccount(account)) return false;
        if(!enoughBalance(account, money)) return false;
        Balance[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */