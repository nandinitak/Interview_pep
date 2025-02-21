class Solution {
public:
    bool isValid(string s) {
        int l = s.length();
        stack <char> st;
        for(int i=0;i<l;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.size()==0){
                    return false;
                }
                char a = s[i];
                char j = st.top();
                if((a==')'&&j=='(')||(a==']'&&j=='[')||(a=='}'&&j=='{')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
     }
};