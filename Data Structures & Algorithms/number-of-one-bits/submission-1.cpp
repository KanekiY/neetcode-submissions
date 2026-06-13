class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
        uint32_t compareNum=1;
        uint32_t totalBits = 0;
        for(int i=0; i<=31; i++)
        {
               totalBits += ((compareNum & n) != 0);
               compareNum<<=1;
        }
        return totalBits;*/
        uint32_t compareNum= 1;
        uint32_t totalBits = 0;
        while(n>0)
        {
            totalBits += n&compareNum;
            n>>=1;
        }
        return totalBits;
    }
};
