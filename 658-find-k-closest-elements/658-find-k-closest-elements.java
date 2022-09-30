class Solution {
    class Comp implements Comparator<ArrayList<Integer>>
    {
        public int compare(ArrayList<Integer> a, ArrayList<Integer> b) {
        if(a.get(0) == b.get(0))
            return a.get(1) - b.get(1);
        return a.get(0) - b.get(0);
    }
}
    public List<Integer> findClosestElements(int[] arr, int k, int x) {

      ArrayList<ArrayList<Integer>> ll= new ArrayList<>();
      for(int i=0;i<arr.length;i++)
      {
          ArrayList<Integer> a = new ArrayList<>();
          a.add(Math.abs(arr[i]-x));
          a.add(arr[i]);
          ll.add(a);
      }
      Collections.sort(ll,new Comp());
        List<Integer> xx = new ArrayList<>();
        for(ArrayList<Integer> z : ll)
        {
            if(k > 0)
            {
                xx.add(z.get(1));
                k -= 1;
            }
        }
        Collections.sort(xx);  
        return xx;
    }
}