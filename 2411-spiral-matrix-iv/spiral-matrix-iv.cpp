/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> arr(n*m, -1);
        int i=0;
        while(head){
            arr[i++] = head->val;
            head = head->next; 
        }
        int j = 0;
        vector<vector<int>> res(m, vector<int>(n, 0));
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        while(left <= right && top <= bottom){
            for(int i=left;i<=right;i++){
                res[top][i] = arr[j++];
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res[i][right] = arr[j++];
            }
            right--;
            if(top <= bottom){
                for(int i=right;i>=left;i--){
                    res[bottom][i] = arr[j++];
                }
                bottom--;
            }
            if(left <= right){
                for(int i=bottom;i>=top;i--){
                    res[i][left] = arr[j++];
                }
                left++;
            }
        }
        return res;
    }
};