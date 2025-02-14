class ProductOfNumbers {
public:
    vector<int> p{1};
    int product=1;
    ProductOfNumbers() {
     
    }
    
    void add(int num) {
        if(num==0) p={1};
       else{
         p.push_back(num*p.back());
       };
        return;
    }
    
    int getProduct(int k) {
            int n = p.size();
        if(k>=n) return 0;
    
        //  product=1;
        return p.back()/p[n-k-1];
   
        
    }
};

/**
 * Your ProductOfNumbers object will be instanti ated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */