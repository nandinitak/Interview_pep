class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
 
    }
    
    void add(int num) {
        nums.push_back(num);
        return;
    }
    
    int getProduct(int k) {
        int n = nums.size();
        int product=1;
        for(int i=n-1;i>n-k-1;i--){
            product=product*nums[i];

        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */