class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n1=s.length();
        int n2= part.length();
        int j=n1;
        while(j>0){
        
          int a=  s.find(part);
          if (a < 0) break; 
          s.erase(s.begin()+a,s.begin()+a+n2);
          j--;

        }
        return s;

    }
};