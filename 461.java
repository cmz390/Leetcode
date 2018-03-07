public class Solution {
    public int hammingDistance(int x, int y) {
        x=x^y;
        int counter=0;
        for(int i=0; i<64; i++)
        {
            if((x&1)==1) counter++;
            x=x>>1;
        }
        return counter;
    }
}