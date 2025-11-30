class Solution {
public:
    int helper(int amount, vector<int>& coins, int index){ // [1,2,5]
       if(amount == 0) return 1;
       if(amount < 0 || index >= coins.size()) return 0;

        int count = 0;
        count += helper(amount, coins, index+1);
        count += helper(amount - coins[index], coins, index);
        return count;
    }
    int change(int amount, vector<int>& coins) {
       return helper(amount, coins, 0); 
    }
};


/*


 amount = 5, coins = [1,2,5]




*/