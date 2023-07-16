#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class myGreat{
    public:
    bool operator()(pair<int, int> m1, pair<int, int> m2){
        return m1.first > m2.first;
    }
};
class Solution {
public:
    static int minimumIndex(vector<int>& nums) {
        //将值与其出现的次数存入map,找到出现次数最多的值，存入pair
        unordered_map<int,int> s;
        pair<int,int> maxcountNum{0,-1};
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) == s.end()){
                s[nums[i]] = 0;
            }
            s[nums[i]] = s[nums[i]]+1;
            if(maxcountNum.second < s[nums[i]]){
                maxcountNum = make_pair(nums[i],s[nums[i]]);
            }
        }
        //
        int pre_count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == maxcountNum.first){pre_count++;}
            int lst_count = maxcountNum.second - pre_count;

            if(pre_count*2 > i+1 && lst_count*2 > (nums.size()-i-1)){
                return i;
            }
        }
        return -1;
    }
    static int maximumBeauty(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        int i = 0,j=0,count = 0;
        while(j < nums.size()){
            while(j < nums.size()&&nums[j] - nums[i] <= 2*k) j++;
            count = max(count,j-i);
            i++;
        }
        return count;
    }
    int lengthOfLongestSubstring_0(string s) {
        int begin=0,end=0,result=0;
        set<char> stmp;
        while(end<s.size()){
            while(stmp.find(s[end]) == stmp.end() && end<s.size()){
                stmp.insert(s[end]);
                end++;
            }
            result = max(result,end-begin);
            char tmp = s[begin++];
            while(tmp != s[end]){
                stmp.erase(tmp);
                tmp = s[begin++];
            }
        }
        return result;
    }
    int lengthOfLongestSubstring_1(string s) {
        int begin=0,end=0,result=0;
        map<char,int> stmp;
        while(end<s.size()){
            while(stmp.find(s[end]) == stmp.end() && end<s.size()){
                stmp.insert(make_pair(s[end],end));
                end++;
            }
            result = max(result,end-begin);
            int btmp = begin;
            begin = stmp.find(s[end])->second+1;
            for(btmp;btmp<begin;btmp++){
                stmp.erase(s[btmp]);
            }
        }
        return result;
    }
    int maximumBeauty_1(vector<int>& nums, int k) {
        //会超时
        int maxval = *max_element(nums.begin(),nums.end())+k;
        int m_map[maxval+1];
        for(int i=0;i<maxval+1;i++) m_map[i] = 0;
        int max_result;
        for (int i = 0; i < nums.size(); i++) {
            int j_begin = (nums[i] < k) ? 0 : (nums[i] - k);
            for (int j = j_begin; j <= nums[i] + k; j++) {
                m_map[j] = m_map[j]+1;
                max_result = max(max_result,m_map[j]);
            }
        }
        return max_result;
    }
    int maximumBeauty_2(vector<int>& nums, int k) {
        //不会超时
        int maxval = *max_element(nums.begin(),nums.end())+k;
        int resultArray[maxval+1];
        int diffArray[maxval+1];
        for(int i=0;i<maxval+1;i++) {resultArray[i] = 0;diffArray[i]=0;}
        for (int i = 0; i < nums.size(); i++) {
            int j_begin = (nums[i] < k) ? 0 : (nums[i] - k);
            int j_end = (nums[i]+k+1);
            diffArray[j_begin] = diffArray[j_begin]+1;
            diffArray[j_end] = diffArray[j_end]-1;
        }
        resultArray[0] = diffArray[0];
        int max_result=0;
        for(int i = 1; i <maxval+1; i++) {
            resultArray[i] = resultArray[i-1]+diffArray[i];
            max_result = max(max_result,resultArray[i]);
        }
        return max_result;
    }
};

int main() {
//    vector<int> nums = {2,1,3,1,1,1,7,1,2,1};
//    vector<int> nums{1,2,2,2};
    vector<int> nums = {4,6,1,2};
//    vector<int> nums = {1,1,1,1};
    int k = 2;
    cout<<Solution::maximumBeauty(nums,k)<<endl;
//    cout<<Solution::minimumIndex(nums)<<endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
