class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        
        unordered_set<int> s1;
        unordered_set<int> s2;
        
        for(int i=0; i<n; i++)
            s1.insert(nums1[i]);
        
        for(int i=0; i<m; i++)
            s2.insert(nums2[i]);
        
        int ans1=0;
        int ans2=0;
        for(int i=0; i<n; i++)
            if(s2.count(nums1[i]))
                ans1++;
        
        for(int i=0; i<m; i++)
            if(s1.count(nums2[i]))
                ans2++;
        
        
        return {ans1, ans2};
        
        
    }
};