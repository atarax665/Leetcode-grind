class Solution {
    public boolean isValid(String str) {
        Stack<Character> st= new Stack<>();
     st.push('1')   ;
  st.push(str.charAt(0));
  
  
         for(int i=1;i<str.length();i++)
        {
          if(str.charAt(i)=='(')
          
           st.push(str.charAt(i));
           else if(str.charAt(i)==')')
           {
            if(st.peek()=='(')
           st.pop();
           else
           st.push(str.charAt(i));}


           if(str.charAt(i)=='{')
           st.push(str.charAt(i));

           else if(str.charAt(i)=='}'){
           if(st.peek()=='{')
           st.pop();
           else 
           st.push(str.charAt(i));}

           
           if(str.charAt(i)=='[')
           st.push(str.charAt(i));

           else if(str.charAt(i)==']'){
           if(st.peek()=='[')
           st.pop();
           else
           st.push(str.charAt(i));}

        }
        
        if(st.peek()=='1')
            return true;
        else
            return false;
}
}