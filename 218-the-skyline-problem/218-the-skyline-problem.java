class Solution {
    public class pair{
        int point ;
        int hieght ;
        pair(int point,int hieght){
            this.point = point;
            this.hieght = hieght;
        }
    }
    
      
   class Sortbypoints implements Comparator<pair> {
    public int compare(pair a, pair b)
      {
        if(a.point == b.point){
          return a.hieght-b.hieght;
        }
        return a.point - b.point;
      }
   } 
    
   public List<List<Integer>> getSkyline(int[][] buildings) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int currh = 0;
        pq.add(0);
        ArrayList<pair> list = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        for(int i =0;i<buildings.length;i++){
            int x = buildings[i][0];
            int y = buildings[i][1];
            int h = buildings[i][2];
                     
            list.add(new pair(x,-h));
            list.add(new pair(y,h));
        }
        
      Collections.sort(list,new Sortbypoints());
      for(int i = 0;i < list.size();i++){
          pair a = list.get(i);
          int currp = a.point;
          int ch = a.hieght;
          
          if(ch < 0){
              pq.add(-ch);
          }else {
              pq.remove(ch);
          }
          
          if(currh != pq.peek()){
              List<Integer> smallans = new ArrayList<>();
              smallans.add(currp);
              smallans.add(pq.peek());
              ans.add(smallans);
              currh = pq.peek();
          }
      }       
        return ans;
    }
    
}