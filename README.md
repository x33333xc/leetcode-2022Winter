# leetcode-2022Winter
2022寒假准备暑期实习leetcode刷题题记

想要找一份暑期实习，让我的简历有些东西可以写，为了能拿到一个暑期实习的offer，从现在开始刷题。

#### 1171. 从链表中删去总和值为零的连续节点

利用$map<preSum,Node>$**前缀和-结点** 记录所有前缀和（保留最靠后的），然后再次遍历并计算前缀和，删去冗余

```C++
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* virtualHead = new ListNode;
        virtualHead->next = head;
        ListNode* cur = virtualHead;
        map<int, ListNode*>mapPreSum;//<sum,Node>
        int preSum = 0;
        while (cur) {
            preSum += cur->val;
            mapPreSum[preSum] = cur;
            cur = cur->next;
        }
        //printMap(mapPreSum);
        cur = virtualHead;
        preSum = 0;
        while (cur) {
            preSum += cur->val;
            cur->next = mapPreSum[preSum]->next;
            cur = cur->next;
        }
        return virtualHead->next;
    }
};
```

