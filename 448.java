
import java.util.*;
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        ArrayList<Integer> result = new ArrayList<>();
      int a,b,c;
        for(int i=0; i<nums.length; i++)
        { 
             c = 0;
            while(nums[i]!=i+1)
            {   
                  a=nums[i];
                 b=nums[nums[i]-1];
                if(a==b) break;
                nums[nums[i]-1]=a;
                nums[i]=b;
                  c++;
                  if(c==nums.length) break;
            }
            }
           
        
        for(int i=0; i<nums.length; i++){
            if(nums[i]!=i+1) {result.add(i+1);}
        }
        return result;
    }
}


// a good solution
public List<Integer> findDisappearedNumbers(int[] nums) {
List<Integer> res = new ArrayList<>();
int n = nums.length;
for (int i = 0; i < nums.length; i ++) nums[(nums[i]-1) % n] += n;
for (int i = 0; i < nums.length; i ++) if (nums[i] <= n) res.add(i+1);
return res;
}
