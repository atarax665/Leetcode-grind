class Solution {
    public boolean isValid(String str) {
        Stack<Character> st= new Stack<>();
     st.push('1')   ;
  st.push(str.charAt(0));
  
  
         for(int i=1;i<str.length();i++)
        {
          if(str.charAt(i)=='('|| str.charAt(i)=='{'||str.charAt(i)=='[')
          
           st.push(str.charAt(i));
          
          else
           
           {
            if (( st.peek() == '(' && str.charAt(i) == ')') || (st.peek ()== '{' && str.charAt(i) == '}') || (st.peek()== '[' && str.charAt(i) == ']'))
               st.pop();
               else 
                   return false;
           }
        }
        
        if(st.peek()=='1')
            return true;
        else
            return false;
}
}